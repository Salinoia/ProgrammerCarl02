#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        // 排序，保证去重方便
        std::sort(nums.begin(), nums.end());
        // 遍历数组
        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前数字大于0，则不可能再有三元组和为0，直接返回
            if (nums[i] > 0) {
                return result;
            }
            // 跳过重复的元素，避免计算重复的三元组
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 双指针
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    // 找到一个三元组，加入结果
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重：跳过重复的左指针
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // 去重：跳过重复的右指针
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    // 更新指针
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++; // 需要增加和，左指针右移
                } else {
                    right--; // 需要减少和，右指针左移
                }
            }
        }
        return result; // 遍历完成后返回结果
    }
};
