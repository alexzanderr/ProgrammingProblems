#include <iostream>
#include "Solution.hpp"

using namespace std;
	
// void test(int array[]) {
// 	cout << sizeof(array) / sizeof(array[0]) << "\n";
// }

ListNode* LinkedListFromArray(int *array, int size) {
	ListNode* head = new ListNode(array[0]);
	ListNode* iter = head;
	for (int i = 1; i < size; ++i) {
		ListNode* new_node = new ListNode(array[i]);
		iter->next = new_node;
		iter = iter->next;
	}
	return head;
}
	
void PrintList(ListNode* head) {
	cout << "[ ";
	ListNode* iter = head;
	for (; iter->next != nullptr; iter = iter->next) {
		cout << "(" << iter->val << ") -> ";
	}
	cout << "(" << iter->val << ") ]\n";
}
	
int main() {
	cout << "\n";
	int array[] = {1, 2, 3};
	int size = sizeof(array) / sizeof(array[0]);
	// test(array); 
	
	ListNode* head = LinkedListFromArray(array, size);
	PrintList(head);
	
	
	Solution s;
	ListNode* rev = s.reverseBetween(head, 1, 2);
	PrintList(rev);
	
	cout << "\n";
	return 0;
}