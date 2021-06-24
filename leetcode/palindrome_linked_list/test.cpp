#include <iostream>
#include "Solution.hpp"

using namespace std;


int main() { 
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);	 
	
	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(2);
	head2->next->next = new ListNode(3);
	head2->next->next->next = new ListNode(3);
	head2->next->next->next->next = new ListNode(2);
	head2->next->next->next->next->next = new ListNode(1);
		
	ListNode* head3 = new ListNode(4);
	head3->next = new ListNode(3);
	head3->next->next = new ListNode(4);
	
	Solution s;
	s.PrintList(head);
	if (s.isPalindrome(head)) {
		cout << "yes\n";
	} else {
		cout << "NO\n";
	}
	
	s.PrintList(head2);
	if (s.isPalindrome(head2)) {
		cout << "yes\n";
	} else {
		cout << "NO\n";
	}
	s.PrintList(head3);
	if (s.isPalindrome(head3)) {
		cout << "yes\n";
	} else {
		cout << "NO\n";
	}
	// int x = 3;

	// if (x == 3) {  
		
	// } else if (x != 3) {
	// 	// == == == <= += >= 
	// 	/*
	// 		some text here
	// 		lets have some fun	
	// 	*/
	
	// } else if (x >= 3) {
	// 	// lets have some tests on my machine
	// } else if (x <= 3) {
	// 	// some comments here in the vs code editor
	// }
		
	return 0;
}