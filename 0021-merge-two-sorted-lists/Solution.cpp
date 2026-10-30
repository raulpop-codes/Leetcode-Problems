struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* phead = new ListNode();
        ListNode* pmergedList = phead;

        while (list1 || list2) {
            int x1 = list1 ? list1->val : 32767;
            int x2 = list2 ? list2->val : 32767;

            if (x1 < x2) {
                pmergedList->next = list1;
                list1 = list1->next;
            } else {
                pmergedList->next = list2;
                list2 = list2->next;
            }
            pmergedList->next->next = nullptr;
            pmergedList = pmergedList->next;
        }

        pmergedList = phead;
        phead = phead->next;
        pmergedList->next = nullptr;
        delete pmergedList;
        return phead;
    }
};
