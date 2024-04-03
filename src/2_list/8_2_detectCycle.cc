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
    ListNode* detectCycle(ListNode *head) {
      if (nullptr == head) return nullptr;

      auto slow = head;
      auto fast = head;

      while (fast->next && fast->next->next)
      {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
          auto index1 = head;
          auto index2 = slow;
          while (index1->next && index2->next)
          {
            if(index1 == index2)
              return index1;

            index1 = index1->next;
            index2 = index2->next;
          }
        }
      }

      return nullptr;
    }
};

int main()
{
  auto entry = new ListNode(2);
  auto tail = new ListNode(-4);
  auto head_ = new ListNode(3, entry);
  entry->next = new ListNode(0, tail);
  tail->next = entry;

  Solution solution;
  solution.detectCycle(head_);
}