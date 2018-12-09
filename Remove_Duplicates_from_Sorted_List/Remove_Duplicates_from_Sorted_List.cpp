// 83. Remove Duplicates from Sorted List
// Easy

// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3

#include <iostream>
#include <algorithm>
#include <vector>


#include <stdlib.h>

#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return head;
    	
    	ListNode* pre = head;
    	ListNode* last = head->next;
    	while(last)
    	{
    		if(last->val == pre->val)
    		{
    			pre->next = last->next;//remove it.
    		}
    		else
    		{
    			pre = last;
    		}
    		last = last->next;
    	}
        return head;
    }
};



int main()
{
	// std::vector<int> v = {1,1,2,3,3};
	std::vector<int> v = {1};
	ListNode* head = NULL;
	ListNode* tail = NULL;
	for(auto i:v)
	{
		if(!head)
		{
			head = new ListNode(i);
			tail = head;
		}
		else
		{
			tail->next = new ListNode(i);
			tail = tail->next;
		}
	}
	Solution sol;
	auto p = sol.deleteDuplicates(head);
	while(p)
	{
		printf("%d->",p->val);
		p = p->next;
	}
	printf("null\n");
	return 0;
}



