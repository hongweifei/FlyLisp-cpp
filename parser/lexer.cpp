




#include "lexer.hpp"
#include <stdlib.h>



namespace FlyLisp
{
    void table_init()
    {
        letter_table = (bool*)calloc(256,sizeof(bool));
        symbol_table = (char*)calloc(256,sizeof(char));
        number_table = (bool*)calloc(256,sizeof(bool));


        for (uint16_t i = 'a'; i <= 'z'; i++)
            letter_table[i] = true;
        
        for (uint16_t i = 'A'; i <= 'Z'; i++)
            letter_table[i] = true;


        symbol_table['+'] = '+';
        symbol_table['-'] = '-';
        symbol_table['*'] = '*';
        symbol_table['/'] = '/';
        symbol_table['%'] = '%';
        symbol_table['='] = '=';
        symbol_table['!'] = '!';
        symbol_table['<'] = '<';
        symbol_table['>'] = '>';
        symbol_table['.'] = '.';
        symbol_table['&'] = '&';
        symbol_table['|'] = '|';
        symbol_table[':'] = ':';
        symbol_table['('] = '(';
        symbol_table[')'] = ')';
        symbol_table['['] = '[';
        symbol_table[']'] = ']';
        symbol_table['{'] = '{';
        symbol_table['}'] = '}';
        symbol_table[';'] = ';';
        symbol_table[','] = ',';


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
        //token_table_init();
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
            cols = prev_line_cols;
            printf("上移一行\n");
        }
        else
            cols--;
        return ch;
    }

    int next_line()
    {
        line++;
        prev_line_cols = cols;
        cols = 1;
        return next_ch();
    }


    Token *get_token(FILE *fp)
    {
        if (using_fp != fp)
        {
            using_fp = fp;
            line = 1;
            cols = 1;
            fseek(using_fp,0L,SEEK_SET);
        }

        //TokenType type = TK_NONE;
        ::std::string value;
        char ch = 0;



start_get_token:
        ch = next_ch();

        switch (ch)
        {
        case EOF:
            return NULL;

        case '\n':
            line++;
            prev_line_cols = cols;
            cols = 1;
            return get_token(fp);

        case ' ':
        case '\t':
        case '\r':
            return get_token(fp);
            
        default:
            break;
        }



        /**数字*/
        if (is_digit(ch))
        {
            value += ch;

            ch = next_ch();
            while (is_digit(ch) || ch == '.')
            {
                value += ch;
                ch = next_ch();
            }

            ch = prev_ch();
            if (ch == '.')
            {
                prev_ch();
                value.pop_back();
            }

            int length = value.length();

            return new Token(TK_CNUMBER,value,line,cols - length);
        }

        /**标识符*/
        else if (is_letter(ch) || ch == '_')
        {
            value += ch;

            ch = next_ch();
            while (is_letter(ch) || ch == '_' || is_digit(ch))
            {
                value += ch;
                ch = next_ch();
            }
            prev_ch();

            TokenType type = str_is_keyword(value);
            int length = value.length();
            if (type == TK_NONE)
                return new Token(TK_IDENTIFIER,value,line,cols - length);
            else
                return new Token(type,value,line,cols - length);
        }


        /**字符串*/
        else if (ch == '\'' || ch == '\"')
        {
            int symbol = ch;
            ch = next_ch();

            while (true)
            {
                if (ch == EOF)
                    return NULL;
                else if (ch == '\n')
                    ch = next_line();
                else if (ch == symbol)
                    break;
                else
                {
                    value += ch;
                    ch = next_ch();
                }
            }

            int length = value.length();
            return new Token(TK_CSTR,value,line,cols - length);
        }



    /**符号*/

        /**注释*/
        else if (ch == '/')
        {
            ch = next_ch();

            //单行注释
            if (ch == '/')
            {
                ch = next_ch();
                while (ch != '\n')
                {
                    ch = next_ch();

                    if (ch == EOF)
                        return NULL;
                }
                prev_ch();
            }

            //多行注释
            else if (ch == '*')
            {
                int star_line = line;
                int star_cols = cols;

                ch = next_ch();

                while (true)
                {
                    if (ch == EOF)
                        return NULL;
                    else if (ch == '\n')
                        ch = next_line();
                    else
                    {
                        ch = next_ch();

                        if (ch == '*')
                        {
                            if (next_ch() == '/')
                                return get_token(fp);
                            else
                                prev_ch();
                        }
                    }
                }
            }

            else
            {
                prev_ch();
                value = "/";
                return new Token(TK_DIVIDE,value,line,cols - 1);
            }
        }


        /**不等于，等于，大于等于，小于等于,赋值*/
        else if (ch == '!' || ch == '=' || ch == '<' || ch == '>')
        {
            value += ch;
            ch = next_ch();
            if (ch == '=')
            {
                value += "=";
                return new Token(get_str_token_type(value),value,line,cols - 2);
            }
            else
            {
                prev_ch();
                return new Token(get_str_token_type(value),value,line,cols - 1);
            }
        }


        /** -> */
        else if (ch == '-')
        {
            ch = next_ch();
            if (ch == '>')
                return new Token(TK_POINTSTO,"->",line,cols - 2);
            else
            {
                prev_ch();
                return new Token(TK_MINUS,"-",line,cols - 1);
            }
        }


        /**省略号*/
        else if (ch == '.')
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
        else if (is_symbol(ch))
        {
            value += ch;
            return new Token(get_str_token_type(value),value,line,cols - 1);
        }

        return NULL;
    }


    TokenStream &get_token_stream(FILE *fp)
    {
        TokenStream *stream = new TokenStream();
        Token *token = get_token(fp);

        while (token != NULL)
        {
            stream->push_back(token);
            token = get_token(fp);
        }
        return *stream;
    }


} // namespace FlyLisp

















