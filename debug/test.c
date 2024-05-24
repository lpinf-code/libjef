/*
** EPITECH PROJECT, 2024
** jef
** File description:
** debug/test.c
*/

#include "jef/json.h"
#include "jef/entity.h"
#include "jef/object.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("test.json", "r");
    fseek(fp, 0, SEEK_END); 
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET); 
    char *fcontent = calloc(size + 1, 1);
    fread(fcontent, 1, size, fp);
    fclose(fp);

    json_entity_t *my_json_data = json_unserialize(fcontent);

    json_object_t *object = NULL;
    json_entity_get(my_json_data, JSON_OBJECT, &object);

    json_entity_t *result = json_object_get(object, "image");

    if (result != NULL) {
        char *str = NULL;
        json_entity_get(result, JSON_STRING, &str);
        
        printf("%s\n", str);
    }
    json_entity_destroy(my_json_data);
    free(fcontent);
}
