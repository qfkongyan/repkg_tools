
bin_PROGRAMS=imgdiff

imgdiff_SOURCES= imgdiff.cpp utils.cpp bsdiff.cpp
top_srcdir=.
imgdiff_LDADD = $(top_srcdir)/../../../out/lib/libz.a \
				$(top_srcdir)/../../../out/lib/libbz.a

AM_CPPFLAGS = -I$(top_srcdir)/../../../external/bzip2 -I$(top_srcdir)/../../../external/zlib/

