




#include "lexer.hpp"
#include <stdlib.h>



namespace FlyLisp
{
    void table_init()
    {
        letter_table = (bool*)calloc(256,sizeof(bool));
        symbol_table = (bool*)calloc(256,sizeof(bool));
        number_table = (bool*)calloc(256,sizeof(bool));


        for (uint16_t i = 'a'; i <= 'z'; i++)
            letter_table[i] = true;
        
        for (uint16_t i = 'A'; i <= 'Z'; i++)
            letter_table[i] = true;


        symbol_table['+'] = true;
        symbol_table['-'] = true;
        symbol_table['*'] = true;
        symbol_table['/'] = true;
        symbol_table['%'] = true;
        symbol_table['='] = true;
        symbol_table['!'] = true;
        symbol_table['<'] = true;
        symbol_table['>'] = true;
        symbol_table['.'] = true;
        symbol_table['&'] = true;
        symbol_table['|'] = true;
        symbol_table[':'] = true;
        symbol_table['('] = true;
        symbol_table[')'] = true;
        symbol_table['['] = true;
        symbol_table[']'] = true;
        symbol_table['{'] = true;
        symbol_table['}'] = true;
        symbol_table[';'] = true;
        symbol_table[','] = true;


        number_table['0'] = true;
        number_table['1'] = true;
        number_table['2'] = true;
        number_table['3'] = true;
        number_table['4'] = true;
        number_table['5'] = true;
        number_table['6'] = true;
        number_table['7'] = true;
        number_table['8'] = true;
        number_table['9'] = true;
    }


    void lexer_init()
    {
        token_map_init();
        table_init();
    }


    bool is_digit(const char ch)
    {
        return number_table[ch];
    }


    bool is_letter(const char ch)
    {
        return letter_table[ch];
    }


    bool is_symbol(const char ch)
    {
        return symbol_table[ch];
    }



    int next_ch()
    {
        cols++;
        return fgetc(using_fp);
    }

    int prev_ch()
    {
        fseek(using_fp,-2L,SEEK_CUR);
        int ch = fgetc(using_fp);
        if (ch == '\n')
        {
            line--;
            cols = prev_cols;
        }
        else
            cols--;
        return ch;
    }

    int next_line()
    {
        line++;
        prev_cols = cols;
        cols = 1;
        return fgetc(using_fp);
    }


    Token *get_token(FILE *fp)
    {
        if (using_fp != fp)
        {
            using_fp = fp;
            line = 1;
            cols = 0;
        }

        //TokenType type = TK_NONE;
        //::std::string value;
        char ch[2] = {0,'\0'};
        #define on_get ch[0]

start_get_token:
        while (true)
        {
            on_get = next_ch();

            switch (on_get)
            {
            case EOF:
                return NULL;
            case '\n':
                line++;
                prev_cols = cols;
                cols = 1;
                continue;
            case ' ':
                continue;
            
            default:
                break;
            }

            break;
        }


        /**数字*/
        if (is_digit(on_get))
        {
            ::std::string value;
            value += ch;

            on_get = next_ch();
            while (is_digit(on_get))
            {
                value += ch;
                on_get = next_ch();
            }
            prev_ch();

            int length = value.length();
            return new Token(TK_CNUMBER,value,line,cols - length);
        }

        /**标识符*/
        else if (is_letter(on_get) || on_get == '_')
        {
            ::std::string value;
            value += ch;

            on_get = next_ch();
            while (is_letter(on_get) || on_get == '_')
            {
                value += ch;
                on_get = next_ch();
            }
            prev_ch();

            int type = str_is_keyword(value.c_str());
            int length = value.length();
            if (type == -1)
                return new Token(TK_IDENTIFIER,value,line,cols - length);
            else
                return new Token(TokenType(type),value,line,cols - length);
        }


        /**字符串*/
        else if (on_get == '\'' || on_get == '\"')
        {
            ::std::string value;
            int symbol = on_get;
            on_get = next_ch();

            while (true)
            {
                if (on_get == EOF)
                    return NULL;
                else if (on_get == '\n')
                    on_get = next_line();
                else if (on_get == symbol)
                    break;
                else
                {
                    value += ch;
                    on_get = next_ch();
                }
            }

            int length = value.length();
            return new Token(TK_CSTR,value,line,cols - length);
        }



    /**符号*/

        /**注释*/
        else if (on_get == '/')
        {
            on_get = next_ch();

            //单行注释
            if (on_get == '/')
            {
                on_get = next_ch();
                while (on_get != '\n')
                {
                    on_get = next_ch();

                    if (on_get == EOF)
                        return NULL;
                }
                prev_ch();
            }

            //多行注释
            else if (on_get == '*')
            {
                int star_line = line;
                int star_cols = cols;

                on_get = next_ch();

                while (true)
                {
                    if (on_get == EOF)
                        return NULL;
                    else if (on_get == '\n')
                        on_get = next_line();
                    else
                    {
                        on_get = next_ch();

                        if (on_get == '*')
                        {
                            if (next_ch() == '/')
                                goto start_get_token;
                            else
                                prev_ch();
                        }
                    }
                }
            }

            else
            {
                prev_ch();
                return new Token(TK_DIVIDE,::std::string("/"),line,cols - 1);
            }
        }


        /**不等于，等于，大于等于，小于等于,赋值*/
        else if (on_get == '!' || on_get == '=' || on_get == '<' || on_get == '>')
        {
            on_get = next_ch();
            ::std::string value(ch);
            if (on_get == '=')
            {
                value += "=";
                return new Token(TokenType(get_str_token_type(value.c_str())),value,line,cols - 2);
            }
            else
            {
                prev_ch();
                return new Token(TokenType(get_str_token_type(value.c_str())),value,line,cols - 1);
            }
        }


        /** -> */
        else if (on_get == '-')
        {
            on_get = next_ch();
            if (on_get == '>')
                return new Token(TK_POINTSTO,"->",line,cols - 2);
            else
            {
                prev_ch();
                return new Token(TK_MINUS,"-",line,cols - 1);
            }
        }


        /**省略号*/
        else if (on_get == '.')
        {
            int next_ch1 = next_ch();
            int next_ch2 = next_ch();
            if (next_ch1 == '.' && next_ch2 == '.')
                return new Token(TK_ELLIPSIS,"...",line,cols - 3);
            else
            {
                prev_ch();
                prev_ch();
                return new Token(TK_DOT,".",line,cols - 1);
            }
        }


        /**其他符号*/
        else if (is_symbol(on_get))
        {
            ::std::string value(ch);
            int type = get_str_token_type(value.c_str());
            if (type == -1)
                return NULL;
            else
                return new Token(TokenType(type),value,line,cols - 1);
        }

        return NULL;
    }


    TokenStream &get_token_stream(FILE *fp)
    {
        TokenStream stream;
        Token *token = get_token(fp);
        while (token != NULL)
        {
            stream.push(*token);
            token = get_token(fp);
        }
        return stream;
    }


} // namespace FlyLisp

















