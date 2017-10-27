AUTOMAKE_OPTIONS = subdir-objects
lib_LTLIBRARIES         = liblog.la

liblog_la_SOURCES = \
	fake_log_device.c \
	logger_write.c \
	config_write.c \
	logger_lock.c \
	fake_writer.c \
	logger_name.c

top_srcdir=.
AM_CPPFLAGS		= -I$(top_srcdir)/../include -I$(top_srcdir)/../../../bionic/libc/include -lpthread -DLIBLOG_LOG_TAG=1005 -DFAKE_LOG_DEVICE=1

