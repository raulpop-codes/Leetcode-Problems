struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* pcurrent = head;
        ListNode* pnthnode = head;
        int i;
        for (i = 0; i < n && pnthnode != nullptr; i++) {
            pnthnode = pnthnode->next;
        }

        while (pnthnode) {
            prev = pcurrent;
            pcurrent = pcurrent->next;
            pnthnode = pnthnode->next;
        }
        if (!prev) {
            prev = pcurrent->next;
            delete pcurrent;
            return prev;
        }
        prev->next = pcurrent->next;
        pcurrent->next = nullptr;
        delete pcurrent;
        return head;
    }
};
