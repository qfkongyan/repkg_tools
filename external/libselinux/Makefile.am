AUTOMAKE_OPTIONS = subdir-objects
lib_LTLIBRARIES         = libselinux.la                                   # Build and install an iperf

libselinux_la_SOURCES = \
	./src/callbacks.c \
	./src/check_context.c \
	./src/freecon.c \
	./src/init.c \
	./src/label.c \
	./src/label_file.c \
	./src/label_android_property.c \
	./src/label_support.c
	
top_srcdir=.
AM_CPPFLAGS		= -I$(top_srcdir)/include
AM_CPPFLAGS		+= -I$(top_srcdir)/../pcre
