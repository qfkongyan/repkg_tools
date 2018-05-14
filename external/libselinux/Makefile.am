AUTOMAKE_OPTIONS = subdir-objects
lib_LTLIBRARIES         = libselinux.la                                   # Build and install an iperf

libselinux_la_SOURCES = \
	./src/callbacks.c \
	./src/check_context.c \
	./src/freecon.c \
	./src/init.c \
	./src/label.c \
	./src/label_file.c \
	./src/label_support.c \
	./src/matchpathcon.c \
	./src/setrans_client.c \
	./src/sha1.c \
	./src/lgetfilecon.c \
	./src/lsetfilecon.c \
	./src/regex.c \
	./src/label_backends_android.c \
	./src/canonicalize_context.c

top_srcdir=.
AM_CPPFLAGS		= -I$(top_srcdir)/include
AM_CPPFLAGS		+= -I$(top_srcdir)/../pcre/include/
AM_CPPFLAGS		+= -DANDROID \
    -DNO_PERSISTENTLY_STORED_PATTERNS \
    -DDISABLE_SETRANS \
    -DDISABLE_BOOL \
    -D_GNU_SOURCE \
    -DNO_MEDIA_BACKEND \
    -DNO_X_BACKEND \
    -DNO_DB_BACKEND \
    -DBUILD_HOST \
    -DUSE_PCRE2