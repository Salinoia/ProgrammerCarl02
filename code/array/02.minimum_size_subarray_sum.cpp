#include<vector>
#include<iostream>
#include<algorithm>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int length = INT32_MAX;// 存储满足条件的最短子数组的长度，初始化为INT32_MAX，表示尚未找到符合条件的子数组
        int slowPtr = 0;
        int sums = 0;
        for(int fastPtr = 0; fastPtr < nums.size(); ++fastPtr){
            sums += nums[fastPtr];
            while(sums >= target){
                int subLength = fastPtr - slowPtr + 1;
                length = std::min(length, subLength);
                sums -= nums[slowPtr++];
            }
        }
        return length == INT32_MAX ? 0 : length;
    }
};