#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    // 计算 nums_first 和 nums_second 中所有元素对的和，并保存到哈希表中
    void getTwoVecSum(unordered_map<int, int>& u_map, vector<int>& nums_first, vector<int>& nums_second) {
        for (int value1 : nums_first) {
            for (int value2 : nums_second) {
                u_map[value1 + value2]++;
            }
        }
    }

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> u_map;
        // 将 nums1 和 nums2 中所有元素对的和存入哈希表
        getTwoVecSum(u_map, nums1, nums2);

        int count = 0;
        // 遍历 nums3 和 nums4 中的所有元素对
        for (int value3 : nums3) {
            for (int value4 : nums4) {
                int target = -(value3 + value4);  // 计算目标和
                if (u_map.find(target) != u_map.end()) {
                    count += u_map[target];  // 如果找到了匹配的和，增加计数
                }
            }
        }

        return count;
    }
};
