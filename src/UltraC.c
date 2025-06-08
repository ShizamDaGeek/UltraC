#include "include/libs.h"

int main(int argc, char** argv[])
{
    lexer_T* lexer = init_lexer(
    "int main()\n"
    "{\n"
        "string name = \"Shivam\";\n"
        "SysOutput < \"You number is: \" < name;\n"

        "return 0;\n"
    "}\n"
    );

    token_T* token = (void*)0;
    while ((token = lexer_get_next_token(lexer)) != (void*)0)
    {
        printf("Token Type(%d, %s)\n", token->type, token->value);
    }

    return 0;
}