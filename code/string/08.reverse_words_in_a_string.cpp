#include <string>
using std::string;

class Solution {
public:
    // 反转字符串从start到end位置的字符
    void myReverse(string& s, int start, int end) {
        while (start < end) { // 只要start小于end，就交换字符
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    // 去除字符串中的多余空格
    void removeExtraSpaces(string& s) {
        int slow_index = 0;  // 慢指针，指向新字符串的位置
        bool in_space = false;  // 用于标识当前是否在空格状态
        for (int fast_index = 0; fast_index < s.size(); ++fast_index) {
            if (s[fast_index] != ' ') {  // 遇到非空格字符
                if (in_space && slow_index > 0) {  // 如果之前遇到过空格且slow_index不为0
                    s[slow_index] = ' ';  // 添加一个空格来分隔单词
                    slow_index++;  // 移动慢指针
                }
                s[slow_index] = s[fast_index];  // 将当前字符放入新位置
                slow_index++;  // 慢指针向前移动
                in_space = false;  // 重置空格标志
            } else {
                in_space = true;  // 当前字符是空格，标记为空格状态
            }
        }
        s.resize(slow_index);  // 最后调整字符串的大小，去除多余空格
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);  // 去除多余空格
        myReverse(s, 0, s.size() - 1);  // 反转整个字符串

        int j = 0;  // 用于记录单词的起始位置
        for (int i = 0; i < s.size(); ++i) {
            // 如果遇到空格或到达字符串末尾（处理最后一个单词）
            if (s[i] == ' ' || i == s.size() - 1) {
                // 反转当前单词，注意处理最后一个单词时的边界
                myReverse(s, j, (i == s.size() - 1) ? i : i - 1);
                j = i + 1;  // 更新j为下一个单词的起始位置
            }
        }
        return s;
    }
};
