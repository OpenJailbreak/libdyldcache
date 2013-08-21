/**
  * libdyldcache-1.0 - decache.h
  * Copyright (C) 2013 Crippy-Dev Team
  * Copyright (C) 2010-2013 Joshua Hill
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include <stdio.h>

#include <libdyldcache-1.0/libdyldcache.h>

int main(int argc, char* argv[]) {
	char* dyldcache = NULL;
	dyldcache_t* cache = NULL;

	if(argc != 2) {
		printf("usage: ./dbgcache <dyldcache>\n");
		return -1;
	}
	dyldcache = strdup(argv[1]);

	cache = dyldcache_open(dyldcache);
	if(cache) {
		//dyldcache_debug(cache);
		dyldcache_free(cache);
	}

	free(dyldcache);
	return 0;
}
