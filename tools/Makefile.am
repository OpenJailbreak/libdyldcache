AM_CFLAGS = $(libcrippy_CFLAGS) $(libmacho_CFLAGS) -I$(top_srcdir)/include
AM_LDFLAGS = $(libcrippy_LIBS) $(libmacho_LIBS)

bin_PROGRAMS = decache dyldrop

decache_SOURCES = decache.c
decache_CFLAGS = $(AM_CFLAGS)
decache_LDFLAGS = $(AM_LDFLAGS)
decache_LDADD = $(top_srcdir)/src/libdyldcache-1.0.la

dyldrop_SOURCES = dyldrop.c
dyldrop_CFLAGS = $(AM_CFLAGS)
dyldrop_LDFLAGS = $(AM_LDFLAGS)
dyldrop_LDADD = $(top_srcdir)/src/libdyldcache-1.0.la