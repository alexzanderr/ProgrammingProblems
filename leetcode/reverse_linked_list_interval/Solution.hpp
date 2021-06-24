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

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr) {
			return nullptr;
		} else if (head->next == nullptr || m == n) {
			return head;
		} else {
			int dimension = 0;
			ListNode* start_node = nullptr;
			ListNode* stop_node = nullptr;
			for (ListNode* iter = head; 
					iter != nullptr; 
				iter = iter->next) {
				if (dimension == m - 1) {
					start_node = iter;
				} else if (dimension == n - 1) {
					stop_node = iter;
				}
				dimension++;
			}
						
			// reversing the specified interval
			ListNode* rev = new ListNode();
			rev->next = new ListNode(start_node->val);
			for (ListNode* iter = start_node->next;
				iter != stop_node->next; iter = iter->next) {
					
				ListNode* new_node = new ListNode(iter->val);
				new_node->next = rev->next;
				rev->next = new_node;
			}
			rev = rev->next; 
			
			ListNode* rev_stop = rev;
			for (; rev_stop->next != nullptr;
				rev_stop = rev_stop->next) {}
				
			if (m == 1 && n == dimension) {
				// the interval is the entire list
				return rev;
			} else if (m == 1 && n < dimension) {
				// the interval is from beginning to somewhere in middle
				rev_stop->next = stop_node->next;
				return rev;
			} else {
				// the interval is between front and end
				// so we have create front side before start_node
				ListNode* front = new ListNode(head->val);
				ListNode* front_iter = front;
				
				for (ListNode* head_iter = head->next; 
						head_iter != nullptr; 
						head_iter = head_iter->next) {
							
					if (head_iter == start_node) {
						front_iter->next = nullptr;
						break;
					}
					front_iter->next = head_iter;
					front_iter = front_iter->next;
				}
				
				ListNode* front_stop = front;
				for (; front_stop->next != nullptr;
					front_stop = front_stop->next) {}
				
				if (1 < m && n == dimension) {
					// from somewhere after start to the last element
					front_stop->next = rev;
				} else if (1 < m && n < dimension) {
					// in the middle
					rev_stop->next = stop_node->next;
					front_stop->next = rev;
				}
				return front;
			}
		}
	}
};