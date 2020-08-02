




#include "parser.hpp"








namespace FlyLisp
{

    void plus(Token *current)
    {
        //back_trace.push(type_map[TK_PLUS]);
    }

    void minus(Token *current)
    {
        //back_trace.push(type_map[TK_MINUS]);
    }

    void multiply(Token *current)
    {
        //back_trace.push(type_map[TK_STAR]);
    }

    void divide(Token *current)
    {
        //back_trace.push(type_map[TK_DIVIDE]);
    }

    void less(Token *current)
    {
        //back_trace.push(type_map[TK_LT]);
    }

    void greater(Token *current)
    {
        //back_trace.push(type_map[TK_GT]);
    }

    void equal(Token *current)
    {
        //back_trace.push(type_map[TK_EQ]);
    }

    void less_equal(Token *current)
    {
        //back_trace.push(type_map[TK_LEQ]);
    }

    void greater_equal(Token *current)
    {
        //back_trace.push(type_map[TK_GEQ]);
    }

    void not_equal(Token *current)
    {
        //back_trace.push(type_map[TK_NEQ]);
    }


    
    Token *next_token()
    {
        //return stream[stream_index++];
        stream_index++;
        return using_stream->at(stream_index);
    }



    Node *parse_simple_operation(Token *current)
    {
        Token *next = next_token();
        if (next == NULL)
            return NULL;

        switch (next->type)
        {
        case TK_CNUMBER:
        case TK_CSTR:
            return NULL;
        
        case TK_PLUS:
        case TK_MINUS:
        case TK_STAR:
        case TK_DIVIDE:
            Token *right_token = next_token();

            Node *left = new Node(current->value,NODE_TYPE_UNARY,current,NULL,NULL,NULL);
            Node *right = new Node("unkown",NODE_TYPE_UNKOWN,right_token);

            if (right_token != NULL)
            {
                if (right_token->type == current->type)
                {
                    right->name = right_token->value;
                    right->type = NODE_TYPE_UNARY;
                }
                else
                    return NULL;
            }

            return new Node(stringify_token_type(next->type),NODE_TYPE_BINARY,next,NULL,left,right);
        }

        return NULL;
    }

    Node *parse(TokenStream &stream)
    {

        if (using_stream != &stream)
        {
            stream_index = -1;
            using_stream = &stream;
        }

    start_parse:
        Token *token = next_token();

        if (token == NULL)
            return NULL;

        switch (token->type)
        {
        case TK_SEMICOLON:
            parse(stream);
        
        case TK_CNUMBER:
        case TK_CSTR:
            return parse_simple_operation(token);
        
        default:
            return NULL;
        }
    }






} // namespace FlyLisp





