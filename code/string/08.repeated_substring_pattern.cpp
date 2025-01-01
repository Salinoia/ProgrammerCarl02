#include<string>
#include<vector>
#include<iostream>
#include<array>

using std::string;
class Solution {
public:
    void getNext(int* next, const string& s){
        int j = - 1;
        next[0] = -1;
        for(int i = 0; i < s.size(); ++i){
            while(j >= 0 && s[i] != s[j + 1]){
                j = next[j];
            }
            if(s[i] == s[j + 1]){
                ++j;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0){
            return false;
        }
        int length = s.size();
        std::vector<int> next(length);
        getNext(next.data(), s);
        if(next[length - 1] != -1 && (length % (length - next[length - 1] - 1)) == 0){
            return true;
        }
        else return false;
    }
};