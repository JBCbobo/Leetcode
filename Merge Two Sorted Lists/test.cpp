/*
 * author:JBC
 * date:2017/9/7
 * describe:Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(NULL == l1)  return l2;
    if(NULL == l2)  return l1;
    if(l1->val < l2->val)
    {
        l1->next =  mergeTwoLists(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next =  mergeTwoLists(l1,l2->next);
        return l2;
    }
}
