/**
 * FreeRDP: A Remote Desktop Protocol Client
 * Configuration Registry
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __REGISTRY_H
#define __REGISTRY_H

typedef struct rdp_registry rdpRegistry;

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <freerdp/freerdp.h>
#include <freerdp/settings.h>
#include <freerdp/utils/memory.h>

enum REG_TYPE
{
	REG_TYPE_NONE,
	REG_TYPE_STRING,
	REG_TYPE_INTEGER,
	REG_TYPE_BOOLEAN,
	REG_TYPE_SECTION
};

typedef struct
{
	uint8 type;
	uint8* name;
	uint32 length;
	void* value;
} REG_ENTRY;

typedef REG_ENTRY REG_STRING;
typedef REG_ENTRY REG_INTEGER;
typedef REG_ENTRY REG_BOOLEAN;
typedef REG_ENTRY REG_SECTION;

struct rdp_registry
{
	FILE* fp;
	uint8* path;
	uint8* file;
	uint8* home;
	boolean available;
	struct rdp_settings* settings;
};

void registry_open(rdpRegistry* registry);
void registry_close(rdpRegistry* registry);

void registry_init(rdpRegistry* registry);
rdpRegistry* registry_new(rdpSettings* settings);
void registry_free(rdpRegistry* registry);

#endif /* __REGISTRY_H */
