// Merge k Sorted Lists
//   Go to Discuss
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>

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
	class cmp
	{
	public:
		bool operator()(ListNode* a, ListNode* b) const
		{
			return a->val > b->val;
		}
	};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	int n = lists.size();
    	if(n==0) return NULL;
    	// auto cmp = [](ListNode* a,ListNode* b){return a->val > b->val;};
    	// std::priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
    	std::priority_queue<ListNode*,vector<ListNode*>,
    						cmp> pq;
    	for(auto l:lists)
    	{
    		if(l!=NULL)
    			pq.push(l);
    	}
    	ListNode* head = NULL;
    	ListNode* cur = NULL;
    	while(!pq.empty())
    	{
    		auto top = pq.top();
    		if(head==NULL)
    		{
    			head = top;
    			cur = head;
    		}
    		else
    		{
    			cur->next = top;
    			cur = top;
    		}
    		ListNode* tmp = top->next;
    		top->next = NULL;
    		pq.pop();
    		if(tmp)
    		{
    			pq.push(tmp);
    		}
    	}
    	return head;
        

    }
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


int main()
{
	vector<vector<int> > a={
		{1,4,5},
		{1,3,4},
		{2,6}
	};
	vector<ListNode*> l;
	for(auto v:a)
	{
		l.push_back(gen_list(v));
		print_list(l.back());
	}
	Solution sol;
	auto head = sol.mergeKLists(l);
	print_list(head);


	return 0;
}
