#include<iostream>
#include<vector>

int main(){
    // 前缀和的方法，相当于数据重新利用
    int n, leftEdge, rightEdge;
    std::cin >> n;
    std::vector<int> inputArray(n);
    int prefix = 0;
    std::vector<int> prefixSum(n, 0);
    for(int i = 0; i < n; ++i){
        // std::cin >> inputArray[i];
        scanf("%d", &inputArray[i]);
        prefix += inputArray[i];
        prefixSum[i] = prefix;
    }
   

    // while(std::cin >> leftEdge >> rightEdge){
    //     if(leftEdge == 0) std::cout << prefixSum[rightEdge] << "\n";
    //     else std::cout << prefixSum[rightEdge] - prefixSum[leftEdge - 1] << "\n";
    // }
    while(~scanf("%d%d", &leftEdge, &rightEdge)){
        // int scanf(const char *format, ...);
        // scanf 在遇到 EOF 时返回 -1，此时表示没有更多数据可供读取，或者发生了严重的输入错误
        if(leftEdge == 0) printf("%d\n", prefixSum[rightEdge]);
        else printf("%d\n", prefixSum[rightEdge] - prefixSum[leftEdge - 1]);
    }    
}