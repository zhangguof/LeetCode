// Intersection of Two Linked Lists
//   Go to Discuss
// Write a program to find the node at which the intersection of two singly linked lists begins.

// For example, the following two linked lists:


// begin to intersect at node c1.

 

// Example 1:


// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
// Output: Reference of the node with value = 8
// Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

// Example 2:


// Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Reference of the node with value = 2
// Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

// Example 3:


// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: null
// Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
// Explanation: The two lists do not intersect, so return null.
 

// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(!headA || !headB) return NULL;
    	auto t = headA;
    	int len1 = 0;
    	int len2 = 0;
    	while(t)
    	{
    		++len1;
    		t=t->next;
    	}
    	t = headB;
    	while(t)
    	{
    		++len2;
    		t = t->next;
    	}
    	//len(la) < len(lb)
    	auto la = headA;
    	auto lb = headB;
    	int count = (len2 - len1);
    	if(len1>len2)
    	{
    		la = headB;
    		lb = headA;
    		count = -count;
    	}
    	while(count--) lb=lb->next;
    	while(la && lb)
    	{
    		if(la==lb) return la;
    		la = la->next;
    		lb = lb->next;
    	}
    	return NULL;
    }
};

int main()
{
	// vector<int> A = {4,1,8,4,5};
	// vector<int> B = {5,0,1};
	// auto la = gen_list(A);
	// auto lb = gen_list(B);
	// auto t = lb;
	// while(t->next) t=t->next;
	// t->next = la->next->next;


	vector<int> A = {0,9,1,2,4};
	vector<int> B = {3};
	auto la = gen_list(A);
	auto lb = gen_list(B);
	auto t = lb;
	while(t->next) t=t->next;
	t->next = la->next->next->next;
	// print_list(la);
	// print_list(lb);

	Solution sol;
	print_list(sol.getIntersectionNode(la,lb));


	return 0;
}
