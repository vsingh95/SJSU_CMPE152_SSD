/**
 * <h1>WhenStatementParser</h1>
 *
 * <p>Parse a Pascal When statement.</p>
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

set<PascalTokenType> WhenStatementParser::THEN_SET;
set<PascalTokenType> WhenStatementParser::OTHERWISE_SET;
set<PascalTokenType> WhenStatementParser::EQUALS_GREATER_SET;

void WhenStatementParser::initialize()
{

	if (INITIALIZED) return;

//
//	    EQUALS_GREATER_SET = CONSTANT_START_SET;
//	    EQUALS_GREATER_SET.insert(PT_EQUALS_GREATER);

//	    set<PascalTokenType>::iterator it;
//	    for (it  = StatementParser::STMT_START_SET.begin();
//	         it != StatementParser::STMT_START_SET.end();
//	         it++)
//	    {
//	        EQUALS_GREATER_SET.insert(*it);
//	    }
//	    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
//	         it != StatementParser::STMT_FOLLOW_SET.end();
//	         it++)
//	    {
//	        EQUALS_GREATER_SET.insert(*it);
//	        //COMMA_SET.insert(*it);
//	    }

	    INITIALIZED = true;



//    if (INITIALIZED) return;
//
//    THEN_SET = StatementParser::STMT_START_SET;
//    THEN_SET.insert(PascalTokenType::THEN);
//
//    set<PascalTokenType>::iterator it;
//    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
//         it != StatementParser::STMT_FOLLOW_SET.end();
//         it++)
//    {
//        THEN_SET.insert(*it);
//    }
//
//    INITIALIZED = true;
}

WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
{
	 token = next_token(token);  // consume the CASE

	    // Create a SELECT node.
	    ICodeNode *select_node =
	            ICodeFactory::create_icode_node((ICodeNodeType) NT_SELECT);

	    // Parse the CASE expression.
	    // The SELECT node adopts the expression subtree as its first child.
	    ExpressionParser expression_parser(this);
	    select_node->add_child(expression_parser.parse_statement(token));

	    // Synchronize at the OF.
//	    token = synchronize(OF_SET);
//	    if (token->get_type() == (TokenType) PT_OF)
//	    {
//	        token = next_token(token);  // consume the OF
//	    }
//	    else {
//	        error_handler.flag(token, MISSING_OF, this);
//	    }

	    // Set of CASE branch constants.
	    set<int> constant_set;

	    // Loop to parse each CASE branch until the END token
	    // or the end of the source file.
	    while ((token != nullptr) &&
	           (token->get_type() != (TokenType) PT_END))
	    {
	        // The SELECT node adopts the CASE branch subtree.
	        select_node->add_child(parse_branch(token, constant_set));

	        token = current_token();
	        TokenType token_type = token->get_type();

	        // Look for the semicolon between CASE branches.
//	        if (token_type == (TokenType) PT_SEMICOLON)
//	        {
//	            token = next_token(token);  // consume the ;
//	        }

	        // If at the start of the next constant, then missing a semicolon.
//	        else if (CONSTANT_START_SET.find((PascalTokenType) token_type)
//	                      != CONSTANT_START_SET.end())
//	        {
//	            error_handler.flag(token, MISSING_SEMICOLON, this);
//	        }
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

	    return select_node;








//    token = next_token(token);  // consume the When
//
//    // Create an When node.
//    ICodeNode *when_node =
//            ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN);
//
//
//    // Parse the expression.
//    // The WHEN node adopts the expression subtree as its first child.
//    ExpressionParser expression_parser(this);
//    when_node->add_child(expression_parser.parse_statement(token));
//
//    // Synchronize at the THEN.
//    token = synchronize(THEN_SET);
//    if (token->get_type() == (TokenType) PT_THEN)
//    {
//        token = next_token(token);  // consume the THEN
//    }
//    else {
//        error_handler.flag(token, MISSING_THEN, this);
//    }
//
//    // Parse the THEN statement.
//    // The when node adopts the statement subtree as its second child.
//    StatementParser statement_parser(this);
//    when_node->add_child(statement_parser.parse_statement(token));
//    token = current_token();
//
//    // Look for an ELSE.
//    if (token->get_type() == (TokenType) PT_ELSE)
//    {
//        token = next_token(token);  // consume the THEN
//
//        // Parse the ELSE statement.
//        // The when node adopts the statement subtree as its third child.
//        when_node->add_child(statement_parser.parse_statement(token));
//    }
//
//    return when_node;
}


ICodeNode *WhenStatementParser::parse_branch(Token *token,
                                             set<int>& constant_set)
    throw (string)
{
    // Create an SELECT_BRANCH node and a SELECT_CONSTANTS node.
    // The SELECT_BRANCH node adopts the SELECT_CONSTANTS node as its
    // first child.
    ICodeNode *branch_node =
            ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_SELECT_BRANCH);
    ICodeNode *constants_node =
            ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_SELECT_CONSTANTS);
    branch_node->add_child(constants_node);

    // Parse the list of CASE branch constants.
    // The SELECT_CONSTANTS node adopts each constant.
   // parse_constant_list(token, constants_node, constant_set);

    // Look for the : token.
    token = current_token();
    if (token->get_type() == (TokenType) PT_COLON)
    {
        token = next_token(token);  // consume the :
    }
    else
    {
        error_handler.flag(token, MISSING_COLON, this);
    }

    // Parse the CASE branch statement. The SELECT_BRANCH node adopts
    // the statement subtree as its second child.
    StatementParser statementParser(this);
    branch_node->add_child(statementParser.parse_statement(token));

    return branch_node;
}



}}}}  // namespace wci::frontend::pascal::parsers
