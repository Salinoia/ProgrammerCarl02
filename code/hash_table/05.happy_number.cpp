#include<unordered_set>

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        std::unordered_set<int> u_set;
        while(1){
            int sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(u_set.find(sum) != u_set.end()){
                return false;// 找到重复元素
            }
            else{
                u_set.insert(sum);
            }
            n = sum;// 更新n 的值
        }
    }
};