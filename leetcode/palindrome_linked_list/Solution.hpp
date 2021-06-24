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
	void PrintList(ListNode* head) {
		ListNode* iter = head;
		for (; iter != nullptr; iter = iter->next) {
			   cout << iter->val << " ";
		}
		cout << "\n";
	} 
	
	bool isPalindrome(ListNode* head) {
		if (head == nullptr) {
			return false;
		} else if (head->next == nullptr) {
			return true;
		} else {
			
			int dimension = 0;
			ListNode* iter = head;
			for (; iter != nullptr; iter = iter->next) {
				dimension++;
			}
			
			// cout << dimension << "\n";
			
			// the index where i start the reversion
			int middle_finger = (dimension + 1) / 2;
			
			
			// we need to get the middle node
			ListNode* middle_noodle = head;
			int counter = 0;
			for (; middle_noodle != nullptr; 
					middle_noodle = middle_noodle->next) {
				if (counter == middle_finger) {
					break;
				}
				counter++;
			}
			
			// cout << "Middle noodle: " << middle_noodle->val << "\n";
			
			ListNode* temp_head = new ListNode(); // has 0
			temp_head->next = new ListNode(middle_noodle->val);
			
			if (middle_noodle->next == nullptr) {
				return (head->val == middle_noodle->val);
			} else {
				iter = middle_noodle->next;
				for (; iter != nullptr; iter = iter->next) {
					ListNode* new_noodle = new ListNode(iter->val);
					new_noodle->next = temp_head->next;
					temp_head->next = new_noodle;
				}
			}
			
			temp_head = temp_head->next;
			
			cout << "Second half reversed: ";
			PrintList(temp_head);
			
			// cout << "First half: ";
			// iter = head;
			// counter = 0;
			// for (; iter != nullptr && counter < middle_finger; iter = iter->next) {
			// 	counter++;
			// 	cout << iter->val << " ";
			// }
			// cout << "\n";
			
			// now we compare the first half and the second half
			// when verifying go from 0 to middle_finger - 1
			// if dimension % 2 == 0 go to middle_finger - 1
			// esle go to middle_finger - 2
			
			iter = head;
			ListNode* rev_iter = temp_head;
			counter = 0;
			if (dimension % 2 == 0) {
				for (; iter != nullptr && rev_iter != nullptr && (counter < middle_finger); iter = iter->next, rev_iter = rev_iter->next) {
					if (iter->val != rev_iter->val) {
						return false;
					}
					counter++;
				}
				
			} else {
				for (; iter != nullptr && rev_iter != nullptr && (counter < middle_finger - 1); iter = iter->next, rev_iter = rev_iter->next) {
					if (iter->val != rev_iter->val) {
						return false;
					}
					counter++;
				}
			}
			return true;
		}
	}
};