









#ifndef __PARSER_HEAD__
#define __PARSER_HEAD__


#include "token.hpp"
#include "ast.hpp"
#include <stdint.h>
#include <vector>
#include <stack>



namespace FlyLisp
{
    
    static ::std::vector<Node*> parse_tree;
    static ::std::stack<Node*> parse_stack;
    static ::std::stack<Token*> back_trace;     //回溯

    static TokenStream *using_stream;
    static uint64_t stream_index = 0;
    static uint64_t stream_size = 0;


    void plus(Node *tree);              // +
    void minus(Node *tree);             // -
    void multiply(Node *tree);          // *
    void divide(Node *tree);            // /

    void less(Node *tree);              // <
    void greater(Node *tree);           // >
    void equal(Node *tree);             // ==

    void less_equal(Node *tree);        // <=
    void greater_equal(Node *tree);     // >=
    void not_equal(Node *tree);         // !=


    Node *parse_plus(Token *current);             // +
    Node *parse_minus(Token *current);             // -
    Node *parse_multiply(Token *current);          // *
    Node *parse_divide(Token *current);            // /

    Node *parse_less(Token *current);              // <
    Node *parse_greater(Token *current);           // >
    Node *parse_equal(Token *current);             // ==

    Node *parse_less_equal(Token *current);        // <=
    Node *parse_greater_equal(Token *current);     // >=
    Node *parse_not_equal(Token *current);         // !=

    
    
    Token *next_token();
    Node *parse_list(Token *current);
    Node *parse(TokenStream *stream);
    
} // namespace FlyLisp














#endif


