




#include "parser.hpp"
#include <iostream>



namespace FlyLisp
{

    void plus(Node *tree)
    {
        //back_trace.push(type_map[TK_PLUS]);
    }

    void minus(Node *tree)
    {
        //back_trace.push(type_map[TK_MINUS]);
    }

    void multiply(Node *tree)
    {
        //back_trace.push(type_map[TK_STAR]);
    }

    void divide(Node *tree)
    {
        //back_trace.push(type_map[TK_DIVIDE]);
    }

    void less(Node *tree)
    {
        //back_trace.push(type_map[TK_LT]);
    }

    void greater(Node *tree)
    {
        //back_trace.push(type_map[TK_GT]);
    }

    void equal(Node *tree)
    {
        //back_trace.push(type_map[TK_EQ]);
    }

    void less_equal(Node *tree)
    {
        //back_trace.push(type_map[TK_LEQ]);
    }

    void greater_equal(Node *tree)
    {
        //back_trace.push(type_map[TK_GEQ]);
    }

    void not_equal(Node *tree)
    {
        //back_trace.push(type_map[TK_NEQ]);
    }



    Node *parse_plus(Token *current)
    {
        back_trace.push(current);

        Node *tree = new Node(current->value,NODE_TYPE_BINARY,current);
        ::std::vector<Token*> tokens;

        while (back_trace.top()->type != TK_END)
        {
            parse_list(current);
        }

        Token *token = back_trace.top();
        back_trace.pop();
        while (token->type != TK_PLUS)
        {
            tokens.push_back(token);
            Token *token = back_trace.top();
            back_trace.pop();
        }
        delete token;

        int token_number = tokens.size();
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i]->type != tokens[0]->type)
            {
                printf("error:token类型错误:\n\t");
                token->print();
                return NULL;
            }
        }

        //tree->left = new Node("字面量",NODE_TYPE_UNARY,tokens[0]);
        //tree->right = new Node("+",NODE_TYPE_BINARY,new Token(TK_PLUS,"+",0,0));
        
        
        if (token_number == 0)
        {
            tree->left = new Node("0",NODE_TYPE_UNARY,new Token(TK_CNUMBER,"0",0,0));
            tree->right = new Node("0",NODE_TYPE_UNARY,new Token(TK_CNUMBER,"0",0,0));
        }
        else if (token_number == 1)
        {
            tree->left = new Node("0",NODE_TYPE_UNARY,tokens[0]);
            tree->right = new Node("0",NODE_TYPE_UNARY,new Token(TK_CNUMBER,"0",0,0));
        }
        else if(token_number == 2)
        {
            tree->left = new Node("0",NODE_TYPE_UNARY,tokens[0]);
            tree->right = new Node("0",NODE_TYPE_UNARY,tokens[1]);
        }
        else
        {
            // + 号数量为 number 数量 - 1
            Node *right = tree;
            for (size_t i = 0; i < token_number - 2; i++)
            {
                Node *right_right = new Node("+",NODE_TYPE_BINARY,current);
                Node *right_left = new Node("number",NODE_TYPE_UNARY,tokens[i]);
                right->right = right_right;
                right->left = right_left;
                right = right->right;
            }

            right->left = new Node("number",NODE_TYPE_UNARY,tokens[token_number - 2]);
            right->right = new Node("number",NODE_TYPE_UNARY,tokens[token_number - 1]);
        }


        if (tree->left != NULL)
            return tree;
        return NULL;
    }


    void parse_minus(Token *current)
    {

    }


    void parse_multiply(Token *current)
    {

    }

    void parse_divide(Token *current)
    {

    }

    void parse_less(Token *current)
    {

    }

    void parse_greater(Token *current)
    {

    }

    void parse_equal(Token *current)
    {

    }

    void parse_less_equal(Token *current)
    {

    }

    void parse_greater_equal(Token *current)
    {

    }

    void parse_not_equal(Token *current)
    {

    }


    
    Token *next_token()
    {
        //return stream[stream_index++];
        stream_index++;

        if (stream_index < stream_size)
        {
            try
            {
                return using_stream->at(stream_index);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        
        return NULL;
    }



    Node *parse_list(Token *current)
    {
        Token *next = next_token();
        if (next == NULL)
            return NULL;
        /*
        switch (next->type)
        {
        case TK_NONE:

        /**符号* /
        case TK_THAN:       // :
        case TK_POINTSTO:   // ->
        case TK_AND:        // &
        case TK_OR:         // |
        case TK_FALSE:      // !
        case TK_ELLIPSIS:   // ...
        case TK_COMMA:      // ,
        case TK_SEMICOLON:  // ;

        /**关键字* /
        case KW_NULL:       // null
        case KW_VOID:       // void
        case KW_CHAR:       // char

        /**字面量* /
        case TK_CNUMBER:    
        case TK_CSTR:
            printf("error:错误的token:\n");
            next->print();
            return NULL;
        }
        */

        switch (next->type)
        {
        /**符号*/
        case TK_PLUS:       // +
            return parse_plus(next);
        case TK_MINUS:      // -
        case TK_STAR:       // *
        case TK_DIVIDE:     // /
        case TK_MOD:        // %
        case TK_EQ:         // ==
        case TK_NEQ:        // !=
        case TK_LT:         // <
        case TK_LEQ:        // <=
        case TK_GT:         // >
        case TK_GEQ:        // >=
        case TK_ASSIGN:     // =
            break;

        case TK_SEMICOLON:
            return parse_list(next);

    /**括号*/
        case TK_BEGIN:      // {
        case TK_OPENBR:     // [
            return parse_list(next);

        case TK_END:        // }
        case TK_CLOSEBR:    // ]
            back_trace.push(next);
            break;

    /**标识符，字面量*/
        case TK_IDENTIFIER:
            break;
        case TK_CNUMBER:
        case TK_CSTR:
            back_trace.push(next);
            break;

    /**关键字*/
        case KW_IMPORT:
        case KW_RETURN:
        case KW_IF:
        case KW_ELSE:
        case KW_SWITCH:
        case KW_WHILE:
        case KW_FOR:
        case KW_UNION:
        case KW_STRUCT:
        case KW_ENUM:
        case KW_CLASS:
            break;

        /**变量，函数声明*/
        case KW_VAR:
        case KW_FUNCTION:
            break;

        /**数字类型声明*/
        case KW_SHORT:
        case KW_INT:
        case KW_LONG:
        case KW_FLOAT:
        case KW_DOUBLE:
        case KW_NUMBER:
            break;

        /**字符串声明*/
        case KW_STRING:
            break;
        
        default:
            printf("error:错误的token:\n\t");
            next->print();
            break;
        }

        return NULL;
    }


    Node *parse(TokenStream *stream)
    {

        if (using_stream != stream)
        {
            stream_index = -1;
            stream_size = stream->size();
            using_stream = stream;
        }

    start_parse:
        Token *token = next_token();

        if (token == NULL)
            return NULL;

        switch (token->type)
        {
        case TK_SEMICOLON:
            return parse(stream);

        /**List*/
        case TK_BEGIN:
        case TK_OPENBR:
            return parse_list(token);
            break;
        
        case TK_CNUMBER:
        case TK_CSTR:
            return NULL;
        
        default:
            return NULL;
        }
    }






} // namespace FlyLisp





