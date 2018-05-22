/**
 * Copyright (C) 2010 by Manish Regmi   (regmi dot manish at gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 **/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#include "ext4copyfile.h"

Ext4CopyFile::Ext4CopyFile(Ext4File *parent, char *dest)
{
    filename = dest;
    file = parent;
    Ext4CopyFile();
}

Ext4CopyFile::Ext4CopyFile()
{

}

Ext4CopyFile::~Ext4CopyFile()
{
}

void Ext4CopyFile::start_copy()
{
    if(!EXT4_S_ISREG(file->inode.i_mode) &&
       !EXT4_S_ISDIR(file->inode.i_mode))
        return ;

    proc = new Ext4CopyProcess(file, filename);
    proc->run();
	delete proc;
}


Ext4CopyProcess::Ext4CopyProcess(Ext4File *parent, char *dest)
{
    filename = dest;
    file = parent;
    blksize = parent->partition->get_blocksize();
}

Ext4CopyProcess::~Ext4CopyProcess()
{
}

void Ext4CopyProcess::run()
{
    if(EXT4_S_ISDIR(file->inode.i_mode))
    {
        copy_folder(filename, file);
        return ;
    }
    else if(!EXT4_S_ISREG(file->inode.i_mode))
        return ;

    copy_file(filename, file);
}

bool Ext4CopyProcess::copy_file(char *destfile, Ext4File *srcfile)
{
    lloff_t blocks = 0, blkindex = 0;
    int extra = 0;
    int ret = 0;
	int fd = 0;
    char *buffer = new char[blksize];

	if(!destfile || !srcfile)
	{
		fprintf(stderr,"#####%s:%s:%d  path:%p parent:%p\r\n",__FILE__,__FUNCTION__,__LINE__, destfile, srcfile);
		return false;
	}

    fd = open(destfile,O_RDWR |O_CREAT | O_TRUNC,(srcfile->inode.i_mode)&(EXT4_S_IRUSR|EXT4_S_IWUSR|EXT4_S_IXUSR|EXT4_S_IRGRP|EXT4_S_IWGRP|EXT4_S_IXGRP|EXT4_S_IROTH|EXT4_S_IWOTH|EXT4_S_IXOTH));
    if(fd < 0)
    {
        fprintf(stderr,"#####%s:%s:%d destfile:%s  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,destfile,strerror(errno));
		delete [] buffer;
        return false;
    }

    blocks = srcfile->file_size / blksize;
    for(blkindex = 0; blkindex < blocks; blkindex++)
    {
        ret = srcfile->partition->read_data_block(&srcfile->inode, blkindex, buffer);
        if(ret < 0)
        {
            close(fd);
            delete [] buffer;
            return false;
        }

        ret = write(fd,buffer, blksize);
		if(ret < 0)
        {
            fprintf(stderr,"#####%s:%s:%d destfile:%s  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,destfile,strerror(errno));
		    delete [] buffer;
            return false;
        }
    }

    extra = srcfile->file_size % blksize;
    if(extra)
    {
        ret = srcfile->partition->read_data_block(&srcfile->inode, blkindex, buffer);
        if(ret < 0)
        {
            close(fd);
            delete [] buffer;
            return false;
        }

        ret = write(fd,buffer, extra);
		if(ret < 0)
        {
            fprintf(stderr,"#####%s:%s:%d destfile:%s  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,destfile,strerror(errno));
		    delete [] buffer;
            return false;
        }
    }
    close(fd);
    delete [] buffer;
    return true;
}

bool Ext4CopyProcess::copy_symlink(char *destfile, Ext4File *srcfile)
{
    int ret = 0;
    char link_to[2048] = { 0 };

	if(!destfile || !srcfile)
	{
		fprintf(stderr,"#####%s:%s:%d  path:%p parent:%p\r\n",__FILE__,__FUNCTION__,__LINE__, destfile, srcfile);
		return false;
	}

	strcat(destfile,srcfile->file_name.c_str());
//	fprintf(stderr,"#####%s:%s:%d  i_flags:0x%x i_mode:0x%x i_size:%d\r\n",__FILE__,__FUNCTION__,__LINE__, srcfile->inode.i_flags, srcfile->inode.i_mode& 0xf000,srcfile->inode.i_size);
	if ((srcfile->inode.i_flags & 0x10000000) || ((0xa000 == (srcfile->inode.i_mode & 0xf000)) && (srcfile->inode.i_size <= 60)))
	{
	    sprintf(link_to,"%s",(char*)(srcfile->inode.i_block));
	}else {
		/***** TODO:  you must read extent data *****/
		char *p = NULL;
		fprintf(stderr,"#####%s:%s:%d  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,strerror(errno));
		*p = 2;
	}
//    fprintf(stderr,"#####%s:%s:%d  link:%s link_to:%s \r\n",__FILE__,__FUNCTION__,__LINE__, destfile, link_to);

	ret = symlink(link_to,destfile);
	if(ret < 0)
	{
		fprintf(stderr,"#####%s:%s:%d  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,strerror(errno));
	}

    return true;
}

bool Ext4CopyProcess::copy_folder(char *path, Ext4File *parent)
{
    EXT4DIRENT *dirent = NULL;
    Ext4Partition *part = NULL;
    Ext4File *child = NULL;
    bool ret = 0;
    char filetosave[1024] = { 0 };
    char dirmk[1024] = { 0 };
    char* rootname = path;

	if(!path || !parent)
	{
		fprintf(stderr,"#####%s:%s:%d  path:%p parent:%p\r\n",__FILE__,__FUNCTION__,__LINE__, path, parent);
		return false;
	}

    if(!EXT4_S_ISDIR(parent->inode.i_mode))
        return false;

	part = parent->partition;
    sprintf(dirmk,"%s/%s",path,parent->file_name.c_str());
    mkdir(dirmk,(parent->inode.i_mode)&(EXT4_S_IRUSR|EXT4_S_IWUSR|EXT4_S_IXUSR|EXT4_S_IRGRP|EXT4_S_IWGRP|EXT4_S_IXGRP|EXT4_S_IROTH|EXT4_S_IWOTH|EXT4_S_IXOTH));

    dirent = part->open_dir(parent);
    while((child = part->read_dir(dirent)) != NULL)
    {
        memset(filetosave,0,sizeof(filetosave));
        memcpy(filetosave,rootname,strlen(rootname));
        strcat(filetosave,"/");
        strcat(filetosave,parent->file_name.c_str());
        if(EXT4_S_ISDIR(child->inode.i_mode))
        {
            ret = copy_folder(filetosave, child);
            if(ret == false)
            {
                part->close_dir(dirent);
                return false;
            }
            continue;
        }
        else if(EXT4_FT_ISLINK(child->file_type))
        {
            strcat(filetosave,"/");
            copy_symlink(filetosave,child);
            continue;

        }

        strcat(filetosave,"/");
        strcat(filetosave,child->file_name.c_str());
        ret = copy_file(filetosave, child);
        if((ret == false))
        {
            part->close_dir(dirent);
            return false;
        }
    }
    return true;
}

