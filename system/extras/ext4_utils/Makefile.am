
bin_PROGRAMS= make_ext4fs ext2simg

ext4fs_source= \
    make_ext4fs.c \
    ext4_utils.c \
    allocate.c \
    contents.c \
    extent.c \
    indirect.c \
    sha1.c \
    wipe.c \
    crc16.c \
    ext4_sb.c

top_srcdir=.
AM_CPPFLAGS = -I$(top_srcdir)/../../../external/libselinux/include/ \
	      -I$(top_srcdir)/../../core/include/ \
	      -I$(top_srcdir)/./include/ \
	      -I$(top_srcdir)/../../core/libsparse/include/ 

AM_CPPFLAGS+= -Doff64_t=off_t \
	      -Dlseek64=lseek \
	      -Dmmap64=mmap \
	      -Dftruncate64=ftruncate \
	      -DANDROID \
	      -DHOST


make_ext4fs_SOURCES= make_ext4fs_main.c \
	$(ext4fs_source)

make_ext4fs_LDADD = $(top_srcdir)/../../../out/lib/libmincrypt.a \
		    $(top_srcdir)/../../../out/lib/libselinux.a \
		    $(top_srcdir)/../../../out/lib/libcutils.a \
		    $(top_srcdir)/../../../out/lib/libsparse.a \
		    $(top_srcdir)/../../../out/lib/libpcre2-8.a \
		    $(top_srcdir)/../../../out/lib/liblog.a \
		    $(top_srcdir)/../../../out/lib/libz.a


ext2simg_SOURCES= make_ext4fs_main.c \
        $(ext4fs_source)
ext2simg_LDADD = $(top_srcdir)/../../../out/lib/libmincrypt.a \
		 $(top_srcdir)/../../../out/lib/libselinux.a \
		 $(top_srcdir)/../../../out/lib/libcutils.a \
		 $(top_srcdir)/../../../out/lib/libsparse.a \
		 $(top_srcdir)/../../../out/lib/libpcre2-8.a \
		 $(top_srcdir)/../../../out/lib/liblog.a \
		 $(top_srcdir)/../../../out/lib/libz.a
