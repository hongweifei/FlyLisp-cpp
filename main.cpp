








#include "parser/lexer.hpp"
#include "parser/parser.hpp"
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


        parse(&stream);
        for (size_t i = 0; i < parse_tree.size(); i++)
        {
            parse_tree[i]->print();
        }
        
    }
    else
    {
        printf("请添加一个文件\n");
    }


    return 0;
}









