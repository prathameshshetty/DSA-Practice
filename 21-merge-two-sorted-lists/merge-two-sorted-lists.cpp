/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;


        ListNode* ans=new ListNode(-1);
        ListNode* res=ans;
        ListNode* curr1=list1;
        ListNode* curr2=list2;

        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->val<=curr2->val)
            {
                ans->next=curr1;
                ans=ans->next;
                curr1=curr1->next;
            }
            else{
                ans->next=curr2;
                ans=ans->next;
                curr2=curr2->next;
            }
        }
        if(curr1!=NULL) ans->next=curr1;
        if(curr2!=NULL) ans->next=curr2;

        return res->next;
       
    }
};