








#include "compiler/lexer.hpp"
#include <stdio.h>


int main(int argc,char *argv[])
{

    if (argc > 1)
    {
        FlyLisp::lexer_init();
        FILE *fp = fopen(argv[1],"r");

        
        FlyLisp::TokenStream stream = FlyLisp::get_token_stream(fp);
        stream.print();
        
        /*
        fseek(fp,0L,SEEK_SET);
        FlyLisp::Token *token = FlyLisp::get_token(fp);
        

    print:
        if (token != NULL)
            token->print();
        else
        {
            token = FlyLisp::get_token(fp);
            goto print;
        }    

        delete token;
        */
    }
    else
    {
        printf("请添加一个文件\n");
    }


    return 0;
}









