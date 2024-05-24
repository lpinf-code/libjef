/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/entity/getters_static.c
*/

#include <stddef.h>

#include "jef/entity.h"

/**
 * @brief Getter for an entity number.
 *
 * Allows retrieval of the entity number, if it contains one.
 *
 * @param entity The entity to read.
 * @returns The value on success, 0 on error.
 *          Check for entity type separately.
*/
double json_entity_get_number(json_entity_t *entity)
{
    if (entity == NULL || entity->type != JSON_NUMBER)
        return 0;
    return entity->content.number;
}

/**
 * @brief Getter for an entity integer.
 *
 * Allows retrieval of the entity integer, if it contains one.
 *
 * @param entity The entity to read.
 * @returns The value on success, 0 on error.
 *          Check for entity type separately.
*/
uint64_t json_entity_get_integer(json_entity_t *entity)
{
    if (entity == NULL || entity->type != JSON_INTEGER)
        return 0;
    return entity->content.integer;
}

/**
 * @brief Getter for an entity boolean.
 *
 * Allows retrieval of the entity boolean, if it contains one.
 *
 * @param entity The entity to read.
 * @returns The value on success, false on error.
 *          Check for entity type separately.
*/
bool json_entity_get_boolean(json_entity_t *entity)
{
    if (entity == NULL || entity->type != JSON_BOOLEAN)
        return 0;
    return entity->content.boolean;
}
