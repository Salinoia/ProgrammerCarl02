#include <vector>
#include <queue>
#include <algorithm>
#include <numeric> // for std::accumulate
#include <limits>
using std::vector;
using std::queue;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class leverorderTraversal
{
public:
    void orderRecursion(TreeNode* current, vector<vector<int>>& result, int depth){// 思考为何此处递归函数需要额外参数depth
        if(current == nullptr) return;

        // 如果当前层还没有被访问过，插入一个新的空数组
        if(depth >= result.size()) result.push_back(vector<int>{});

        // 将当前节点的值加入对应层的数组
        result[depth].push_back(current->val);

        // 递归遍历左子树和右子树，深度加 1
        orderRecursion(current->left, result, depth + 1);
        orderRecursion(current->right, result, depth + 1);
    }
    // leetcode 102
    vector<vector<int>> levelOrderRecursion(TreeNode* root){
        vector<vector<int>> res;
        int depth = 0;
        orderRecursion(root, res, depth);
        return res;
    }
    vector<vector<int>> levelOrderIteration(TreeNode* root){
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
    // leetcode 107
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        int depth = 0;
        orderRecursion(root, res, depth);
        std::reverse(res.begin(), res.end());
        return res;
    }
    // leetcode 199
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> vecs;
        int depth = 0;
        orderRecursion(root, vecs, depth);
        vector<int> res(depth);
        for(auto& vec : vecs){
            res.push_back(vec.back());
        }
        return res;
    }
  
    // leetcode 637
    template<typename T> 
    double average(const std::vector<T>& data){
        if(data.empty()) return 0.000;
        long long sum = std::accumulate(data.begin(), data.end(), 0LL);
        return static_cast<double>(sum) / data.size();
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> vecs;
        int depth = 0;
        orderRecursion(root, vecs, depth);
        vector<double> res(depth);
        for(auto& vec : vecs){
            res.push_back(average(vec));
        }
        return res;
    }

    // leetcode 637
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};  // 为空树时直接返回

        vector<double> res;   // 用于存储每层的平均值
        queue<TreeNode*> q;   // 队列用于 BFS 层序遍历
        q.push(root);         // 将根节点入队

        while (!q.empty()) {
            int levelSize = q.size();   // 当前层的节点数量
            long long levelSum = 0;     // 当前层节点值的累加和
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();  // 取出队列中的节点
                q.pop();                     // 弹出该节点
                levelSum += node->val;       // 累加当前节点的值

                // 将左右子节点入队
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // 当前层的平均值，加入结果中
            res.push_back(static_cast<double>(levelSum) / levelSize);
        }

        return res;  // 返回每层的平均值
    }

    // leetcode 429
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return{};
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            vec.reserve(size);
            for(int i = 0; i < size; ++i){
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for(auto& child : node->children){
                    if(child != nullptr) 
                    que.push(child);
                }
            }
            res.push_back(std::move(vec));
        }
        return res;
    }

    // leetcode 515
    void maxValueTraversal(TreeNode* node, vector<int>& maxValues, int depth){
        if(node == nullptr) return;

        if(depth >= maxValues.size()){
            maxValues.push_back(node->val);
        }
        else{
            maxValues[depth] = std::max(maxValues[depth], node->val);
        }

        if(node->left) maxValueTraversal(node->left, maxValues, depth + 1);
        if(node->right) maxValueTraversal(node->right, maxValues, depth + 1);
        
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxValues;
        maxValueTraversal(root, maxValues, 0);
        return maxValues;
    }

    //leetcode 515
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> maxValues;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            int maxValue = std::numeric_limits<int>::min();
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                maxValue = std::max(maxValue, node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            maxValues.push_back(maxValue);
        }
        return maxValues;
    }
};
class Part2{
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };
    // leetcode 116
    Node* connect(Node* root) {
        // 如果根节点为空，直接返回空指针
        if (root == nullptr) return nullptr;
        queue<Node*> que;
        que.push(root); 

        while (!que.empty()) {
            int size = que.size(); // 当前层的节点数量
            Node* prev = nullptr;  // 前一个节点，用于连接 'next' 指针

            // 遍历当前层的所有节点
            for (int i = 0; i < size; ++i) {
                Node* current = que.front(); // 获取队首节点
                que.pop();                    // 将队首节点弹出

                // 如果 prev 不为空，说明这是当前层的第二个及以后的节点
                if (prev != nullptr) {
                    prev->next = current; // 将前一个节点的 next 指针指向当前节点
                }

                // 更新 prev 为当前节点，以便下一个节点连接时使用
                prev = current;

                // 将当前节点的左子节点入队（如果存在）
                if (current->left) {
                    que.push(current->left);
                }

                // 将当前节点的右子节点入队（如果存在）
                if (current->right) {
                    que.push(current->right);
                }
            }

            // 遍历完当前层后，最后一个节点的 next 已默认设置为 nullptr
            // 根据 Node 的构造函数，next 已初始化为 nullptr
            // 如果需要显式设置，可以取消注释以下行：
            if (prev != nullptr) prev->next = nullptr;
        }

        // 返回修改后的根节点
        return root;
    }
};

