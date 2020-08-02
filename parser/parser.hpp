









#ifndef __PARSER_HEAD__
#define __PARSER_HEAD__


#include "token.hpp"
#include "ast.hpp"
#include <stdint.h>
#include <vector>
#include <stack>



namespace FlyLisp
{
    
    static ::std::vector<Node> parse_tree;
    static ::std::stack<Node> parse_stack;
    static ::std::stack<::std::string> back_trace;     //回溯

    static TokenStream *using_stream = NULL;
    static uint64_t stream_index = 0;


    void plus(Token *current);          // +
    void minus(Token *current);         // -
    void multiply(Token *current);      // *
    void divide(Token *current);        // /

    void less(Token *current);          // <
    void greater(Token *current);       // >
    void equal(Token *current);         // ==

    void less_equal(Token *current);        // <=
    void greater_equal(Token *current);     // >=
    void not_equal(Token *current);         // !=

    
    
    Token *next_token();
    Node *parse_simple_operation(Token *current);   //请送个字面量过来
    Node *parse(TokenStream &stream);
    
} // namespace FlyLisp














#endif


