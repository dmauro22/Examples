//Definition for singly-linked list.
//struct ListNode 
//{
//    int val;
//   ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
 
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
		ListNode *list1 = l1;
		ListNode *list2 = l2;
		ListNode l3(0);
        ListNode *ptr = &l3;
		bool carry = false;
		while (list1 || list2 || carry)
		{
			int sum = 0;
			sum = (list1 ? list1->val : 0) + (list2 ? list2->val : 0) + carry;
			if (sum > 9)
			{
				sum %= 10;
				carry = true;
			}
			else
			{
				carry = false;
			}
            
            ptr->next = new ListNode(sum);
            ptr = ptr->next; 
            if(list1)
                list1 = list1->next;
            if(list2)
			    list2 = list2->next;
		}
		return l3.next;

    }
};
