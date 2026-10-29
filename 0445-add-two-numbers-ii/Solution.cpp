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
        ListNode* invertedl1 = inverted(l1);
        ListNode* invertedl2 = inverted(l2);
        ListNode* copy1 = invertedl1;
        ListNode* copy2 = invertedl2;

        ListNode* phead = nullptr;
        int carry = 0;
        while (invertedl1 || invertedl2 || carry) {
            int x1 = invertedl1 ? invertedl1->val : 0;
            int x2 = invertedl2 ? invertedl2->val : 0;

            int sum = x1 + x2 + carry;
            ListNode* pnewnode = new ListNode(sum % 10);
            carry = sum / 10;
            pnewnode->next = phead;
            phead = pnewnode;

            invertedl1 = invertedl1 ? invertedl1->next : nullptr;
            invertedl2 = invertedl2 ? invertedl2->next : nullptr;
        }

        inverted(copy1);
        inverted(copy2);

        return phead;
    }

private:
    ListNode* inverted(ListNode* phead) {
        ListNode* current = phead;
        ListNode* prev = nullptr;
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
