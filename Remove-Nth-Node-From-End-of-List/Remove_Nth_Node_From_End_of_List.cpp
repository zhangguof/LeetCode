
// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = 1;
        ListNode* p = head;
        while(p->next!=NULL)
        {
            len++;
            p=p->next;
        }
        int count = len-n+1;
        std::cout<<"count:"<<count<<std::endl;
        ListNode *q = head;
        p = head; //p will  remove.
        if(count==1)
        {
            head = q->next;
            return head;
        }
        
        for(int i=2;i<=count;i++)
        {
            q=p;
            p=p->next;
            
        }
        
        //remove p
        std::cout<<p->val<<std::endl;
        q->next = p->next;
        
        return head;
        
    }
};

ListNode * makeList(int a[],int len)
{
    ListNode *head = new ListNode(a[0]);
    ListNode *p = head;
    for(int i=1;i<len;i++)
    {
        p->next = new ListNode(a[i]);
        p=p->next;
    }
    return head;
}

void printList(ListNode* head)
{
    ListNode *p=head;
    std::cout<<p->val<<std::endl;
    while(p->next != NULL)
    {
        p=p->next;
        std::cout<<p->val<<std::endl;
    }
    
}

int main()
{
    int a[]={1,2,3,4,5};
    ListNode *head = makeList(a,sizeof(a)/sizeof(int));
    printList(head);
    
    std::cout<<"----"<<std::endl;
    Solution sol;
    ListNode* r = sol.removeNthFromEnd(head,1);
    printList(r);
    
}


