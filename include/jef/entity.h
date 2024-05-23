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

json_entity_t *json_entity_new(void);
void json_entity_init(json_entity_t *entity);
void json_entity_destroy(json_entity_t *entity);

int json_entity_get(json_entity_t *entity, enum json_type type, void *vptr);

int json_entity_set_object(json_entity_t *entity, json_object_t *object);
int json_entity_set_array(json_entity_t *entity, json_array_t *array);
int json_entity_set_string(json_entity_t *entity, char *string, bool free);
int json_entity_set_integer(json_entity_t *entity, int64_t integer);
int json_entity_set_number(json_entity_t *entity, double number);
int json_entity_set_boolean(json_entity_t *entity, bool boolean);
int json_entity_set_null(json_entity_t *entity);

#endif // !JEF_ENTITY_H
