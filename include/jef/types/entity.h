/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/types/entity.h
*/

/**
 * @file
 * @brief JSON entity type definition.
 *
 * This file defines the JSON entity types and
 * enumerations.
*/

#include <stdbool.h>
#include <stdint.h>

#include "defs.h"

#ifndef JEF_TYPE_ENTITY_H
    #define JEF_TYPE_ENTITY_H

/**
 * @brief An enumeration of the JSON types.
 */
enum json_type {
    JSON_NULL,    //!< The literal `null` value
    JSON_BOOLEAN, //!< `true` or `false`
    JSON_INTEGER, //!< A Number with no decimal point
    JSON_NUMBER,  //!< A Number with a decimal point
    JSON_STRING,  //!< A string of characters
    JSON_OBJECT,  //!< A key-value storage structure
    JSON_ARRAY    //!< A linear storage structure
};

/**
 * @brief The actual value of an entity
 *
 * A 64-byte meta-value that contains all the
 * correct types for the `json_entity_s::value`
 * field.
 */
union json_entity_content {
    /**
     * @brief The value when the type is `JSON_BOOLEAN`
     *
     * The rest is initialized to 0.
    */
    bool boolean;

    /**
     * @brief The value when the type is `JSON_INTEGER`
     *
     * In JSON, integers vs numbers don't exist, but in C
     * they are very different.
     *
     * Thus, when parsing an number with no decimal
     * point/exponent, we assume it to be a `BigInt`
     * (aka 64-bit signed integer value).
     *
     * @note To fetch the JS `Number` equivalent, instead fetch
     *       `json_entity_content::number` which will always be set
     *       when `JSON_INTEGER` is set.
    */
    uint64_t integer; // Automatically inferred from source

    /**
     * @brief The value when the type is `JSON_NUMBER` or `JSON_INTEGER`
     *
     * In JS, all numbers are double precision floating point
     * numbers.
     *
     * Staying true to JS, this value is set for all number types,
     * which means even if the value is a fixed `JSON_INTEGER`,
     * this value is set.
    */
    double number;    // file !

    /**
     * @brief The value when the type is `JSON_STRING`
     *
     * A separately initialized, null-terminated string.
    */
    char *string;

    /**
     * @brief The value when the type is `JSON_OBJECT`
     *
     * A separately initialized structure containing
     * entities associated with keys (which must be strings).
     *
     * @see json_object_t
    */
    json_object_t *object;

    /**
     * @brief The value when the type is `JSON_ARRAY`
     *
     * A separately initialized structure with pointers
     * to a sequence of entities, alongside its size.
     *
     * @see json_array_t
    */
    json_array_t *array;
};

/**
 * @brief A JSON entity
 *
 * The concept of entity resides in a structure
 * that represents any possible JSON type,
 * because it keeps track of the its internal
 * type itself.
 *
 * @warning Destroying an **object** or **array**
 *          entity will destory all contained entities
 *          in said object or arrays.
*/
struct json_entity_s {
    /**
     * @brief The actual entity content.
     *
     * A 64-bit union where the type to pick
     * depends on the `json_entity_s::type`
     * attribute.
     *
     * Will be freed if the type is any pointer
     * type and the `json_entity_s::dynamic_value`
     * boolean is set.
    */
    union json_entity_content content;

    /**
     * @brief The entity type.
     *
     * An enumeration corresponding to the type
     * of the `json_entity_s::content` attribute.
     *
     * If this type is `JSON_NULL`, assume the
     * content contains nothing.
    */
    enum json_type type;

    /**
     * @brief Dynamic allocation value marker.
     *
     * A flag specifying that a string type
     * is contained in `json_entity_s::content`,
     * and that it should be freed on entity destruction.
     *
     * Does not apply to other pointer types such
     * as objects and arrays as they MUST be dynamically
     * allocated in the first place. It is still considered
     * good practice to keep it set for these non-affected
     * pointer types.
    */
    bool dynamic_value;

    /**
     * @brief Dynamic key allocation marker.
     *
     * @note Only useful in object entries.
     *
     * A flag specifying that a parent object entry
     * contains a key to free on destruction.
     *
     * If the value is not loaded in an object entry
     * (such as the root or an array), this flag
     * is ignored.
    */
    bool dynamic_key;
};

#endif // !JEF_ENTITY_H
