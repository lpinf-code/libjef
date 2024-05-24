/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/object/extras.c
*/

#include "jef/object.h"
#include <stddef.h>

static void run_node(
    struct json_object_entry_s *entry,
    void (*loopfn)(const char *key, json_entity_t *value)
)
{
    if (entry == NULL)
        return;
    run_node(entry->less, loopfn);
    loopfn(entry->key, &entry->value);
    run_node(entry->gteq, loopfn);
}

/**
 * @brief Runs a function for each pair in the object.
 *
 * @param object The object to look into.
 * @param loopfn The function to run.
*/
void json_object_forpairs(
    json_object_t *object,
    void (*loopfn)(const char *key, json_entity_t *value)
)
{
    run_node(object->root, loopfn);
}
