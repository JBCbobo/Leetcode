/**
 * Time : 2017/8/24
 * Author: JbcBoBo
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head;
	int i = 0;
	int flag = 0; //进位标志
	struct ListNode *node ;
	l3->next = NULL;
    head = l3;
	while(NULL != l1 || NULL !=l2)
	{
		/*Add l3 List node*/
		node = (struct ListNode *)malloc(sizeof(struct ListNode)); 
		l3->next = node;
		l3 = l3->next;
		l3->next = NULL;
		if(NULL != l1 && NULL !=l2)
		{
			l3->val = l1->val  + l2->val + flag;
            l1 = l1->next;
		    l2 = l2->next;
		}
		else if(NULL != l1)
		{
			l3->val = l1->val + flag;
            l1 = l1->next;
		}
		else
		{
			l3->val = l2->val + flag;
            l2 = l2->next;
		}
        flag = 0;
		if(l3->val >= 10)
		{
			l3->val = l3->val - 10;
			flag = 1;
		}
		else
		{
			flag  = 0;
		}
        if(NULL == l1 && NULL == l2 && flag == 1)
        {
            node = (struct ListNode *)malloc(sizeof(struct ListNode)); 
            l3->next = node;
            l3 = l3->next;
            l3->next = NULL;
            l3->val  = 1;
        }
	}
    return head->next;
}
