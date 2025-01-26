struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
class Solution{
public:
    int minDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);

        // 处理左子树为空，右子树非空场景，此时非叶子节点，不满足深度定义
        if(root->left == nullptr && root->right != nullptr){
            return 1 + right_depth;
        }   

        // 处理右子树为空，左子树非空场景，此时非叶子节点，不满足深度定义
        if(root->left != nullptr && root->right == nullptr){
            return 1 + left_depth;
        }

        return 1 + std::min(left_depth, right_depth);
    }
};