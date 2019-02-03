//  list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5


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


ListNode* gen_list(vector<int>& a)
{
	ListNode* head = NULL;
	ListNode* cur = head;
	for(auto i:a)
	{
		if(head == NULL)
		{
			head = cur = new ListNode(i);
		}
		else
		{
			cur->next = new ListNode(i);
			cur = cur->next;
		}
	}
	return head;
}
void print_list(ListNode* head)
{
	auto cur = head;
	while(cur!=NULL)
	{
		printf("%d->",cur->val);
		cur = cur->next;
	}
	printf("\n");
	
}


class Solution {
public:
	ListNode* make_sort(ListNode*l, ListNode* r)
	{

	}
	ListNode* MergeList(ListNode* l,ListNode* r)
	{
		ListNode* cur = NULL;
		ListNode* head = cur;
		if(l==NULL && r) return r;
		if(l&&r==NULL) return l;
		if(l==NULL && r==NULL) return NULL;

		while(l&&r)
		{
			if(l->val < r->val)
			{
				if(head==NULL)
				{
					head = cur = l;

				}
				else
				{
					cur->next = l;
					cur = l;
				}
				l = l->next;
			}
			else
			{
				if(head==NULL)
				{
					head = cur = r;
				}
				else
				{
					cur->next = r;
					cur = r;
				}
				r = r->next;
			}
		}
		if(l||r)
		{
			auto remain = l?l:r;
			while(remain)
			{

				cur->next = remain;
				cur = remain;
				remain = remain->next;
			}
		}
		return head;

	}
	ListNode* get_mid(ListNode* head)
	{
		ListNode* mid = head;
        ListNode* cur = head;
        ListNode* pre_mid = head;
        while(mid && mid->next)
        {
        	pre_mid = cur;
        	cur = cur->next;
        	mid = mid->next->next;
        }
        return pre_mid;
	}
    ListNode* sortList(ListNode* head) {
    	if(head==NULL) return NULL;
    	if(head->next == NULL) return head;

    	auto mid = get_mid(head);
    	auto l = head;
    	auto r = mid->next;
    	mid->next = NULL;

    	auto h1 = sortList(l);
    	auto h2 = sortList(r);
    	auto ret = MergeList(h1,h2);
    	//l..mid mid+1..r
    	return ret;

    }
};

int main()
{
	vector<int> a={
		4,2,1,3,5
	};
	auto l = gen_list(a);
	Solution sol;
	auto head = sol.sortList(l);
	print_list(head);

	return 0;
}
