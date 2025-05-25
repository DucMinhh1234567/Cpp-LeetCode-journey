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
    // Cách 1: Sử dụng đệ quy
    void inorderRecursive(TreeNode* root, vector<int>& result) {
        if (!root) return;
        
        inorderRecursive(root->left, result);  // Duyệt cây con trái
        result.push_back(root->val);           // Thêm giá trị gốc
        inorderRecursive(root->right, result); // Duyệt cây con phải
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderRecursive(root, result);
        return result;
    }
    
    // Cách 2: Sử dụng stack
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        while (current || !st.empty()) {
            // Đi đến node trái nhất
            while (current) {
                st.push(current);
                current = current->left;
            }
            
            // Lấy node từ stack
            current = st.top();
            st.pop();
            
            // Thêm giá trị vào kết quả
            result.push_back(current->val);
            
            // Chuyển sang cây con phải
            current = current->right;
        }
        
        return result;
    }
    
    // Cách 3: Morris Traversal (không sử dụng stack và đệ quy)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        
        while (current) {
            if (!current->left){
                // Nếu không có cây con trái, thêm giá trị hiện tại
                result.push_back(current->val);
                current = current->right;
            } 
            else {
                // Tìm node phải nhất của cây con trái
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                
                if (!predecessor->right) {
                    // Tạo liên kết tạm thời
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Xóa liên kết tạm thời
                    predecessor->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        
        return result;
    }
};