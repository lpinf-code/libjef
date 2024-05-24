/*
** EPITECH PROJECT, 2024
** jef
** File description:
** debug/test.c
*/

#include "jef/json.h"
#include "jef/entity.h"
#include "jef/object.h"
#include "jef/array.h"
#include <stdio.h>
#include <stdlib.h>

static char *readfile(const char *path)
{
    FILE *fp = fopen(path, "r");
    long size = 0;
    char *fcontent = NULL;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fcontent = calloc(size + 1, 1);
    fread(fcontent, 1, size, fp);
    fclose(fp);
    return fcontent;
}

bool *get_tile_collisions(void)
{
    char *fcontent = readfile("test.json");
    json_entity_t *data = json_unserialize(fcontent);
    json_entity_t *tiles = json_entobj_get(data, "tiles");
    json_array_t *tilearray = json_entity_get_array(tiles);
    json_entity_t *tmp;
    bool *collisions = NULL;

    if (tilearray == NULL)
        return NULL;
    collisions = calloc(tilearray->length, sizeof(bool));
    for (size_t i = 0; i < tilearray->length; i++) {
        tmp = tilearray->content[i];
        tmp = json_entobj_get(tmp, "properties");
        tmp = json_entarr_get(tmp, 0);
        tmp = json_entobj_get(tmp, "value");
        collisions[i] = json_entity_get_boolean(tmp);
    }
    json_entity_destroy(data);
    free(fcontent);
    return collisions;
}
