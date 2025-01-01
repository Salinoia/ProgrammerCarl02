#include <vector>
#include <deque>

using std::vector;
using std::deque;

class Solution {
public:
    // 计算每个滑动窗口的最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // 存储结果

        // 边界条件检查
        if(nums.empty() || k <= 0) return result;
        if(k == 1) return nums; // 每个元素即为最大值

        MonotonicQueue mq; // 初始化单调队列

        // for(int i = 0; i < k; ++i){
        //     mq.push(nums[i]);
        // }
        // result.emplace_back(mq.getMaxVal());

        // for(int i = k; i < nums.size(); ++i){
        //     mq.pop(nums[i - k]);
        //     mq.push(nums[i]);
        //     result.emplace_back(mq.getMaxVal());
        // }
        // 遍历数组
        for(int i = 0; i < nums.size(); ++i){
            if(i >= k){
                mq.pop(nums[i - k]); // 移除窗口外元素
            }
            mq.push(nums[i]); // 添加新元素

            if(i >= k - 1){
                result.emplace_back(mq.getMaxVal()); // 记录当前最大值
            }
        }
        return result;
    }

private:
    // 单调队列，维护递减顺序
    class MonotonicQueue {
    public:
        // 移除队列前端元素若与给定值相同
        void pop(int val){
            if(!que.empty() && val == que.front()){
                que.pop_front();
            }
        }

        // 添加新元素并保持队列递减
        void push(int val){
            while(!que.empty() && val > que.back()){
                que.pop_back(); // 移除较小元素
            }
            que.push_back(val);
        }

        // 获取当前最大值
        int getMaxVal() const {
            return que.front();
        }

    private:
        deque<int> que; // 双端队列
    };
};
