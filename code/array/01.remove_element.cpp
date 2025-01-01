#include<vector>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // 非空判决
        if(!(nums.size()))
        return 0;

        int slowFlag = 0;
        for(int fastFlag = 0; fastFlag < nums.size(); ++fastFlag){
            if(nums[fastFlag] != val){// 快指针一直后移
                nums[slowFlag] = nums[fastFlag];// 慢指针存储不等元素覆盖直“新”数组
                ++slowFlag;
            }
        }
        return slowFlag;
    }
};