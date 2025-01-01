#include <vector>
#include <stack>
#include <algorithm>
using std::vector;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class IterativeTraversal{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        std::stack<TreeNode*> st;
        TreeNode* current = root;
        while(current != nullptr || !st.empty()){
            while(current != nullptr){// 先将左子树压栈
                st.push(current);
                current = current->left;
            }
            // 访问当前节点
            current = st.top();
            st.pop();
            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        std::stack<TreeNode*> st;
        if(root != nullptr) st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node != nullptr){
                result.push_back(node->val);
                // 先右子树后左子树，因为栈是后进先出（LIFO）的结构
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
        }
        return result;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        std::stack<TreeNode*> st;
        
        if (root != nullptr) st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            if (node != nullptr) {
                result.push_back(node->val);  // 先访问根节点
                
                // 先压左子树，再压右子树
                if (node->left) st.push(node->left);  // 左子树
                if (node->right) st.push(node->right);  // 右子树
            }
        }
        
        // 反转结果数组，得到左 -> 右 -> 根 的顺序
        std::reverse(result.begin(), result.end());
        return result;
    }
};