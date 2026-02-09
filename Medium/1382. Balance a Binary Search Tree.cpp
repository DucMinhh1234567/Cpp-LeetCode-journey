#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

// Given the root of a binary search tree, return 
// a balanced binary search tree with the same node values. 
// If there is more than one answer, return any of them.
// A binary search tree is balanced if the depth of 
// the two subtrees of every node never differs by more than 1.

// Example 1:
// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

// Example 2:
// Input: root = [2,1,3]
// Output: [2,1,3]
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105


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
    void inorder(TreeNode* node, vector<int>& vals){
        if (node == nullptr) return;

        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    TreeNode* build(vector<int>& vals, int l, int r){
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* temp = new TreeNode(vals[mid]);
        temp->left = build(vals, l, mid - 1);
        temp->right = build(vals, mid + 1, r);
        return temp;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, vals.size() - 1);
    }
};