#include<string>
#include<vector>
using std::string;
class Solution{
public:
    // 使用初始化为 -1 的情况进行初始化
    void getNextArray(int * next, const string& s){
        int j = -1;
        next[0] = -1;
        for(int i = 1; i < s.size(); ++i){
            while(j != -1 && s[i] != s[j + 1]){
                j = next[j];
            }
            if(s[i] == s[j + 1]){
                ++j;
            }
            next[i] = j;
        }
    }
    // 主函数，调用 matchString 进行字符串匹配
    int strStr(string haystack, string needle) {
        // 如果 needle 为空，返回 -1
        if (needle.size() == 0) {
            return -1;
        }
        std::vector<int> next(needle.size());
        getNextArray(next.data(), needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); ++i){
            while(j != -1 && haystack[i] != needle[j + 1]){
                j = next[j + 1];
            }
            if(haystack[i] == needle[j + 1]){
                ++j;
            }
            if(j == needle.size() - 1){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};