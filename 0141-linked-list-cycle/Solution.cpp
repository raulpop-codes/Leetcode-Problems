struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) { return false; }

        ListNode* slow = head;
        ListNode* fast = head;

        do {
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : nullptr;
        } while (fast && slow && fast != slow);

        return fast && slow;
    }
};
