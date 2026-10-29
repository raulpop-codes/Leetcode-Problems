struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* phead = new ListNode();
        ListNode* pcurrent = phead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;
            int sum = carry + x1 + x2;
            carry = sum / 10;

            ListNode* pnewnode = new ListNode(sum % 10);
            pcurrent->next = pnewnode;

            pcurrent = pcurrent->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        pcurrent = phead;
        phead = phead->next;
        pcurrent->next = nullptr;
        delete pcurrent;
        return phead;
    }
};
