








#include "compiler/lexer.hpp"
#include <stdio.h>


using namespace FlyLisp;


int main(int argc,char *argv[])
{

    if (argc > 1)
    {
        FlyLisp::lexer_init();
        FILE *fp = fopen(argv[1],"r");
        FILE *log = fopen("./log.txt","w");

        TokenStream stream = get_token_stream(fp);
        TokenStreamPrint(stream);
        TokenStreamWrite(stream,log);

    }
    else
    {
        printf("请添加一个文件\n");
    }


    return 0;
}









