#include<unordered_set>
#include<vector>

using std::unordered_set;
using std::vector;
class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_set<int> result_set;
    //     unordered_set<int> num_set(nums1.begin(), nums1.end());
    //     for(int num:nums2){
    //         if(num_set.find(num) != num_set.end()){
    //             result_set.insert(num);
    //         }
    //     }
    //     return vector<int>(result_set.begin(), result_set.end());
    // }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result_set;
        int hash_table[1010] = {0};
        for(int num:nums1){
            hash_table[num] = 1;
        }
        for(int num:nums2){
            if(hash_table[num] == 1){
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};