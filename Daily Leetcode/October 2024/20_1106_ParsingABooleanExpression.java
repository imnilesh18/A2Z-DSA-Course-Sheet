/*
 * 1106. Parsing A Boolean Expression
 * 
 * A boolean expression is an expression that evaluates to either true or false.
 * It can be in one of the following shapes:
 * 't' that evaluates to true.
 * 'f' that evaluates to false.
 * '!(subExpr)' that evaluates to the logical NOT of the inner expression
 * subExpr.
 * '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of
 * the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 * '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of
 * the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 * Given a string expression that represents a boolean expression, return the
 * evaluation of that expression.
 * It is guaranteed that the given expression is valid and follows the given
 * rules.
 * 
 * Example 1:
 * Input: expression = "&(|(f))"
 * Output: false
 * Explanation:
 * First, evaluate |(f) --> f. The expression is now "&(f)".
 * Then, evaluate &(f) --> f. The expression is now "f".
 * Finally, return false.
 * 
 * Example 2:
 * Input: expression = "|(f,f,f,t)"
 * Output: true
 * Explanation: The evaluation of (false OR false OR false OR true) is true.
 * 
 * Example 3:
 * Input: expression = "!(&(f,t))"
 * Output: true
 * Explanation:
 * First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression
 * is now "!(f)".
 * Then, evaluate !(f) --> NOT false --> true. We return true.
 * 
 * Constraints:
 * 1 <= expression.length <= 2 * 10^4
 * expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f',
 * and ','.
 */

// T.C : O(n)
// S.C : O(n)

class Solution {
    char solveOp(char op, List<Character> values) {
        if (op == '!') {
            return values.get(0) == 't' ? 'f' : 't';
        }

        if (op == '&') {
            return values.stream().anyMatch(ch -> ch == 'f') ? 'f' : 't';
        }

        if (op == '|') {
            return values.stream().anyMatch(ch -> ch == 't') ? 't' : 'f';
        }

        return 't'; // Unreachable
    }

    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();
        int n = expression.length();

        for (int i = 0; i < n; i++) {
            char ch = expression.charAt(i);
            if (ch == ',') {
                continue;
            }

            if (ch == ')') {
                List<Character> values = new ArrayList<>();
                while (st.peek() != '(') {
                    values.add(st.pop());
                }
                st.pop();
                char op = st.pop();
                st.push(solveOp(op, values));
            } else {
                st.push(ch);
            }
        }
        return st.peek() == 't';
    }
}

// Code with comments for better understanding:
// T.C : O(n)
// S.C : O(n)

class Solution {
    // Helper method to evaluate the operation
    // 'op' can be '!', '&', or '|'
    // 'values' contains the sub-expressions to be evaluated
    char solveOp(char op, List<Character> values) {
        // If op is '!', return the NOT of the first value
        if (op == '!') {
            return values.get(0) == 't' ? 'f' : 't';
        }

        // If op is '&', return 'f' if any of the values is 'f' (AND operation)
        if (op == '&') {
            return values.stream().anyMatch(ch -> ch == 'f') ? 'f' : 't';
        }

        // If op is '|', return 't' if any of the values is 't' (OR operation)
        if (op == '|') {
            return values.stream().anyMatch(ch -> ch == 't') ? 't' : 'f';
        }

        return 't'; // Unreachable, but added for safety
    }

    public boolean parseBoolExpr(String expression) {
        // Stack to keep track of the current expression being evaluated
        Stack<Character> st = new Stack<>();
        int n = expression.length();

        // Iterate through the expression
        for (int i = 0; i < n; i++) {
            char ch = expression.charAt(i);

            // Skip commas as they are just separators
            if (ch == ',') {
                continue;
            }

            // If closing parenthesis, start evaluating the current sub-expression
            if (ch == ')') {
                List<Character> values = new ArrayList<>();
                // Collect all values inside the parenthesis
                while (st.peek() != '(') {
                    values.add(st.pop());
                }
                // Pop the '(' from the stack
                st.pop();
                // Pop the operator before the '('
                char op = st.pop();
                // Push the result of the evaluated expression back onto the stack
                st.push(solveOp(op, values));
            } else {
                // For other characters (including '(', 't', 'f', and operators), push to the
                // stack
                st.push(ch);
            }
        }

        // The final result will be at the top of the stack
        return st.peek() == 't';
    }
}
