#include<vector>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        // 已知数组升序排列且非空
        // 典型左闭右开判断
        int leftFlag = 0;
        int rightFlag = nums.size();
        while(leftFlag < rightFlag){
            // int middleFlag = leftFlag + (rightFlag - leftFlag) / 2;
            int middleFlag = leftFlag + ((rightFlag - leftFlag) >> 1);
            int middleFlag = leftFlag + ((rightFlag - 1 - leftFlag) >> 1);
            if(target < nums[middleFlag]){
                rightFlag = middleFlag; // 右开
            }
            else if(target > nums[middleFlag]){
                leftFlag = middleFlag + 1; // 左闭
            }
            else return middleFlag;
        }
        return -1;
    }
};