class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *n1,*n2,*n3;
        if(head==NULL)
            return head;
        else if(head->next==NULL)
            return head;
        else if(head->next->next==NULL){
            n1=head;
            n2=head->next;
            n2->next=n1;
            n1->next=NULL;
            return n2;
        }
        else{
            n1=head;
            n2=n1->next;
            n3=n2->next;
            n1->next=NULL;
            while(n3!=NULL){
                n2->next=n1;
                n1=n2;
                n2=n3;
                n3=n3->next;
            }
            n2->next=n1;
            return n2;
        }
    }
};