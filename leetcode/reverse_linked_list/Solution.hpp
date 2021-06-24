/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	   int val;
 *	   ListNode *next;
 *	   ListNode() : val(0), next(nullptr) {}
 *	   ListNode(int x) : val(x), next(nullptr) {}
 *	   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
        if (head == nullptr ) {
            return nullptr;
        } else if (head->next == nullptr){
            return head;
        } else {
            ListNode* reversed = new ListNode();
            reversed->next = new ListNode(head->val);
            
            for (ListNode* iter = head->next; iter != nullptr; iter = iter->next) {
                ListNode* new_node = new ListNode(iter->val);
                new_node->next = reversed->next;
                reversed->next = new_node;
            }
            reversed = reversed->next;
            return reversed;   
        }
	}
};