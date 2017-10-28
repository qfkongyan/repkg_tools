
bin_PROGRAMS= mkbootimg unpackbootimg

top_srcdir=.
AM_CPPFLAGS             = -I$(top_srcdir)/../include 

mkbootimg_SOURCES= mkbootimg.c 
mkbootimg_LDADD = $(top_srcdir)/../../../out/lib/libmincrypt.a

unpackbootimg_SOURCES= unpackbootimg.c


