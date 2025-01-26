#include <string>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& results){
        // 前序遍历
        // 中
        path.push_back(cur->val);
        if(cur->left == nullptr && cur->right == nullptr){
            string sPath;
            int size = path.size();
            for(int i = 0; i < size - 1; ++i){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[size - 1]);
            results.emplace_back(move(sPath));
        }
        if(cur->left){// 左
            traversal(cur->left, path, results);
            path.pop_back();// 回溯
        }
        if(cur->right){// 右
            traversal(cur->right, path, results);
            path.pop_back();// 回溯
        }
    }
    void traversalSimplified(TreeNode* node, string path, vector<string>& results){// 使用拷贝传参，达到回溯效果
        path += to_string(node->val);
        if(node->left == nullptr && node->right == nullptr){
            results.emplace_back(move(path));
        }
        if(node->left) traversalSimplified(node->left, path + "->", results);
        if(node->right) traversalSimplified(node->right, path + "->", results);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        if(!root) return res;
        traversalSimplified(root, path, res);
        return res;
    }
};