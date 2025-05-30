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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Cách khôn lỏi
        vector<int> temp;
        ListNode *current = head;
        while(current){
            temp.push_back(current->val);
            current = current->next;
        }
        sort(temp.begin(), temp.end());
        current = head;
        for (int i = 0; i < temp.size(); i++){
            current->val = temp[i];
            current = current->next;
        }
        return head;

        // Cách merge sort
        // Tìm điểm giữa
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Tách list thành 2 phần
        ListNode *mid = slow->next;
        // Ngắt liên kết giữa nửa đầu và nửa sau của list để tạo thành 2 list riêng biệt
        slow->next = nullptr;
        
        // Đệ quy sắp xếp 2 nửa
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        
        return mergelist(l1, l2);
    }

    ListNode* mergelist(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // Lặp khi cả l1 và l2 đều còn phần tử
        while (l1 && l2) {
            // So sánh giá trị của node hiện tại của l1 và l2
            if (l1->val <= l2->val) {
                // Nếu giá trị l1 nhỏ hơn hoặc bằng l2
                // Nối current với node của l1
                current->next = l1;
                // Di chuyển l1 sang node tiếp theo
                l1 = l1->next;
            } else {
                // Nếu giá trị l2 nhỏ hơn l1
                // Nối current với node của l2 
                current->next = l2;
                // Di chuyển l2 sang node tiếp theo
                l2 = l2->next;
            }
            // Di chuyển current sang node vừa được nối
            current = current->next;
        }
        
        // Nếu l1 còn node thì nối current với l1, ngược lại nối với l2
        current->next = l1 ? l1 : l2;  // Vì đã chia đều 2 bên nên chỉ có thể thừa tối đa 1 node
        return dummy.next;
    }    
};