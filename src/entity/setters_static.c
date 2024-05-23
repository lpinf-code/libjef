/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/entity/setters_static.c
*/

#include "jef/entity.h"
#include <stdlib.h>

/**
 * @brief Setter for an entity integer.
 *
 * Stores an integer in an entity.
 *
 * @param entity The entity to set.
 * @param integer The integer to store.
*/
int json_entity_set_integer(json_entity_t *entity, int64_t integer)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_INTEGER;
    entity->content.integer = integer;
    entity->dynamic_value = false;
    return 0;
}

/**
 * @brief Setter for an entity number.
 *
 * Stores an number in an entity.
 *
 * @param entity The entity to set.
 * @param number The number to store.
*/
int json_entity_set_number(json_entity_t *entity, double number)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_NUMBER;
    entity->content.number = number;
    entity->dynamic_value = false;
    return 0;
}

/**
 * @brief Setter for an entity boolean.
 *
 * Stores an boolean in an entity.
 *
 * @param entity The entity to set.
 * @param boolean The boolean to store.
*/
int json_entity_set_boolean(json_entity_t *entity, bool boolean)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_BOOLEAN;
    entity->content.object = NULL;
    entity->content.boolean = boolean;
    entity->dynamic_value = false;
    return 0;
}

/**
 * @brief Setter for a null entity.
 *
 * Sets an entity to null.
 *
 * @param entity The entity to set.
*/
int json_entity_set_null(json_entity_t *entity)
{
    if (entity == NULL)
        return -1;
    if (entity->dynamic_value && entity->type == JSON_STRING)
        free(entity->content.string);
    entity->type = JSON_NULL;
    entity->content.object = NULL;
    entity->dynamic_value = false;
    return 0;
}
