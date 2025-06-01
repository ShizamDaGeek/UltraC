#include "include/libs.h"

lexer_T* init_lexer(char* contents)
{
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->index = 0;
    lexer->currentCharacter = contents[lexer->index];

    return lexer;
}

void lexer_advanced(lexer_T* lexer)
{
    if (lexer->currentCharacter != '\0' && lexer->index < strlen(lexer->contents))
    {
        lexer->index += 1;
        lexer->currentCharacter = lexer->contents[lexer->index];
    }
}

void lexer_skip_whitespace(lexer_T* lexer)
{
    while (lexer->currentCharacter == ' ' || lexer->currentCharacter == 10)
    {
        lexer_advanced(lexer);
    }
}

token_T* lexer_get_next_token(lexer_T* lexer)
{
    while (lexer->currentCharacter != '\0' && lexer->index < strlen(lexer->contents))
    {
        if (lexer->currentCharacter == ' ' || lexer->currentCharacter == 10)
        {
            lexer_skip_whitespace(lexer);
        }

        if (isalnum(lexer->currentCharacter))
        {
            return lexer_collect_identifier(lexer);
        }

        if (lexer->currentCharacter == '"')
        {
            return lexer_collect_string(lexer);
        }

        switch (lexer->currentCharacter)
        {
            case '=': return lexer_advanced_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advanced_with_token(lexer, init_token(TOKEN_SEMICOLON, lexer_get_current_char_as_string(lexer))); break;
            case '{': return lexer_advanced_with_token(lexer, init_token(TOKEN_LEFTCURBRACE, lexer_get_current_char_as_string(lexer))); break;
            case '}': return lexer_advanced_with_token(lexer, init_token(TOKEN_RIGHTCURBRACE, lexer_get_current_char_as_string(lexer))); break;
            case '(': return lexer_advanced_with_token(lexer, init_token(TOKEN_LEFTPARENTHESIS, lexer_get_current_char_as_string(lexer))); break;
            case ')': return lexer_advanced_with_token(lexer, init_token(TOKEN_RIGHTPARENTHESIS, lexer_get_current_char_as_string(lexer))); break;
        }   
    }

    return (void*)0;
}

token_T* lexer_collect_string(lexer_T* lexer)
{
    lexer_advanced(lexer);
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer->currentCharacter != '"')
    {
        char* string = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(string) + 1) * sizeof(char));
        strcat(value, string);

        lexer_advanced(lexer);
    }

    lexer_advanced(lexer);

    return init_token(TOKEN_STRING, value);
}

token_T* lexer_collect_identifier(lexer_T* lexer)
{
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (isalnum(lexer->currentCharacter))
    {
        char* string = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(string) + 1) * sizeof(char));
        strcat(value, string);

        lexer_advanced(lexer);
    }

    return init_token(TOKEN_IDENTIFIER, value);
}

token_T* lexer_advanced_with_token(lexer_T* lexer, token_T* token)
{
    lexer_advanced(lexer);

    return token;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{
    char* string = calloc(2, sizeof(char));
    string[0] = lexer->currentCharacter;
    string[1] = '\0';

    return string;
}