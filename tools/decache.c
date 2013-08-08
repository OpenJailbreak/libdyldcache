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

#include <libdyldcache-1.0/cache.h>
#include <libdyldcache-1.0/image.h>

int main(int argc, char* argv[]) {
	int err = 0;
	char* cache = NULL; // The path the dyldcache
	char* dylib = NULL; // The name of the dylib to extract
	dyldcache_t* dyldcache = NULL; // Handle to dyld cache
	dyldimage_t* dyldimage = NULL; // Handle to dyld image

	if(argc == 2) {
		// We need to free this when we're done with it
		cache = strdup(argv[1]);

	} else if(argc == 3) {
		// We need to free this when we're done with it
		dylib = strdup(argv[2]);

	} else {
		printf("usage: ./decache <dyldcache>\n");
		printf("       ./decache <dyldcache> <dylib>\n");
		return -1;
	}

	// Make sure cache was specified on the command line
	if(cache != NULL) {
		// Cache was specified on the command line
		//  so let's try openning it
		dyldcache_t* dyldcache = dyldcache_open(cache);
		if(dyldcache != NULL) {
			// Cache was successfully opened
			//  did they specify which dylib they wanted also?
			if(dylib != NULL) {
				// Dylib was specified on the command line
				//  so only extract it
				dyldimage = dyldcache_get_image(dyldcache, dylib);
				if(dyldimage != NULL) {
					// We've successfully found the dylib
					//  Let's write it to disk
					dyldimage_save(dyldimage, dylib);
					// dyldimage is freed when dyldcache is
					//  this might not be very safe if used incorrectly...

				} else {
					// Error locating the dylib in the provided cache
					//  are you sure the filename was correct?
					printf("Unable to find dylib in dyldcache\n");
					err = -1;
				}

				// Don't need the dylib string anymore
				free(dylib);

			} else {
				// No dylib was specified on the command line
				//  so extract all dylibs
				for(dyldimage = dyldcache_first_image(dyldcache);
					dyldimage != NULL;
					dyldimage = dyldcache_next_image(dyldcache, dyldimage)) {
						// Save each image
						dyldimage_save(dyldimage, dyldimage_get_name(dyldimage));
				}
			}

			// Don't need this the handle to dyldcache anymore
			//  This also frees dyldimage if it exists
			dyldcache_free(dyldcache);

		} else {
			// We were unable to open the dyldcache
			//  Is the path correct? Has the format changed?
			printf("Unable to open dyldcache\n");
			err = -1;
		}

		// We don't need the cache string anymore
		free(cache);
	}

	return err;
}
