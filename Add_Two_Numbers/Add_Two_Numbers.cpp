//   Add Two Numbers
//   Go to Discuss
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.


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


class Solution {
public:
    ListNode* reverse_list(ListNode* l)
    {
        auto pre = l;
        auto cur = pre->next;
        while(1)
        {
           if(!cur) break;
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;  
        }
        l->next = NULL;
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse
        if(!l1 && !l2) return NULL;
        if(!l1 && l2) return l2;
        if(!l2 && l1) return l1;
        ListNode* head = NULL;
        ListNode* cur = NULL;

        // l1 = reverse_list(l1);
        // l2 = reverse_list(l2);
        auto p1 = l1;
        auto p2 = l2;
        int inc = 0;
        while(p1 && p2)
        {
        	int val = p1->val + p2->val + inc;
        	inc = val / 10;
        	val = val % 10;
        	if(!head)
        	{
        		cur = head = new ListNode(val);
        	}
        	else
        	{
        		cur->next = new ListNode(val);
        		cur = cur->next;
        	}
        	printf("add val:%d,inc:%d\n",val,inc);
        	p1 = p1->next;
        	p2 = p2->next;
        }
        auto p = p1;
        if(p==NULL && p2)
        {
        	p = p2;
        }
        while(p || inc)
        {
        	int val = 0;
        	if(p)
        	{
        		val = p->val + inc;
        	}
        	else
        	{
        		val = inc;
        	}
        	inc = val / 10;
        	val = val % 10;
        	cur->next = new ListNode(val);
        	cur = cur->next;
        	if(p)
        		p = p->next;
        }
        // return reverse_list(head);
        return head;
        
    }
};

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

void print_list(ListNode* head)
{
	while(head)
	{
		printf("%d->",head->val);
		head = head->next;
	}
	printf("null\n");
}

int main()
{

	Solution sol;
	// vector<int> a = {2,4,3};
	// vector<int> b = {5,6,4};
	vector<int> a = {5};
	vector<int> b = {5};
	ListNode* la = gen_list(a);
	ListNode* lb = gen_list(b);
	// auto l1 = sol.reverse_list(la);
	// auto l2 = sol.reverse_list(lb);
	// print_list(l1);
	// print_list(l2);
	print_list(sol.addTwoNumbers(la,lb));


	return 0;
}
