struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int MAX = 32767;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* phead = new ListNode();
        ListNode* pmergedList = phead;
        int length = lists.size();

        while (true) {
            int val = MAX, idx = -1;
            for (int k = 0; k < length; k++) {
                if (!lists[k]) continue;

                if (lists[k]->val < val) {
                    idx = k;
                    val = lists[k]->val;
                }
            }
            if (val == MAX) break;

            pmergedList->next = lists[idx];
            pmergedList = pmergedList->next;
            lists[idx] = lists[idx]->next;
        }
        if (phead->next == nullptr) { delete phead; return nullptr; }

        pmergedList = phead;
        phead = phead->next;
        pmergedList->next = nullptr;
        delete pmergedList;
        return phead;
    }
};
