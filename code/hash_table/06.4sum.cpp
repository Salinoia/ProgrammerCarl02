#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for(int j = 0; j < nums.size(); ++j){
            // 剪枝：当前元素已经大于target，找不到有效四元组
            if(nums[j] > target && nums[j] >= 0) break;// 由于数组已排序，如果当前元素是非负数，进一步的四元组和一定会超过 target，提前终止。
            if(j > 0 && nums[j] == nums[j - 1]) continue;// 去重

            for(int i = j + 1; i < nums.size(); ++i){
                //剪枝：考虑此时两个数相加已经大于sum，可退出寻找
                if(nums[j] + nums[i] > 0 && nums[j] + nums[i] > target) break;
                if(i > j + 1 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while(right > left){
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        result.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    else if(sum > target){
                        right--;
                    }
                    else left++;
                }
            }
        }
        return result;
    }
};