/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/entity/helper.c
*/

#include "jef/entity.h"
#include "jef/object.h"
#include "jef/array.h"

/**
 * @brief Retrieves an entity at a key in an entity object.
 *
 * @param entobj The entity with an object to look into.
 * @param key The key to retrieve from.
 * @returns The entity, or NULL if not found (and for errors).
*/
json_entity_t *json_entobj_get(json_entity_t *entobj, const char *key)
{
    json_object_t *object = json_entity_get_object(entobj);

    if (object == NULL)
        return NULL;
    return json_object_get(object, key);
}

/**
 * @brief Retrieves an entity at an index in an entity array.
 *
 * @param entobj The entity with an array to look into.
 * @param index The index to retrieve from.
 * @returns The entity, or NULL if not found (and for errors).
*/
json_entity_t *json_entarr_get(json_entity_t *entarr, size_t index)
{
    json_array_t *array = json_entity_get_array(entarr);

    if (array == NULL)
        return NULL;
    return json_array_at(array, index);
}
