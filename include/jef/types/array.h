/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/types/array.h
*/

/**
 * @file
 * @brief JSON array type definition.
 *
 * This file defines the JSON array type.
*/

#include <stdint.h>

#include "defs.h"

#ifndef JEF_TYPE_ARRAY_H
    #define JEF_TYPE_ARRAY_H

/**
 * @brief A JSON array.
 *
 * Contains a simple pointer array,
 * along with its size.
 *
 * Grows x2 on overflow.
*/
struct json_array_s {
    /**
     * @brief The entity pointer array.
     *
     * A pointer to each item in the array.
    */
    json_entity_t **content;

    /**
     * @brief The assigned length of the array.
    */
    uint32_t length;

    /**
     * @brief The real (allocated) length of the pointer array.
    */
    uint32_t region_size;
};

#endif // !JEF_ARRAY_H
