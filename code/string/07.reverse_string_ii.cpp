#include<string>
#include<algorithm>
using std::string;
class Solution {
public:
    void myReverse(string& s, int start_index, int end_index){// 左闭右闭
        for(int i = start_index, j = end_index; i < j; ++i, --j){
            std::swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        int length = s.length(), position = 0;
        while(position < length){
            // if(position + k <length) std::reverse(s.begin() + position, s.begin() + position + k);
            // else std::reverse(s.begin() + position, s.end());
            // position += 2 * k;
            if(position + k < length) myReverse(s, position, position + k - 1);
            else myReverse(s, position, length - 1);
            position += 2 * k;
        }
        return s;
    }
};