



#ifndef __AST_HEAD__
#define __AST_HEAD__


#include "token.hpp"
#include <string>
#include <map>


namespace FlyLisp
{

    //static ::std::map<::std::string, TokenType> terminal_symbol_map;     //终止符map
    //void ast_map_init();


    // Basic types for a value
    typedef enum node_type : uint8_t
    {
        NODE_TYPE_UNKOWN,
        NODE_TYPE_UNARY,            //
        NODE_TYPE_BINARY,           //
    } NodeType;


    typedef union node_value
    {
        double number;
        ::std::string str;
    } NodeValue;
    
    const char *stringify_node_type(NodeType type);



    class Node
    {
    private:
        
        Token *token;

    public:
        ::std::string name;
        NodeType type;

        Node *next;             //unary  一元
        /**binary   二元*/
        Node *left;
        Node *right;

        Node(::std::string name,NodeType type,Token *token,Node *next = NULL,Node *left = NULL,Node *right = NULL);
        ~Node();

        void print(int deepth = 0);
    };
    

    






} // namespace FlyLisp






















#endif // __AST_HEAD__




