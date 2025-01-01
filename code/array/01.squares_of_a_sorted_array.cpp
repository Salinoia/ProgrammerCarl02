#include<vector>
using std::vector;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 非空非递减数组
        // 无论哪种情况，最大值一定会出现在数组两侧，考虑双指针
        int index = nums.size() - 1;
        std::vector<int> res(nums.size());
        for(int i = 0, j = nums.size() - 1; i <=j;){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                res[index--] = nums[j] * nums[j];
                j--;
            }
            else{
                res[index--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};