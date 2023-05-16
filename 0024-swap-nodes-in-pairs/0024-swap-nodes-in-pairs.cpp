class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=swapPairs(head->next->next);
        ListNode* t=head;
        head=head->next;
        head->next=t;
        head->next->next=temp;
        return head;
    }
};