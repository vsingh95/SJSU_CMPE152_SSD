/**
 * <h1>IfExecutor</h1>
 *
 * <p>Execute an IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include <map>
#include "WhenExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

//JumpCache WhenExecutor::jump_cache;

WhenExecutor::WhenExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object WhenExecutor::execute(ICodeNode *node)
{

    // Get the WHEN node's children.
    vector<ICodeNode *> select_children = node->get_children();
    ICodeNode *expr_node = select_children[0];

    // Evaluate the WHEN expression.
    ExpressionExecutor expression_executor(this);
    Object select_value = expression_executor.execute(expr_node);

    // If there is a selection, execute the WHEN_BRANCH's statement.
    int key = instanceof(select_value, int)
                                    ? cast(select_value, int)
                                    : cast(select_value, string)[0];
    // ICodeNode *statement_node = (*jump_table)[key];
    // if (statement_node != nullptr)
    // {
    //     StatementExecutor statement_executor(this);
    //     statement_executor.execute(statement_node);
    // }

    // ++execution_count;  // count the WHEN statement itself
    // return Object();    // empty
}


}}}}  // namespace wci::backend::interpreter::executors
