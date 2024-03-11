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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(nullptr == headA || nullptr == headB) return nullptr;

      int lenA = 1, lenB = 1;
      auto curA = headA;
      auto curB = headB;

      while(curA->next && curB->next) {
          curA = curA->next;
          curB = curB->next;
          ++lenA;
          ++lenB;
      }

      if(curA->next) {
        while(curA->next) {
          curA = curA->next;
          ++lenA;
        }
      }

      if(curB->next) {
        while (curB->next)
        {
          curB = curB->next;
          ++lenB;
        }
      }

      if(curA != curB) return nullptr;

      int diff = 0;
      curA = headA;
      curB = headB;

      if(lenA >= lenB) {
        diff = lenA - lenB;
        while (diff-- && curA->next) {
          curA = curA->next;
        }
      } else {
        diff = lenB - lenA;
        while (diff-- && curB->next) {
          curB = curB->next;
        }
      }

      while (curA && curB)
      {
        if(curA == curB && curA != nullptr && curB != nullptr) {
          return curA;
        } else {
          curA = curA->next;
          curB = curB->next;
        }
      }

      return nullptr;
    }
};

// [0,9,1,2,4]
// [3,2,4]

int main()
{
  ListNode* commonHead_ = new ListNode(2, new ListNode(4));
  ListNode* headA_ = new ListNode(0, new ListNode(9, new ListNode(1, commonHead_)));
  ListNode* headB_ = new ListNode(3, commonHead_);

  headA_ = headB_ = new ListNode(1);
  Solution solution;
  auto intersectionNode = solution.getIntersectionNode(headA_, headB_);
  std::cout << intersectionNode->val << std::endl;
}