/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/parsing.h
*/

#ifndef JEF_PARSING_H
    #define JEF_PARSING_H

    #define JEF_STR_DELIM "\"\'"

enum json_tk_type {
    JSON_TK_OBJ_START,
    JSON_TK_OBJ_END,
    JSON_TK_ARR_START,
    JSON_TK_ARR_END,
    JSON_TK_STRING,
    JSON_TK_NUMBER,
    JSON_TK_BOOL,
    JSON_TK_NULL,
    JSON_TK_SEP
};

struct json_token {
    enum json_tk_type type;
    const char *begin;
    int size;
    struct json_token *next;
};

struct json_tokens {
    struct json_token *start;
    struct json_token *end;
    const char *cursor;
    int errors;
};

int jef_tkn_isin(char c, const char *str);

int jef_tkn_next(struct json_tokens *tokens);

int jef_tkn_number(struct json_tokens *tokens, struct json_token *tok);

#endif // !JEF_PARSING_H
