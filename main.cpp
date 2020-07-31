








#include "compiler/lexer.hpp"
#include <stdio.h>


int main(int argc,char *argv[])
{

    if (argc > 1)
    {
        FILE *fp = fopen(argv[1],"r");
        FlyLisp::TokenStream stream = FlyLisp::get_token_stream(fp);
        stream.print();
    }
    else
    {
        printf("请添加一个文件\n");
    }


    return 0;
}









