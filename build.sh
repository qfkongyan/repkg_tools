#!/bin/bash

#aclocal
#autoheader
#autoreconf -ivf
#
#libtoolize --version
#libtoolize --automake --copy --debug --force
#
#automake --add-missing
#automake
#
#./configure  --prefix=$1
#
#make
conf_path=$PWD/out/
echo $conf_path

function gen_configure()
{
    echo "===== enter $PWD ======================="
	aclocal
	autoheader
	autoreconf -ivf

	libtoolize --version
	libtoolize --automake --copy --debug --force >& /dev/null

	automake --add-missing
	automake

	./configure  --prefix=$conf_path
	echo "===== exit $PWD ======================="
}

scan_dir=$1
tmp_rst=/tmp/1.txt

function find_mk( )
{
    find $scan_dir -name Makefile.am > $tmp_rst
    while read LINE
    do
        path_dir=`dirname $LINE`
#	echo $path_dir
		cd $path_dir;
		if [ ! -f "Makefile" ];then
			gen_configure ;
		fi
		cd -
    done < $tmp_rst
}

find_mk
make install
