//  Odd Even Linked List
//   Go to Discuss
// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example 1:

// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL
// Example 2:

// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL
// Note:

// The relative order inside both the even and odd groups should remain as it was in the input.
// The first node is considered odd, the second node even and so on ...


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head)
{
	while(head)
	{
		printf("%d->",head->val);
		head = head->next;
	}
	printf("null\n");
}

ListNode* gen_list(vector<int>& a)
{
	ListNode* head = NULL;
	ListNode* cur = head;
	for(auto it:a)
	{
		if(!head)
		{
			head = new ListNode(it);
			cur = head;
		}
		else
		{
			cur->next = new ListNode(it);
			cur = cur->next;
		}
	}
	return head;
}




class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        auto p1 = head;
        auto p2 = head->next;
        auto head2 = p2;
        while(p1 && p2)
        {

        	p1->next = p2->next;
        	p1 = p1->next;
        	if(p1)
	        {
		    	p2->next = p1->next;
		    	p2 = p2->next;
	        }
        }
        auto t = head;
        while(t->next) t = t->next;
        t->next = head2;
        // print_list(head);
        // print_list(head2);
        return head;
    }
};




int main()
{

	// vector<int> a = {1,2,3,4,5};
	vector<int> a = {};
	auto l = gen_list(a);
	Solution sol;
	print_list(sol.oddEvenList(l));

	return 0;
}
