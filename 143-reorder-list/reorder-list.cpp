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
    void reorderList(ListNode* head) {
        //step 1 find the middle of the linked list
        //step2 from the middle push all into stack
        //step3 now agains strat from head and pop 


        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //now my slow->next is mid

       // cout<<slow->next->val<<"\n";
        ListNode* curr=slow->next;
        slow->next=NULL;
        stack<ListNode*> st;
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->next;
        }

        curr=head;

        while(curr!=NULL && !st.empty())
        {
            ListNode* temp=curr->next;
            curr->next=st.top();
            st.pop();
            curr->next->next=temp;
            curr=temp;
        }

        


    }
};