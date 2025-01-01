#include<vector>
using std::vector;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x_start_index = 0;
        int y_start_index = 0;
        int x_end_index = n - 1;
        int y_end_index = n - 1;
        int value = 1;
        /*
            左闭右开区间环绕
            则围绕中心点四次循环，分别视为：
            [(x_start_index, y_start_index), (x_end_index, y_start_index)) 
            [(x_end_index, y_start_index), (x_end_index, y_end_index))
            [(x_end_index, y_end_index), (x_start_index, y_end_index))
            [(x_start_index, y_end_index), (x_start_index, y_start_index))
            若n为奇数，则中心存在一个单独的数需要最后循环结束后处理，偶数则不需要
        */
        int loopCount = n / 2;
        while(loopCount--){
            for(int i = x_start_index; i < x_end_index; ++i) res[y_start_index][i] = value++;
            for(int j = y_start_index; j < y_end_index; ++j) res[j][x_end_index] = value++;
            for(int i = x_end_index; i > x_start_index; --i) res[y_end_index][i] = value++;
            for(int j = y_end_index; j > y_start_index; --j) res[j][x_start_index] = value++;
            x_start_index++;
            y_start_index++;
            x_end_index--;
            y_end_index--;
        }
        if(n % 2) res[n / 2][n / 2] = n * n;
        return res;
    }
};