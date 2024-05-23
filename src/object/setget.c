/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/object/setget.c
*/

#include "jef/entity.h"
#include "jef/object.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief A simple yet effective hashing function.
*/
static uint64_t hash(const char *k)
{
    uint64_t out = 0xA5A5A5A5A5A5A5A5;

    for (size_t i = 0; k[i] != '\0'; i++) {
        out = (out + i) & 1
            ? (out * k[i]) ^ ((out << 7) + (k[i] >> 3))
            : (out * k[i]) ^ ((out << 11) + (k[i] >> 5));
    }
    return out;
}

static void push(
    struct json_object_entry_s **parent,
    struct json_object_entry_s *entry
)
{
    if ((*parent) == NULL) {
        *parent = entry;
        printf("Inserted '%s' %ld\n", entry->key, entry->hash);
        return;
    }
    if ((*parent)->key > entry->key)
        push(&(*parent)->less, entry);
    else
        push(&(*parent)->gteq, entry);
}

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
)
{
    struct json_object_entry_s* entry =
        malloc(sizeof(struct json_object_entry_s));

    entry->key = key;
    entry->gteq = NULL;
    entry->less = NULL;
    entry->hash = hash(key);
    json_entity_init(&entry->value);
    entry->value.type = entity->type;
    entry->value.dynamic_value = entity->dynamic_value;
    entry->value.content = entity->content;
    entry->value.dynamic_key = free_key;
    push(&object->root, entry);
}

static bool equal(const char *a, const char *b)
{
    size_t i = 0;

    while (true) {
        if (a[i] != b[i])
            return false;
        if (a[i] == '\0')
            return true;
        i++;
    }
}

/**
 * @brief Retrieves an entity at a key.
 *
 * @param object The object to look into.
 * @param key The key to retrieve from.
 * @returns The entity, or NULL if not found (and for errors).
*/
json_entity_t *json_object_get(json_object_t *object, const char *key)
{
    struct json_object_entry_s* entry = object->root;
    uint64_t hashed_key = hash(key);

    while (true) {
        if (entry == NULL)
            return NULL;
        if (entry->hash == hashed_key && equal(entry->key, key))
            break;
        if (entry->hash > hashed_key)
            entry = entry->less;
        else
            entry = entry->gteq;
    }
    return &entry->value;
}
