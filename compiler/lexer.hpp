



#ifndef __LEXER_HEAD__
#define __LEXER_HEAD__


#include <stdint.h>



uint8_t *number_table;


void table_init();


//判断一个字符是否为数字
bool is_digit(int ch);
//bool is_digit(const char*);


//判断一个字符是否为字母
bool is_letter(int ch);

//判断一个字符是否为符号
bool is_symbol(int ch);

























#endif








