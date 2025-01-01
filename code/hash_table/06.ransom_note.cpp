#include<string>
using std::string;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 由题干可知，字符串的字母不可重复且均用小写字母构成，那么需要记录字符出现的次数以及出现的频率
        int hash_table[26] = {0};
        if(ransomNote.size() > magazine.size()){
            return false;
        }
        for(int i = 0; i < magazine.size(); ++i){
            hash_table[magazine[i] - 'a']++;
        }
        for(int i = 0; i < ransomNote.size(); ++i){
            hash_table[ransomNote[i] - 'a']--;
            if(hash_table[ransomNote[i] - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};