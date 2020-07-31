



#include "token.hpp"
#include <stdio.h>
#include <string.h>

namespace FlyLisp
{
    void token_map_init()
    {
        /**token type map init*/

        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_PLUS, "+"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_MINUS, "-"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_STAR, "*"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_DIVIDE, "/"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_MOD, "%"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_EQ, "=="));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_NEQ, "!"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_LT, "<"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_LEQ, "<="));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_GT, ">"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_GEQ, ">="));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_ASSIGN, "="));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_POINTSTO, "->"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_DOT, "."));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_AND, "&"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_OR, "|"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_THAN, ":"));


        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_FALSE, "!"));


        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_OPENPA, "("));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_CLOSEPA, ")"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_OPENBR, "["));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_CLOSEBR, "]"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_BEGIN, "{"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_END, "}"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_SEMICOLON, ";"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_COMMA, ","));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_ELLIPSIS, "..."));


        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_EOF, "EOF"));


        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_IDENT, "IDENT"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_NONE, "NONE"));


        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_CNUMBER, "NUMBER"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_CCHAR, "CHAR"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (TK_CSTR, "STR"));


        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_IMPORT, "import"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_RETURN, "return"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_IF, "if"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_ELSE, "else"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_SWITCH, "switch"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_WHILE, "while"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_FOR, "for"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_UNION, "union"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_STRUCT, "struct"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_CLASS, "class"));

        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_VAR, "var"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_FUNCTION, "function"));

        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_NULL, "null"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_VOID, "void"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_SHORT, "short"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_INT, "int"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_LONG, "long"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_FLOAT, "float"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_DOUBLE, "double"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_BOOL, "boolean"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_CHAR, "char"));
        type_map.insert(::std::map<TokenType, const char*>::value_type (KW_STRING, "string"));





        /**value map init*/

        value_map.insert(::std::map<const char*, TokenType>::value_type ("+", TK_PLUS));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("-", TK_MINUS));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("*", TK_STAR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("/", TK_DIVIDE));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("%", TK_MOD));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("==", TK_EQ));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("!=", TK_NEQ));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("<", TK_LT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("<=", TK_LEQ));
        value_map.insert(::std::map<const char*, TokenType>::value_type (">", TK_GT));
        value_map.insert(::std::map<const char*, TokenType>::value_type (">=", TK_GEQ));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("=", TK_ASSIGN));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("->", TK_POINTSTO));
        value_map.insert(::std::map<const char*, TokenType>::value_type (".", TK_DOT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("&", TK_AND));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("|", TK_OR));
        value_map.insert(::std::map<const char*, TokenType>::value_type (":", TK_THAN));


        value_map.insert(::std::map<const char*, TokenType>::value_type ("!", TK_FALSE));


        value_map.insert(::std::map<const char*, TokenType>::value_type ("(", TK_OPENPA));
        value_map.insert(::std::map<const char*, TokenType>::value_type (")", TK_CLOSEPA));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("[", TK_OPENBR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("]", TK_CLOSEBR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("{", TK_BEGIN));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("}", TK_END));
        value_map.insert(::std::map<const char*, TokenType>::value_type (";", TK_SEMICOLON));
        value_map.insert(::std::map<const char*, TokenType>::value_type (",", TK_COMMA));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("...", TK_ELLIPSIS));


        value_map.insert(::std::map<const char*, TokenType>::value_type ("EOF", TK_EOF));


        value_map.insert(::std::map<const char*, TokenType>::value_type ("IDENT", TK_IDENT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("NONE", TK_NONE));


        value_map.insert(::std::map<const char*, TokenType>::value_type ("NUMBER", TK_CNUMBER));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("CHAR", TK_CCHAR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("STRING", TK_CSTR));


        value_map.insert(::std::map<const char*, TokenType>::value_type ("import", KW_IMPORT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("return", KW_RETURN));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("if", KW_IF));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("else", KW_ELSE));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("switch", KW_SWITCH));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("while", KW_WHILE));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("for", KW_FOR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("union", KW_UNION));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("struct", KW_STRUCT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("class", KW_CLASS));

        value_map.insert(::std::map<const char*, TokenType>::value_type ("var", KW_VAR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("function", KW_FUNCTION));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("func", KW_FUNCTION));

        value_map.insert(::std::map<const char*, TokenType>::value_type ("null", KW_NULL));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("NULL", KW_NULL));

        value_map.insert(::std::map<const char*, TokenType>::value_type ("void", KW_VOID));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("short", KW_SHORT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("int", KW_INT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("long", KW_LONG));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("float", KW_FLOAT));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("double", KW_DOUBLE));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("bool", KW_BOOL));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("char", KW_CHAR));
        value_map.insert(::std::map<const char*, TokenType>::value_type ("string", KW_STRING));






        /**keyword map init*/

        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("import", KW_IMPORT));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("return", KW_RETURN));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("if", KW_IF));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("else", KW_ELSE));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("switch", KW_SWITCH));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("while", KW_WHILE));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("for", KW_FOR));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("union", KW_UNION));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("struct", KW_STRUCT));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("class", KW_CLASS));

        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("var", KW_VAR));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("function", KW_FUNCTION));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("func", KW_FUNCTION));

        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("null", KW_NULL));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("NULL", KW_NULL));

        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("void", KW_VOID));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("short", KW_SHORT));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("int", KW_INT));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("long", KW_LONG));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("float", KW_FLOAT));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("double", KW_DOUBLE));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("bool", KW_BOOL));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("char", KW_CHAR));
        keyword_map.insert(::std::map<const char*, TokenType>::value_type ("string", KW_STRING));
    }


    const char *stringify_token_type(TokenType type) noexcept
    {
        if (type_map.count(type))
            return type_map[type];
        else
            return "<unknown type>";
    }

    int get_str_token_type(const char *str) noexcept
    {
        if (value_map.count(str))
            return value_map[str];
        else
            return -1;
    }


    int str_is_keyword(const char *str) noexcept
    {
        if (keyword_map.count(str))
            return keyword_map[str];
        else
            return -1;
    }



    
    Token::Token(TokenType type, const ::std::string &value, uint32_t line, uint32_t cols)
    {
        this->type = type;
        this->value = &value;
        this->line = line;
        this->cols = cols;
    }


    Token::~Token()
    {
        
    }


    void Token::print()
    {
        printf("TokenType:%d\n",this->type);
        printf("TokenValue:%s\n",this->value->c_str());
        printf("TokenLine:%d\n",this->line);
        printf("TokenCols:%d\n",this->cols);
    }

} // namespace FlyLisp














