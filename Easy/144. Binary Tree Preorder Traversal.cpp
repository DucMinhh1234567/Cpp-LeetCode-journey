#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Cách 1: đệ quy
    void preorderRecursive(TreeNode *root, vector<int> &result){
        if (!root) return;

        result.push_back(root->val);
        preorderRecursive(root->left, result);
        preorderRecursive(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderRecursive(root, result);
        return result;
    }
    
    // Cách 2: Dùng Stack
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            
            result.push_back(current->val);

            // Push right trước, sau đó push left
            // Vì stack là LIFO (Last In First Out)
            if (current->right) {
                st.push(current->right);
            }
            if (current->left) {
                st.push(current->left);
            }
        }

        return result;
    }
};