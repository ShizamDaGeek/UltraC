#ifndef TOKEN_H
#define TOKEN_H

#include "libs.h"

typedef struct TOKEN_STRUCT
{
    // Token structors
    enum
    {
        TOKEN_IDENTIFIER,
        TOKEN_LEFTCURBRACE,
        TOKEN_EQUALS,
        TOKEN_SEMICOLON,
        TOKEN_STRING,
        TOKEN_NUMBER,
        TOKEN_RIGHTCURBRACE
    }type;

    char* value;
}token_T;

token_T* init_token(int type, char* value);

#endif