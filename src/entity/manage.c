/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/entity/management.c
*/

#include "jef/entity.h"
#include <stdlib.h>

/**
 * @brief Creates a new JSON entity initialized to `JSON_NULL`.
 *
 * This entity is allocated in the heap and must be destroyed.
 *
 * @returns A pointer to the entity, or NULL on failure.
*/
json_entity_t *json_entity_new(void)
{
    json_entity_t *entity = malloc(sizeof(json_entity_t));

    if (entity == NULL)
        return NULL;
    entity->dynamic_key = false;
    json_entity_init(entity);
    return entity;
}

/**
 * @brief Initializes a JSON entity to `JSON_NULL`.
 *
 * This function allows for initialization of non-dynamically
 * allocated or pre-existing entities (such as object entries).
 *
 * @param entity The entity to initialize.
*/
void json_entity_init(json_entity_t *entity)
{
    entity->dynamic_value = false;
    json_entity_set_null(entity);
}

/**
 * @brief Destroys a JSON entity.
 *
 * For entities allocated using `json_entity_new`,
 * serves as a destructor.
 *
 * @param entity The entity to destroy.
*/
void json_entity_destroy(json_entity_t *entity)
{
    free(entity);
}
