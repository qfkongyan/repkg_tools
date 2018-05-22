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

#ifndef EXT4COPYFILE_H
#define EXT4COPYFILE_H
#include "ext4read.h"

class Ext4CopyProcess
{
private:
    char * filename;
    Ext4File *file;
    char *buffer;
    int blksize;

    bool copy_folder(char *path, Ext4File *file);
    bool copy_file(char *destfile, Ext4File *srcfile);
    bool copy_symlink(char *destfile, Ext4File *srcfile);

public:
    Ext4CopyProcess(Ext4File *parent, char *dest);
    ~Ext4CopyProcess();

    void run();

};

class Ext4CopyFile
{
    char * filename;
    Ext4File *file;
    Ext4CopyProcess *proc;

public:
    Ext4CopyFile(Ext4File *parent, char *dest);
    Ext4CopyFile();
    ~Ext4CopyFile();
    void set_file(Ext4File *sfile) { file = sfile; }
    void set_name(char *name) { filename = name; }
    void start_copy();

};

#endif // EXT4COPYFILE_H
