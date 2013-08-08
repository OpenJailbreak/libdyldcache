AM_CFLAGS = $(libcrippy_CFLAGS) $(libmacho_CFLAGS) -I$(top_srcdir)/include
AM_LDFLAGS = $(libcrippy_LIBS) $(libmacho_LIBS)

lib_LTLIBRARIES = libdyldcache-1.0.la
libdyldcache_1_0_la_CFLAGS = $(AM_CFLAGS)
libdyldcache_1_0_la_LDFLAGS = $(AM_LDFLAGS)
libdyldcache_1_0_la_SOURCES = \
								map.c \
								image.c \
								cache.c