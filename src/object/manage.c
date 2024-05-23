/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/object.c
*/

#include "jef/object.h"
#include "jef/array.h"
#include <stdlib.h>

/**
 * @brief Creates a new JSON object.
 *
 * This object is empty by default.
 *
 * @returns The object, or NULL on allocation error.
*/
json_object_t *json_object_new(void)
{
    json_object_t *object = malloc(sizeof(json_object_t));

    if (object == NULL)
        return NULL;
    object->root = NULL;
    return object;
}

static void free_node(struct json_object_entry_s *entry)
{
    if (entry == NULL)
        return;
    free_node(entry->less);
    free_node(entry->gteq);
    if (entry->value.type == JSON_STRING && entry->value.dynamic_value)
        free(entry->value.content.string);
    if (entry->value.type == JSON_OBJECT && entry->value.dynamic_value)
        json_object_destroy(entry->value.content.object);
    if (entry->value.type == JSON_ARRAY && entry->value.dynamic_value)
        json_array_destroy(entry->value.content.array);
    if (entry->value.dynamic_key)
        free(entry->key);
    free(entry);
}

/**
 * @brief Destroys a JSON object.
 *
 * @param object The object to destroy.
*/
void json_object_destroy(json_object_t *object)
{
    free_node(object->root);
    free(object);
}
