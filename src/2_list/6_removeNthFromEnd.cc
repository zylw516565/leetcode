
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
        auto dummyHead_ = new ListNode(0);
        dummyHead_->next = head;

        auto slow = dummyHead_;
        auto fast = dummyHead_;
        while(n-- && fast) {
            fast = fast->next;
        }

        while(fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummyHead_->next;
    }
};