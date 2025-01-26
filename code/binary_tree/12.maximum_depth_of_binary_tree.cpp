#include <vector>
using std::vector;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for a Node.
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

#include <algorithm>
class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return 1 + std::max(left_height, right_height);
    }

    int maxDepth(Node* root){
        if(root == nullptr) return 0;
        int depth = 0;
        for(auto& child : root->children){
            depth = std::max(depth, maxDepth(child));
        }
        return depth + 1;
    }
};



