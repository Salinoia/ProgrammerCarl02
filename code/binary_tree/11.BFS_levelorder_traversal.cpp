#include <vector>
#include <queue>
#include <algorithm>
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
    void orderRecursion(TreeNode* currrent, vector<vector<int>>& result, int depth){// 思考为何此处递归函数需要额外参数depth
        if(currrent == nullptr) return;

        // 如果当前层还没有被访问过，插入一个新的空数组
        if(depth >= result.size()) result.push_back(vector<int>{});

        // 将当前节点的值加入对应层的数组
        result[depth].push_back(currrent->val);

        // 递归遍历左子树和右子树，深度加 1
        orderRecursion(currrent->left, result, depth + 1);
        orderRecursion(currrent->right, result, depth + 1);
    }
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        int depth = 0;
        orderRecursion(root, res, depth);
        std::reverse(res.begin(), res.end());
        return res;
    }
    
};

