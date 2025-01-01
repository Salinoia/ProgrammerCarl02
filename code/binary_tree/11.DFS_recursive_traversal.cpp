#include<vector>
using std::vector;

struct TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class RecursiveTraversal {
public:
    void preTraversal(TreeNode* current_node, vector<int>& values){
        if(current_node == nullptr) return;
        values.push_back(current_node->val);// middle
        preTraversal(current_node->left, values);// left
        preTraversal(current_node->right, values);// right
    }
    void inTraversal(TreeNode* current_node, vector<int>& values){
        if(current_node == nullptr) return;
        inTraversal(current_node->left, values);
        values.push_back(current_node->val);
        inTraversal(current_node->right, values);
    }
    void postTraversal(TreeNode* current_node, vector<int>& values){
        if(current_node == nullptr) return;
        postTraversal(current_node->left, values);
        postTraversal(current_node->right, values);
        values.push_back(current_node->val);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preTraversal(root, res);
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inTraversal(root, res);
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postTraversal(root, res);
        return res;
    }
};