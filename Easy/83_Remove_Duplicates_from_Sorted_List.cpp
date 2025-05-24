#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode *current = head;
        while (current && current->next){
            if (current->val == current->next->val){
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }

        // Two pointer: fast and slow, giảm được 1 số lần so sánh
        // if (!head || !head->next) return head;
        
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        
        // while (fast) {
        //     if (slow->val == fast->val) {
        //         // Skip duplicate node
        //         slow->next = fast->next;
        //         delete fast;
        //         fast = slow->next;
        //     } else {
        //         // Move both pointers
        //         slow = fast;
        //         fast = fast->next;
        //     }
        // }

        return head;
    }
};