/*
 * Ext2read
 * File: main.c
 */
/*
 * Copyright (C) 2005 by Manish Regmi   (regmi dot manish at gmail.com)
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
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>

#include "ext4copyfile.h"
#include "ext4read.h"
#include "platform.h"
#include "partition.h"

static void usage(char *path)
{
	fprintf(stderr, "%s -i [ ext4Image ] -o [ outputDir ]\n", basename(path));
	fprintf(stderr, "    [ -i <input file, It's a ext4 Image> ]\n");
	fprintf(stderr, "    [ -o <output dir, extract to this dir> \n");
}

int main(int argc, char *argv[])
{
	int opt = 0;
    Ext4Read app;
    Ext4CopyFile copyfile;
    Ext4File* root = NULL;
	char *ext4Image = NULL;
	char *outputDir = NULL;

	while ((opt = getopt(argc, argv, "i:o:n")) != EOF) {

		switch (opt) {
		case 'i':
			ext4Image = optarg;
			break;
		case 'o':

			outputDir = optarg;
			break;
		default: /* '?' */
			usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	if( argc < 2){
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

    root = app.add_loopback(ext4Image);

    copyfile.set_file(root);
    copyfile.set_name(outputDir);
    copyfile.start_copy();

    return 0;
}
