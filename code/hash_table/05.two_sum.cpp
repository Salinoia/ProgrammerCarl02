#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
public:
    // 主函数，输入数组 nums 和目标值 target，返回符合条件的两个索引
    vector<int> twoSum(vector<int>& nums, int target) {
        // 创建一个哈希表，存储已遍历的数字及其索引
        std::unordered_map<int, int> u_map;
        
        // 遍历数组 nums
        for (int i = 0; i < nums.size(); ++i) {
            // 对于当前元素 nums[i]，检查是否有一个数在哈希表中，
            // 使得这个数与 nums[i] 相加等于目标值 target。
            auto iter = u_map.find(target - nums[i]);  // 查找与当前元素配对的数
            if (iter != u_map.end()) {
                // 如果找到了对应的数，返回该数的索引和当前数的索引
                return {iter->second, i};  // iter->second 是配对数的索引，i 是当前数的索引
            }
            
            // 如果没找到配对数，将当前元素 nums[i] 和其索引 i 存入哈希表
            u_map.insert(std::pair<int, int>(nums[i], i));
        }
        
        // 如果遍历完整个数组仍未找到符合条件的两个数，返回空数组
        return {};
    }
};
