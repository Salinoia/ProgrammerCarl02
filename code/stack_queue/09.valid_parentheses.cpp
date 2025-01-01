#include<string>
#include<stack>
#include<unordered_map>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> cache_data;
        std::unordered_map<char, char> mapping ={
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        if(s.size() % 2){
            return false;// 奇数位字符串，必然不可能是合法的
        }
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch =='{'){
                cache_data.push(ch);
            }
            else if(ch == ')' || ch == ']' || ch == '}'){
                if(cache_data.empty()){
                    return false;
                }
                if(cache_data.top() == mapping[ch])
                    cache_data.pop();
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return cache_data.empty();
    }
};