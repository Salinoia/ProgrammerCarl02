#include<string>

using std::string;
class Solution {
public:
    // 计算 next 数组的函数
    void getNextArray(int* next, const string& s) {
        int j = 0;
        // 从第二个字符开始遍历字符串 s
        for (int i = 1; i < s.size(); ++i) {
            // 如果当前字符 s[i] 与 s[j] 相等，则将 j 加 1
            if (s[i] == s[j]) {
                ++j;
            }
            // 当 j 大于 0 且 s[j] 与 s[i] 不相等时，进行回溯操作
            while (j > 0 && s[j]!= s[i]) {
                j = next[j - 1];
            }
            // 将当前位置的 next 值更新为 j
            next[i] = j;
        }
    }
    // 匹配字符串的函数
    int matchString(string haystack, string needle) {
        // 创建一个与 haystack 大小相同的 next 数组
        int next[haystack.size()];
        int j = 0;
        // 初始化 next 数组的第一个元素为 0
        next[j] = 0;
        // 调用 getNextArray 函数计算 needle 的 next 数组
        getNextArray(&next[0], needle);
        // 遍历 haystack 字符串
        for (int i = 0; i < haystack.size(); ++i) {
            // 如果当前字符 haystack[i] 与 needle[j] 相等，将 j 加 1
            if (haystack[i] == needle[j]) {
                ++j;
            }
            // 当 j 大于 0 且 haystack[i] 与 needle[j] 不相等时，进行回溯操作
            while (j > 0 && haystack[i]!= needle[j]) {
                j = next[j - 1];
            }
            // 如果 j 等于 needle 的长度，说明找到匹配，返回相应的位置
            if (j == needle.size()) {
                return next[i - j + 1];
            }
        }
        // 未找到匹配，返回 -1
        return -1;
    }
    // 主函数，调用 matchString 进行字符串匹配
    int strStr(string haystack, string needle) {
        // 如果 needle 为空，返回 -1
        if (needle.size() == 0) {
            return -1;
        }
        // 调用 matchString 进行匹配
        return matchString(haystack, needle);
    }
};