#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (nullptr == head) return false;

      auto dummyNode_ = new ListNode();
      dummyNode_->next = head;
      auto slow = dummyNode_;
      auto fast = dummyNode_;

      while (fast->next && fast->next->next)
      {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
          return true;
        }
      }

      return false;
    }
};

int main()
{
}