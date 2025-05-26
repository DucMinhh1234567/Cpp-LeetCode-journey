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
    // Cách 1: Đệ quy
    void postorderRecursive(TreeNode *root, vector<int> &result){
        if (!root) return;

        postorderRecursive(root->left, result);
        postorderRecursive(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderRecursive(root, result);
        return result;
    }

    // Cách 2: Dùng Stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (current || !st.empty()) {
            // Đi đến node trái nhất có thể
            while (current) {
                st.push(current);
                current = current->left;
            }

            // Lấy node trên cùng của stack
            current = st.top();

            // Nếu node hiện tại có con phải và chưa được thăm
            if (current->right && current->right != lastVisited) {
                current = current->right;
            } else {
                // Thêm giá trị node vào kết quả
                result.push_back(current->val);
                lastVisited = current;
                st.pop();
                current = nullptr;
            }
        }

        return result;
    }
};