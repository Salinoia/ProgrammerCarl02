#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

using std::vector;
using std::string;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        
        for (const string& token : tokens) {
            // 判断当前 token 是否是运算符
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // 确保栈中有至少两个操作数
                int num1 = stack.top(); stack.pop();
                int num2 = stack.top(); stack.pop();
                // 根据运算符进行计算
                if (token == "+") stack.push(num2 + num1);
                else if (token == "-") stack.push(num2 - num1);
                else if (token == "*") stack.push(num2 * num1);
                else if (token == "/") stack.push(num2 / num1);
            } else {
                // 转换为整数并压入栈中
                stack.push(std::stoi(token));
            }
        }
        // 最终栈中只剩下一个结果
        int res = stack.top();
        stack.pop();
        return res;
    }
};
