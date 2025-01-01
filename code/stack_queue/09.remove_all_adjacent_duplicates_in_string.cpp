#include<string>
#include<stack>
#include<algorithm>
using std::string;

class Solution {
public:
    string removeDuplicates(string s){
        std::string res_string;// 字符串模拟栈，降低空间复杂度
        for(char ch : s){
            if(res_string.empty() || res_string.back() != ch){
                res_string.push_back(ch);
            }
            else{
                res_string.pop_back();
            }
        }
        return res_string;

    }
    string removeDuplicates(string s) {
        std::stack<char> cache_data;
        for(char ch : s){
            if(cache_data.empty() || cache_data.top() != ch){
                cache_data.push(ch);
            }
            else{
               cache_data.pop(); 
            }
        }

        string res;
        while(!cache_data.empty()){
            res += cache_data.top();
            cache_data.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};