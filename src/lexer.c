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

        switch (lexer->currentCharacter)
        {
            case '=': return lexer_advanced_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advanced_with_token(lexer, init_token(TOKEN_SEMICOLON, lexer_get_current_char_as_string(lexer))); break;
            case '{': return lexer_advanced_with_token(lexer, init_token(TOKEN_LEFTCURBRACE, lexer_get_current_char_as_string(lexer))); break;
            case '}': return lexer_advanced_with_token(lexer, init_token(TOKEN_RIGHTCURBRACE, lexer_get_current_char_as_string(lexer))); break;
        }
    }
}

token_T* lexer_collect_string(lexer_T* lexer)
{

}

token_T* lexer_advanced_with_token(lexer_T* lexer, token_T* token)
{
    lexer_advanced(lexer);

    return token;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{

}