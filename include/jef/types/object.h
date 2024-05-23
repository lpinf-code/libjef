/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/types/object.h
*/

/**
 * @file
 * @brief JSON object type definition.
 *
 * This file defines the JSON object type.
*/

#include <stdbool.h>
#include <stdint.h>

#include "defs.h"
#include "entity.h"

#ifndef JEF_TYPE_OBJECT_H
    #define JEF_TYPE_OBJECT_H

/**
 * @brief JSON object entry.
 *
 * This is one object key-value pair.
 * These are stored in a self-balancing binary
 * tree.
*/
struct json_object_entry_s {
    /**
     * @brief The value in the pair.
    */
    json_entity_t value;

    /**
     * @brief The key in the pair.
    */
    char *key;

    /**
     * @brief The nearest element with a lower hash.
    */
    struct json_object_entry_s *less;

    /**
     * @brief The nearest element with a greater or equal hash.
    */
    struct json_object_entry_s *gteq;

    /**
     * @brief The storage hash.
    */
    uint64_t hash;
};

/**
 * @brief JSON object.
 *
 * This is a JSON object, a collection
 * of entities stored in key-value pairs.
*/
struct json_object_s {
    /**
     * @brief The root of the entry tree.
    */
    struct json_object_entry_s *root;
};

#endif // !JEF_OBJECT_H
