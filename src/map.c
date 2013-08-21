/**
  * libdyldcache-1.0 - map.c
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
#include <stdlib.h>
#include <string.h>

#define _DEBUG
#include <libcrippy-1.0/debug.h>
#include <libcrippy-1.0/libcrippy.h>
#include <libcrippy-1.0/boolean.h>
#include <libdyldcache-1.0/map.h>

dyldmap_t* dyldmap_create() {
	debug("Creating dyldmap\n");
	dyldmap_t* map = (dyldmap_t*) malloc(sizeof(dyldmap_t));
	if(map) {
		memset(map, '\0', sizeof(dyldmap_t));
	}
	return map;
}

dyldmap_t* dyldmap_parse(unsigned char* data, uint32_t offset) {
	debug("Parsing dyldmap\n");
	dyldmap_t* map = dyldmap_create();
	if (map) {
		map->info = dyldmap_info_parse(data, offset);
		if(map->info == NULL) {
			error("Unable to allocate data for dyld map info\n");
			return NULL;
		}
		map->address = map->info->address;
		map->size = map->info->size;
		map->offset = map->info->offset;
		dyldmap_debug(map);
	}
	return map;
}

boolean_t dyldmap_contains(dyldmap_t* map, uint64_t address) {
	debug("Seeing if dyldmap contains address\n");
	if(address >= map->address &&
			address < (map->address + map->size)) {
		return kTrue;
	}
	return kFalse;
}

void dyldmap_free(dyldmap_t* map) {
	debug("Freeing dyldmap\n");
	if(map) {
		if (map->info) {
			dyldmap_info_free(map->info);
		}
		free(map);
	}
}


void dyldmap_debug(dyldmap_t* map) {
	if(map) {
		debug("\tMap:\n");
		if(map->info) {
			dyldmap_info_debug(map->info);
		}
		debug("\t\n");
	}
}

/*
 * Dyldcache Map Info Functions
 */
dyldmap_info_t* dyldmap_info_create() {
	debug("Creating dyldmap info\n");
	dyldmap_info_t* info = (dyldmap_info_t*) malloc(sizeof(dyldmap_info_t));
	if(info) {
		memset(info, '\0', sizeof(dyldmap_info_t));
	}
	return info;
}

dyldmap_info_t* dyldmap_info_parse(unsigned char* data, uint32_t offset) {
	debug("Parsing dyldmap info\n");
	dyldmap_info_t* info = dyldmap_info_create();
	if(info) {
		memcpy(info, &data[offset], sizeof(dyldmap_info_t));
	}
	return info;
}

void dyldmap_info_debug(dyldmap_info_t* info) {
	if(info) {
		debug("\t\tInfo {\n");
		debug("\t\t\t address = 0x%08x\n", (uint32_t)info->address);
		debug("\t\t\t    size = 0x%08x\n", (uint32_t)info->size);
		debug("\t\t\t  offset = 0x%08x\n", (uint32_t)info->offset);
		debug("\t\t\t maxProt = %s\n", prot2str(info->maxProt));
		debug("\t\t\tinitProt = %s\n", prot2str(info->initProt));
		debug("\t\t}\n");
	}
}

void dyldmap_info_free(dyldmap_info_t* info) {
	debug("Freeing dyldmap info\n");
	if(info) {
		free(info);
	}
}
