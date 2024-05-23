/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/entity.h
*/

/**
 * @file
 * @brief JSON entity manipulation functions.
*/

#include "types/defs.h"
#include "types/entity.h"

#ifndef JEF_ENTITY_H
    #define JEF_ENTITY_H

/**
 * @brief Creates a new JSON entity initialized to `JSON_NULL`.
 *
 * This entity is allocated in the heap and must be destroyed.
 *
 * @returns A pointer to the entity, or NULL on failure.
*/
json_entity_t *json_entity_new(void);

/**
 * @brief Initializes a JSON entity to `JSON_NULL`.
 *
 * This function allows for initialization of non-dynamically
 * allocated or pre-existing entities (such as object entries).
 *
 * @param entity The entity to initialize.
*/
void json_entity_init(json_entity_t *entity);

/**
 * @brief Destroys a JSON entity.
 *
 * For entities allocated using `json_entity_new`,
 * serves as a destructor.
 *
 * @param entity The entity to destroy.
*/
void json_entity_destroy(json_entity_t *entity);

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
int json_entity_get(json_entity_t *entity, enum json_type type, void *vptr);

/**
 * @brief Setter for an entity object.
 *
 * Stores an object in an entity.
 *
 * @param entity The entity to set.
 * @param object The object to store.
*/
int json_entity_set_object(json_entity_t *entity, json_object_t *object);

/**
 * @brief Setter for an entity array.
 *
 * Stores an array in an entity.
 *
 * @param entity The entity to set.
 * @param array The array to store.
*/
int json_entity_set_array(json_entity_t *entity, json_array_t *array);

/**
 * @brief Setter for an entity string.
 *
 * Stores a string in an entity.
 *
 * @param entity The entity to set.
 * @param string The string to store.
 * @param free Wherther the string should be freed on entity destruction.
*/
int json_entity_set_string(json_entity_t *entity, char *string, bool free);

/**
 * @brief Setter for an entity integer.
 *
 * Stores an integer in an entity.
 *
 * @param entity The entity to set.
 * @param integer The integer to store.
*/
int json_entity_set_integer(json_entity_t *entity, int64_t integer);

/**
 * @brief Setter for an entity number.
 *
 * Stores an number in an entity.
 *
 * @param entity The entity to set.
 * @param number The number to store.
*/
int json_entity_set_number(json_entity_t *entity, double number);

/**
 * @brief Setter for an entity boolean.
 *
 * Stores an boolean in an entity.
 *
 * @param entity The entity to set.
 * @param boolean The boolean to store.
*/
int json_entity_set_boolean(json_entity_t *entity, bool boolean);

/**
 * @brief Setter for a null entity.
 *
 * Sets an entity to null.
 *
 * @param entity The entity to set.
*/
int json_entity_set_null(json_entity_t *entity);

#endif // !JEF_ENTITY_H
