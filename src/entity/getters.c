/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/entity/getters.c
*/

#include <stddef.h>

#include "jef/entity.h"

/**
 * @brief Getter for an entity value.
 *
 * Allows retrieval of the entity's data in a C native type.
 *
 * @param entity The entity to read.
 * @param type The expected type.
 * @param vptr A pointer where the value will be written. This pointer
 *             must match the type provided in `type`
 * @see json_type
 * @returns 0 on success, -1 on error.
*/
int json_entity_get(json_entity_t *entity, enum json_type type, void *vptr)
{
    if (entity == NULL || (type != entity->type
        && !(type == JSON_STRING && entity->type == JSON_NULL)))
        return -1;
    if (type == JSON_STRING)
        (*(char **)vptr) = entity->content.string;
    if (type == JSON_INTEGER)
        (*(int64_t *)vptr) = entity->content.integer;
    if (type == JSON_NUMBER)
        (*(double *)vptr) = entity->content.number;
    if (type == JSON_BOOLEAN)
        (*(bool *)vptr) = entity->content.boolean;
    if (type == JSON_OBJECT)
        (*(json_object_t **)vptr) = entity->content.object;
    if (type == JSON_ARRAY)
        (*(json_array_t **)vptr) = entity->content.array;
    return 0;
}

/**
 * @brief Getter for an entity object.
 *
 * Allows retrieval of the entity object, if it contains one.
 *
 * @param entity The entity to read.
 * @returns The value on success, NULL on error.
*/
json_object_t *json_entity_get_object(json_entity_t *entity)
{
    if (entity == NULL || entity->type != JSON_OBJECT)
        return NULL;
    return entity->content.object;
}

/**
 * @brief Getter for an entity array.
 *
 * Allows retrieval of the entity array, if it contains one.
 *
 * @param entity The entity to read.
 * @returns The value on success, NULL on error.
*/
json_array_t *json_entity_get_array(json_entity_t *entity)
{
    if (entity == NULL || entity->type != JSON_ARRAY)
        return NULL;
    return entity->content.array;
}

/**
 * @brief Getter for an entity string.
 *
 * Allows retrieval of the entity string, if it contains one.
 *
 * @param entity The entity to read.
 * @returns The value on success, NULL on error.
*/
char *json_entity_get_string(json_entity_t *entity)
{
    if (entity == NULL || entity->type != JSON_STRING)
        return NULL;
    return entity->content.string;
}
