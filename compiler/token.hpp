



#ifndef __TOKEN_HEAD__
#define __TOKEN_HEAD__


#include <stdint.h>
#include <string>
#include <map>
#include <vector>


namespace FlyLisp
{

    //token类型
    enum TokenType : uint8_t
    {

        TK_NONE = 0,                //空

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
        TK_IDENTIFIER,           //标识符


        /**/
        TK_CNUMBER,         //
        TK_CCHAR,           //
        TK_CSTR,            //

        /*关键字*/
        KW_IMPORT,          // import
        KW_RETURN,          // return
        KW_IF,              // if
        KW_ELSE,            // else
        KW_SWITCH,          // switch
        KW_WHILE,           // while
        KW_FOR,             // for
        KW_UNION,           // union
        KW_STRUCT,          // struct
        KW_ENUM,
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

    #define TOKEN_TYPE_NUMBER  sizeof(TokenType) / sizeof(uint8_t)  //token类型的数量
    //static ::std::string type_table[TOKEN_TYPE_NUMBER];           //type表，可以通过类型获取其字符串      这个玩意儿用不了map那个可以

    static ::std::map<TokenType, const char*> type_map;             //可通过类型获取其字符串
    static ::std::map<::std::string, TokenType> value_map;          //可通过字符串获取其类型
    static ::std::map<::std::string, TokenType> keyword_map;        //用来判断一个字符串是否是关键字
    //void token_table_init();                                      //初始化table
    void token_map_init();                                          //初始化map
    const char *stringify_token_type(TokenType type) noexcept;      //获取类型的字符串
    TokenType get_str_token_type(::std::string str) noexcept;       //存在返回其类型，否则返回 -1
    TokenType str_is_keyword(::std::string str) noexcept;           //是keyword符号其类型，否则返回 -1



    class Token
    {
    private:
        
    public:
        
        TokenType type;
        ::std::string value;
        uint32_t line;//行数
        uint32_t cols;//偏移，列数 offset

        Token();
        Token(TokenType type, const ::std::string &value, uint32_t line, uint32_t cols);
        ~Token();

        void print();
    };

    char *str(int32_t number);

    #define TokenStream ::std::vector<FlyLisp::Token*>  //token流
    void TokenStreamPrint(TokenStream &stream);         //输出token流中的各个token
    void TokenStreamWrite(TokenStream &stream,FILE *fp);

} // namespace FlyLisp

































#endif // __TOKEN_HEAD__






















