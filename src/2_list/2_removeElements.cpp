#include <vector>
#include <iostream>

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// My edition, may be wrong!
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if (nullptr == head) return nullptr;

//         ListNode* prev = nullptr;
//         ListNode* cur = head;
//         while(cur->next) {
//           if(cur->val == val) {
//             auto beDel = cur;
//             if(cur == head) {
//               head = cur->next;
//             } else {
//               prev->next = cur->next;
//             }

//             cur = cur->next;
//             delete beDel;
//           } else {
//             prev = cur;
//             cur = cur->next;
//           }
//         }

//         return head;
//     }
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* dummyHead = new ListNode(0);
      dummyHead->next = head;

      ListNode* cur = dummyHead;
      while(cur && cur->next) {
        if(cur->next->val == val) {
          auto tmp = cur->next;
          cur->next = cur->next->next;
          delete tmp;
        } else {
          cur = cur->next;
        }
      }

      head = dummyHead->next;
      delete dummyHead;
      return head;
    }
};


using std::vector;

int main()
{
  ListNode* head_ = new ListNode();
  ListNode* idx_ = head_;
 
  // vector<int> vecInput({1,2,6,3,4,5,6});
  vector<int> vecInput({7,7,7,7});
  for (auto elme : vecInput) {
    idx_->val = elme;
    idx_->next = new ListNode();
    idx_ = idx_->next;
    std::cout << elme;
  }

  Solution solution;
  // auto newList = solution.removeElements(head_, 6);
  auto newList = solution.removeElements(head_, 7);
  getchar();
}