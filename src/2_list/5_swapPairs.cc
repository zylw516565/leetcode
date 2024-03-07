
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      auto dummyHead_ = new ListNode(0);
      dummyHead_->next = head;
      auto prev = dummyHead_;

      auto cur = head;
      while (cur && cur->next)
      {
        auto tmp = cur->next->next;  //先保存相邻两节点之后的节点地址
        cur->next->next = cur;                  //后指向前
        prev->next = cur->next;
        cur->next  = tmp;                       //交换后,相邻两节点指向断开的后继节点
        prev = cur;                             //更新prev
        cur = tmp;                              //cur移动两个节点
      }

      return dummyHead_->next;
    }
};