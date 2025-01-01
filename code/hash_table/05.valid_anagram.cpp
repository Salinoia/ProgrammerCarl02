#include<string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int hash_array[26] = {0};
        for(int i = 0; i < s.length(); ++i){
            hash_array[s[i] - 'a']++;// 仅记录二十六个字母出现的次数，无需在意具体是哪个字母
        }
        for(int i = 0; i < t.length(); ++i){
            hash_array[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; ++i){
            if(hash_array[i] != 0){
                return false;
            }
        }
        return true;
    }
};