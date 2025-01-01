#include<vector>
#include<unordered_map>
#include<queue>
using std::vector;
using std::pair;

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        std::unordered_map<int, int> freqMap;
        for(int num : nums){
            freqMap[num]++;
        }
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pri_que;
        for(auto& [num, freq] : freqMap){
            pri_que.push(std::make_pair(num, freq));
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        vector<int> res(k);
        for(int i = k - 1; i >= 0; i--){
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
private:
    class Compare{
    public:
    bool operator()(const pair<int, int>& lhs,const pair<int, int> & rhs ){
            return lhs.second > rhs.second;// 小顶堆排序，低频率优先
        }
    };
};

// // 桶排序
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         std::unordered_map<int, int> freqMap;
//         for(int num : nums){
//             freqMap[num]++; // 使用 operator[] 自动插入新键
//             // freqMap.at(num)++; // 不合理，会抛出异常
//         }
//         int n = nums.size();

//         vector<vector<int>> buckets(n + 1, vector<int>());
//         for(auto& [num, freq] : freqMap){
//             buckets[freq].emplace_back(num);
//         }

//         vector<int> res;

//         for(int i = n; i >= 0 && res.size() < k; --i){
//             for(int num : buckets[i]){
//                 res.emplace_back(num);
//             }
//             if(res.size() == k){
//                 return res;
//             }
//         }
//     return res;
//     }
// };