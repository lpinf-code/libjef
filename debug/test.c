/*
** EPITECH PROJECT, 2024
** jef
** File description:
** debug/test.c
*/

#include "jef/json.h"
#include "jef/entity.h"

int main(void)
{
    char *test_string = (
        "{\n"
        "   'hello':.1,\n"
        "   'what\\'s up': true,\n"
        "   \"silly\": null,\n"
        "   'a': [1,2,3,4,5,null]\n"
        "}\n"
    );

    json_entity_destroy(json_unserialize(test_string));
}
