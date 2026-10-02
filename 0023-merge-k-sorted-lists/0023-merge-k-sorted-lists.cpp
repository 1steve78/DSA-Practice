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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        int n = lists.size();
        for(int i = 0 ; i<n ;i++){
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode * dummy  = new ListNode(0);
        ListNode * temp = dummy;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            temp->next = it.second;
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};