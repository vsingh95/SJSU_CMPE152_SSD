/**
 * <h1>IfExecutor</h1>
 *
 * <p>Execute an WHEN statement.</p>
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

   // Get the WHEN node's branch_children.
    vector<ICodeNode *> branch_children = node->get_children();
    
    for(int i = 0 ; i < branch_children.size(); i++)
    {
        ICodeNode *wb_node = branch_children[i];
        vector<ICodeNode *> children = wb_node->get_children();
        ICodeNode *expr_node = children.size() != 1 ? children[0] : nullptr;
        ICodeNode *stmt_node = children.size() != 1 ? children[1] : children[0];
        
        ExpressionExecutor expression_executor(this);
        StatementExecutor statement_executor(this);

        // Evaluate the expression to determine which statement to execute.
        if (expr_node == nullptr)
        {
            statement_executor.execute(stmt_node);
            break;
        }
        else
        {
            Object data_value = expression_executor.execute(expr_node);
            if (cast(data_value, bool))
            {
                statement_executor.execute(stmt_node);
                break;
            }
        }

        ++execution_count;  // count the WHEN statement itself
    }


    return Object();    // empty
}


}}}}  // namespace wci::backend::interpreter::executors
