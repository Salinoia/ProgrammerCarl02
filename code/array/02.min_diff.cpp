#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;

int main(){
    // 输入行列数 n 和 m 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> initial_data(n, vector<int>(m ,0));
    int total_sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            // 行主序存储
            cin >> initial_data[i][j];
            total_sum += initial_data[i][j];
        }
    }
    vector<int> row_sum(n, 0);
    vector<int> col_sum(m, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            row_sum[i] += initial_data[i][j];// 行主序读取
        }
    }
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            col_sum[j] += initial_data[i][j];// 列主序读取
        }
    }
    int min_diff = INT32_MAX;
    // 横向划分
    int top_sum = 0;
    for(int i = 0; i < n - 1; ++i){
        top_sum += row_sum[i];
        int bottom_sum = total_sum - top_sum;
        min_diff = std::min(min_diff, std::abs(top_sum - bottom_sum)); 
    }

    // 纵向划分
    int left_sum = 0;
    for(int j = 0; j < m - 1; ++j){
        left_sum += col_sum[j];
        int right_sum = total_sum - left_sum;
        min_diff = std::min(min_diff, std::abs(left_sum - right_sum));
    }
    cout << min_diff; 
}

