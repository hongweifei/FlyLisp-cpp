



#ifndef __LEXER_HEAD__
#define __LEXER_HEAD__


#include "token.hpp"
#include <stdint.h>


namespace FlyLisp
{
    static FILE *using_fp = NULL;
    static uint32_t line = 1;
    static uint32_t cols = 0;
    static uint32_t prev_cols = 1;


    static bool *letter_table;     //字母表
    static char *symbol_table;     //符号表
    static bool *number_table;     //ascii总共256个字符


    void table_init();
    void lexer_init();


    //判断一个字符是否为数字
    bool is_digit(const char ch);

    //判断一个字符是否为字母
    bool is_letter(const char ch);

    //判断一个字符是否为符号
    bool is_symbol(const char ch);




    int next_ch();
    int prev_ch();
    int next_line();
    Token *get_token(FILE *fp);
    TokenStream &get_token_stream(FILE *fp);

} // namespace FlyLisp























#endif // __LEXER_HEAD__








