/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/object.h
*/

/**
 * @file
 * @brief JSON object management functions.
*/

#include "types/object.h"

#ifndef JEF_OBJECT_H
    #define JEF_OBJECT_H

/**
 * @brief Creates a new JSON object.
 *
 * This object is empty by default.
 *
 * @returns The object, or NULL on allocation error.
*/
json_object_t *json_object_new(void);

/**
 * @brief Destroys a JSON object.
 *
 * @param object The object to destroy.
*/
void json_object_destroy(json_object_t *object);

/**
 * @brief Inserts an entity at a key in an object.
 *
 * @param object The object to insert into.
 * @param key The key to insert at.
 * @param entity The entity to copy into. You may then destroy the original.
 * @param free_key A flag describing if the key should be freed on object
 *                 destruction.
*/

void json_object_push(
    json_object_t *object,
    char *key,
    json_entity_t *entity,
    bool free_key
);

/**
 * @brief Retrieves an entity at a key.
 *
 * @param object The object to look into.
 * @param key The key to retrieve from.
 * @returns The entity, or NULL if not found (and for errors).
*/
json_entity_t *json_object_get(json_object_t *object, const char *key);

#endif // !JEF_OBJECT_H
