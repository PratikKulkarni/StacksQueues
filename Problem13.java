class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode node=head,prev=null;
        while(node!=null){
            if(node.val==val){
                if(node==head){
                    head=head.next;
                    node=head;
                }
                else{
                    prev.next=node.next;
                    node=node.next;
                }
            }
            else{
                prev=node;
                node=node.next;
            }
        }
        return head;
    }
}