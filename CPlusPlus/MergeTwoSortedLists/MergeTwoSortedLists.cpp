

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode merged(0);// = ListNode(0);
        
        ListNode *walker = &merged;
        
        while (l1 || l2)
        {
            
            if(!l1)
            {
                walker->next = l2;
                return merged.next;
            }
            if(!l2)
            {
                walker->next = l1;
                return merged.next;
            }
            
            if (l1->val <= l2->val)
            {
                walker->next = new ListNode(l1->val);
                l1 = l1->next;
                walker = walker->next;
            }
            
            else
            {
                walker->next = new ListNode(l2->val);
                l2 = l2->next;
                walker = walker->next;
            }
        
        }
        
        return merged.next;
        
        
    }
};
