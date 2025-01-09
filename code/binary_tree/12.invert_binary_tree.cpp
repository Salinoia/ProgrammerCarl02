#include <algorithm>
struct TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    //1.确定递归参数以及返回值
    void preorderRecusion(TreeNode* node){
        if(node == nullptr) return;// 2.确定终止条件
        // 3.确定单层递归逻辑
        TreeNode* temp_node;
        temp_node = node->left;
        node->left = node->right;
        node->right = temp_node;// 中
        preorderRecusion(node->left);// 左
        preorderRecusion(node->right);// 右
    }

    void postorderRecusion(TreeNode* node){
        if(node == nullptr) return;
        postorderRecusion(node->left);// left
        postorderRecusion(node->right);// right
        std::swap(node->left, node->right);// root
    }

    void inorderRecusion(TreeNode* node){
        if(node == nullptr) return;
        inorderRecusion(node->left);// left
        std::swap(node->left, node->right);// root
        inorderRecusion(node->left);// left 画图分析
    }
    TreeNode* invertTree(TreeNode* root) {
        preorderRecusion(root);
        return root;
    }
};