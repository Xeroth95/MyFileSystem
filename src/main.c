/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*-  */

/*
 * main.c
 * Copyright (C) 2014 Xeroth95 <shillah@hotmail.de>
 * 
 * MyFileSystem is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * MyFileSystem is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/***************************************************************************
 *            main.c
 *
 *  Fr Februar 07 15:22:54 2014
 *  Copyright  2014  Xeroth95
 *  <user@domain.org>
 ****************************************************************************/

#define INIT_BLOCKCOUNT 200
#define TEST_CASE "Debug/test_file"

#include <stdio.h>

typedef unsigned long size_t;

int create_fs( char *name, size_t blocksize );

int main( int argc, char **argv )
{
	create_fs( "test", 512 );
	return 0;
}

int create_fs( char *name, size_t blocksize )
{
	FILE *fs = fopen( name, "r" );
	if (fs != NULL) {
		fclose(fs);
		return -1;
	}
	
	fs = fopen( name, "w+" );
	unsigned char arr[INIT_BLOCKCOUNT * blocksize];
	fwrite( arr, blocksize, INIT_BLOCKCOUNT, fs );
	fclose( fs );
	
	return 0;
}