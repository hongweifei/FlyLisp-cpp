






#include "ast.hpp"




namespace FlyLisp
{

    /*
    void ast_map_init()
    {
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("+", TK_PLUS));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("-", TK_MINUS));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("*", TK_STAR));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("/", TK_DIVIDE));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("%", TK_MOD));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("==", TK_EQ));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("!=", TK_NEQ));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("<", TK_LT));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("<=", TK_LEQ));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (">", TK_GT));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (">=", TK_GEQ));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("=", TK_ASSIGN));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("->", TK_POINTSTO));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (".", TK_DOT));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("&", TK_AND));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("|", TK_OR));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (":", TK_THAN));

        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("!", TK_FALSE));

        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("(", TK_OPENPA));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (")", TK_CLOSEPA));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("[", TK_OPENBR));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("]", TK_CLOSEBR));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("{", TK_BEGIN));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("}", TK_END));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (";", TK_SEMICOLON));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type (",", TK_COMMA));
        terminal_symbol_map.insert(::std::map<::std::string, TokenType>::value_type ("...", TK_ELLIPSIS));
    }
    */


    const char *stringify_node_type(NodeType type)
    {
        switch (type)
        {
        case NODE_TYPE_UNKOWN:
            return "unkown";

        case NODE_TYPE_UNARY:
            return "unary";

        case NODE_TYPE_BINARY:
            return "binary";
        
        default:
            return "unkown";;
        }
    }


    Node::Node(::std::string name,NodeType type,Token *token,Node *next,Node *left,Node *right)
    {
        this->name = name;
        this->type = type;
        this->token = token;
        this->next = next;
        this->left = left;
        this->right = right;
    }
    
    Node::~Node()
    {

    }


    void Node::print(int deepth)
    {
        if (this == NULL)
            return;

        for (int i = 0;i < deepth;i++)
            printf("\t");

        printf("Node %s:",stringify_node_type(this->type));
        this->token->print();

        for (int i = 0;i < deepth;i++)
            printf("\t");
        printf("{\n");

        int child_deepth = deepth + 1;
        this->next->print(child_deepth);
        this->left->print(child_deepth);
        this->right->print(child_deepth);

        for (int i = 0;i < deepth;i++)
            printf("\t");
        printf("}\n");
    }


} // namespace FlyLisp




    
