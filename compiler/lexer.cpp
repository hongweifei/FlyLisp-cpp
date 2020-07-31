




#include "lexer.hpp"
#include <stdlib.h>


void table_init()
{
    number_table = (uint8_t*)calloc(256,sizeof(uint8_t));

    number_table['0'] = 1;
    number_table['1'] = 1;
    number_table['2'] = 1;
    number_table['3'] = 1;
    number_table['4'] = 1;
    number_table['5'] = 1;
    number_table['6'] = 1;
    number_table['7'] = 1;
    number_table['8'] = 1;
    number_table['9'] = 1;
}

























