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

#ifdef __unix__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "platform.h"
#include <string.h>


FileHandle open_disk(const char *path, int *sect_size)
{
	int fd = 0;

	if(!path || !sect_size)
	{
		fprintf(stderr,"#####%s:%s:%d  path:%p sect_size:%p\r\n",__FILE__,__FUNCTION__,__LINE__,path,sect_size);
		return -1;
	}

	fd = open(path,O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr,"#####%s:%s:%d  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,strerror(errno));
		return -1;
	}
	*sect_size = SECTOR_SIZE;

	return fd;
}

int get_ndisks()
{

    return 0;
}

void close_disk(FileHandle handle)
{
    close(handle);
}

int read_disk(FileHandle handle, void *ptr, lloff_t sector, int nsects, int sectorsize)
{
    lloff_t offset;
	int ret = 0;
	int len = 0;

	if(!ptr)
	{
		fprintf(stderr,"#####%s:%s:%d  path:%p \r\n",__FILE__,__FUNCTION__,__LINE__,ptr);
		return -1;
	}

	offset = sector * sectorsize;

    len = nsects * sectorsize;
    lseek(handle, offset, SEEK_SET);
    ret = read(handle,ptr,len);
    if (ret < 0)
    {
		fprintf(stderr,"#####%s:%s:%d  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,strerror(errno));
        return -1;
    }

   return ret;
}


int write_disk(FileHandle handle, void *ptr, lloff_t sector, int nsects, int sectorsize)
{
    lloff_t offset;
	int ret = 0;
	int len = 0;

	if(!ptr)
	{
		fprintf(stderr,"#####%s:%s:%d  path:%p \r\n",__FILE__,__FUNCTION__,__LINE__,ptr);
		return -1;
	}

	offset = sector * sectorsize;

    len = nsects * sectorsize;
    lseek(handle, offset, SEEK_SET);
    ret = write(handle,ptr,len);
    if (ret < 0)
    {
		fprintf(stderr,"#####%s:%s:%d  (%s)\r\n",__FILE__,__FUNCTION__,__LINE__,strerror(errno));
        return -1;
    }

   return ret;
}

int get_nthdevice(char *path, int ndisks)
{
    return 0;
}

#endif
