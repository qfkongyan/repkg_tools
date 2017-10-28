lib_LTLIBRARIES         = libsparse.la

libsparse_la_SOURCES= \
	backed_block.c \
	output_file.c \
	sparse.c \
	sparse_crc32.c \
	sparse_err.c \
	sparse_read.c

top_srcdir=.
AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_srcdir)/../../../external/zlib/

AM_CPPFLAGS+= -Doff64_t=off_t \
	      -Dlseek64=lseek \
	      -Dmmap64=mmap \
	      -Dftruncate64=ftruncate 

bin_PROGRAMS= simg2img simg2simg img2simg append2simg
simg2img_SOURCES= simg2img.c 
simg2img_LDADD=libsparse.la \
			$(top_srcdir)/../../../out/lib/libz.a

simg2simg_SOURCES= simg2simg.c
simg2simg_LDADD=libsparse.la \
			$(top_srcdir)/../../../out/lib/libz.a

img2simg_SOURCES= img2simg.c
img2simg_LDADD=libsparse.la \
			$(top_srcdir)/../../../out/lib/libz.a

append2simg_SOURCES= append2simg.c
append2simg_LDADD=libsparse.la \
			$(top_srcdir)/../../../out/lib/libz.a
