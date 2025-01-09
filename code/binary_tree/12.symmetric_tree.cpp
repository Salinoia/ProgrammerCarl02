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
    bool compare(TreeNode* left, TreeNode* right){
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        
        if (left->val != right->val) return false;

        bool outside_comparsion = compare(left->left, right->right);
        bool inside_comparsion = compare(left->right, right->left);
        bool comparsion_result = outside_comparsion &&  inside_comparsion;
        return comparsion_result;
    }
    bool isSymmetric(TreeNode* root) {// 递归实现，函参数与返回值都可确定
        if(root == nullptr) return false;
        return compare(root->left, root->right);
    }
};