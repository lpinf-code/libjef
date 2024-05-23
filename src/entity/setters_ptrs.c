/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/entity/setters_ptrs.c
*/

#include "jef/entity.h"
#include <stdlib.h>

/**
 * @brief Setter for an entity object.
 *
 * Stores an object in an entity.
 *
 * @param entity The entity to set.
 * @param object The object to store.
*/
int json_entity_set_object(json_entity_t *entity, json_object_t *object)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_OBJECT;
    entity->content.object = object;
    entity->dynamic_value = true;
    return 0;
}

/**
 * @brief Setter for an entity array.
 *
 * Stores an array in an entity.
 *
 * @param entity The entity to set.
 * @param array The array to store.
*/
int json_entity_set_array(json_entity_t *entity, json_array_t *array)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_ARRAY;
    entity->content.array = array;
    entity->dynamic_value = true;
    return 0;
}

/**
 * @brief Setter for an entity string.
 *
 * Stores a string in an entity.
 *
 * @param entity The entity to set.
 * @param string The string to store.
 * @param free Wherther the string should be freed on entity destruction.
*/
int json_entity_set_string(json_entity_t *entity, char *string, bool freeable)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_STRING;
    entity->content.string = string;
    entity->dynamic_value = freeable;
    return 0;
}
