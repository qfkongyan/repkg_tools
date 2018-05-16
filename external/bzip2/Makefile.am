
lib_LTLIBRARIES=libbz.la

libbz_la_SOURCES= \
      blocksort.c  \
      huffman.c    \
      crctable.c   \
      randtable.c  \
      compress.c   \
      decompress.c \
      bzlib.c

bin_PROGRAMS=bzip2
bzip2_SOURCES=bzip2.c
bzip2_LDADD=libbz.la

