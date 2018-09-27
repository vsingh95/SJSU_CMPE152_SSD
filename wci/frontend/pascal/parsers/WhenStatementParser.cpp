/**
 * <h1>WhenStatementParser</h1>
 *
 * <p>Parse a Pascal WHEN statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

bool WhenStatementParser::INITIALIZED = false;

// set<PascalTokenType> WhenStatementParser::CONSTANT_START_SET =
// {
//     PT_IDENTIFIER, PT_INTEGER, PT_PLUS, PT_MINUS, PT_STRING,
// };

set<PascalTokenType> WhenStatementParser::ARROW_SET;

void WhenStatementParser::initialize()
{
    if (INITIALIZED) return;

    ARROW_SET = StatementParser::STMT_START_SET;
    ARROW_SET.insert(PascalTokenType::THEN);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        ARROW_SET.insert(*it);
    }

    INITIALIZED = true;
}

WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
{
    token = next_token(token);  // consume the WHEN

    // Create an WHEN node.
    ICodeNode *when_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN);


    while ((token != nullptr) &&
           (token->get_type() != (TokenType) PT_OTHERWISE))
    {
        
        when_node->add_child(parse_branch(token));


        token = current_token();
        TokenType token_type = token->get_type();

        // Look for the semicolon between WHEN branches.
        if (token_type == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);  // consume the ;
        }

        // If at the start of the next constant, then missing a semicolon.
        else
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }

    }
        
    // Look for an OTHERWISE.
    if (token->get_type() == (TokenType) PT_OTHERWISE)
    {
        token = next_token(token);  // consume the OTHERWISE
        TokenType token_type = token->get_type();

        // Parse the OTHERWISE statement.
        // The WHEN node adopts the statement subtree as its third child.
        token = next_token(token);
        token_type = token->get_type();

        // Synchronize at the ARROW.
        token = synchronize(ARROW_SET);
        if (token->get_type() == (TokenType) PT_ARROW)
        {
            token = next_token(token);  // consume the ARROW
        }
        // else {
        //     error_handler.flag(token, MISSING_THEN, this);
        // } // Parse the ARROW statement.
        
        StatementParser statement_parser(this);
        when_node->add_child(statement_parser.parse_statement(token));
    }



    // Look for the END token.
    if (token->get_type() == (TokenType) PT_END)
    {
        token = next_token(token);  // consume END
    }
    else
    {
        error_handler.flag(token, MISSING_END, this);
    }
    
    return when_node;
}

ICodeNode *WhenStatementParser::parse_branch(Token *token)
    throw (string)
{
    // Create an SELECT_BRANCH node and a SELECT_CONSTANTS node.
    // The SELECT_BRANCH node adopts the SELECT_CONSTANTS node as its
    // first child.
    ICodeNode *branch_node =
            ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_SELECT_BRANCH);
    
    // Parse the expression.
    // The WHEN node adopts the expression subtree as its first child.
    ExpressionParser expression_parser(this);
    branch_node->add_child(expression_parser.parse_statement(token));
    
    token = next_token(token);
    TokenType token_type = token->get_type();

    // Synchronize at the ARROW.
    token = synchronize(ARROW_SET);
    if (token->get_type() == (TokenType) PT_ARROW)
    {
        token = next_token(token);  // consume the ARROW
    }
    // else {
    //     error_handler.flag(token, MISSING_THEN, this);
    // } // Parse the ARROW statement.
    
    // The WHEN node adopts the statement subtree as its second child.
    
    StatementParser statement_parser(this);
    branch_node->add_child(statement_parser.parse_statement(token));    

    return branch_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
