#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
        ListNode* dummyHead_ = new ListNode(0);
        int size_;
public:
    Solution() {
        dummyHead_ = new ListNode(0);
        size_ = 0;
    }

    ListNode* reverseList(ListNode* head) {
      ListNode* tmp;
      ListNode* prev = nullptr;
      auto cur = head;

      while (cur) {
        tmp = cur->next;  //先保存cur下一个节点,因为下面翻转会覆盖cur->next
        cur->next = prev; //翻转
        prev = cur;       //把当前cur节点保存为prev,以供后续翻转
        cur = tmp;        //cur向后移动一个节点
      }

      return prev;
    }

    //my edition
    // ListNode* reverseList(ListNode* head) {
    //   if(nullptr == head) return nullptr;

    //   ListNode* prev = nullptr;
    //   auto cur = head;
    //   while (cur && cur->next)
    //   {
    //     auto tmp = cur;
    //     cur = cur->next;
    //     if(tmp == head) {
    //       head->next = nullptr;
    //     } else {
    //       tmp->next = prev;
    //     }

    //     prev = tmp;
    //   }

    //   cur->next = prev;
    //   return cur;
    // }
};

void printLinkedList(ListNode* head)
{
  auto dummyHead_ = new ListNode(0);
  dummyHead_->next = head;
  auto cur = dummyHead_;
  while (cur->next)
  {
    cout << cur->next->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main()
{
  ListNode* head_ = new ListNode();
  ListNode* idx_ = head_;
 
  vector<int> vecInput({1,2,3,4,5,6});
  for (int i = 0; i < vecInput.size(); ++i) {
    idx_->val = vecInput[i];
    if(i < vecInput.size() - 1) {
      idx_->next = new ListNode();
      idx_ = idx_->next;
    }
    std::cout << vecInput[i];
  }
  std::cout << std::endl;

  Solution solution;
  auto reversedList = solution.reverseList(head_);
  printLinkedList(reversedList);
  getchar();
}