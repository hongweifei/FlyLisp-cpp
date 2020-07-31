


#ifndef __TOKEN_HEAD__
#define __TOKEN_HEAD__


#include <stdint.h>
#include <string>
#include <map>


namespace FlyLisp
{


    enum TokenType : uint8_t
    {
        /*运算符和分隔符*/
        TK_PLUS,                    // +   加号
        TK_MINUS,                   // -   减号
        TK_STAR,                    // *   乘号
        TK_DIVIDE,                  // /   除号
        TK_MOD,                     // %   求余运算符
        TK_EQ,                      // ==  等号
        TK_NEQ,                     // !=  不等号
        TK_LT,                      // <   小于号
        TK_LEQ,                     // <=  小于等于号
        TK_GT,                      // >   大于号
        TK_GEQ,                     // >=  大于等于号
        TK_ASSIGN,                  // =   赋值运算符
        TK_POINTSTO,                // -> 
        TK_DOT,                     // .  
        TK_AND,                     // &   地址与运算符
        TK_OR,                      // |
        TK_THAN,                    // :


        TK_FALSE,                   // !


        TK_OPENPA,                  // (   左圆括号
        TK_CLOSEPA,                 // )   有圆括号
        TK_OPENBR,                  // [   左中括号
        TK_CLOSEBR,                 // ]   右中括号
        TK_BEGIN,                   // {   左大括号
        TK_END,                     // }   右大括号
        TK_SEMICOLON,               // ;   分号
        TK_COMMA,                   // ,   逗号
        TK_ELLIPSIS,                // ... 省略号

        TK_EOF,                     //文件结束符

        /*标识符*/
        TK_IDENT,           //标识符
        TK_NONE,            //空

        /**/
        TK_CNUMBER,         //
        TK_CCHAR,           //
        TK_CSTR,            //

        /*关键字*/
        KW_IMPORT,          // import
        KW_RETURN,          // return
        KW_IF,              // if
        KW_ELSE,
        KW_SWITCH,          // switch
        KW_WHILE,           // while
        KW_FOR,             // for
        KW_UNION,           // union
        KW_STRUCT,          // struct
        KW_CLASS,           // class


        KW_VAR,             // var
        KW_FUNCTION,        // function,func

        KW_NULL,            // null
        KW_VOID,            // void关键字
        KW_SHORT,           // short关键字
        KW_INT,             // int关键字
        KW_LONG,            // long关键字
        KW_FLOAT,           // float
        KW_DOUBLE,          // double
        KW_BOOL,            // bool
        KW_CHAR,            // char关键字
        KW_STRING,          // string
    };

    ::std::map<TokenType, const char*> type_map;
    ::std::map<const char*, TokenType> value_map;
    ::std::map<const char*, TokenType> keyword_map;
    void token_map_init();
    const char *stringify_token_type(TokenType type) noexcept;
    int get_str_token_type(const char *str) noexcept;         //存在返回其类型，否则返回 -1
    int str_is_keyword(const char *str) noexcept;             //是keyword符号其类型，否则返回 -1



    class Token
    {
    private:
        
    public:
        
        TokenType type;
        const ::std::string *value;
        uint32_t line;//行数
        uint32_t cols;//偏移，列数 offset


        Token(TokenType type, const ::std::string &value, uint32_t line, uint32_t cols);
        ~Token();

        void print();
    };




} // namespace FlyLisp

































#endif // __TOKEN_HEAD__






















