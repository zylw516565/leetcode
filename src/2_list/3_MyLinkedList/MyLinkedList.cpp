class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

private:
    ListNode* dummyHead_;
    int       size_;
public:
    MyLinkedList() {
        dummyHead_ = new ListNode(0);
        size_ = 0;
    }

    int get(int index) {
        if(index < 0 || index > size_ - 1 || 0 == size_) return -1;

        auto cur = dummyHead_;
        for (int i = 0; i < index && cur && cur->next; i++) {
          cur = cur->next;
        }

        return cur->next->val;
    }
    
    void addAtHead(int val) {
      auto tmp = dummyHead_->next;
      auto head = new ListNode(val);
      dummyHead_->next = head;
      head->next = tmp;
      ++size_;
    }
    
    void addAtTail(int val) {
      auto cur = dummyHead_;
      while(cur && cur->next) {
        cur = cur->next;
      }

      cur->next = new ListNode(val);
      ++size_;
    }

    void addAtIndex(int index, int val) {
      if(index > size_) return;

      auto cur = dummyHead_;
      for(int i = 0; i < index && cur && cur->next; ++i) {
        cur = cur->next;
      }

      if(index < size_) {
        auto tmp = cur->next;
        auto newNode = new ListNode(val);
        cur->next = newNode;
        newNode->next = tmp;
      } else {
        cur->next = new ListNode(val);
      }

      ++size_;
    }
    
    void deleteAtIndex(int index) {
      if(index < 0 || index > size_ - 1 || 0 == size_) return;

      auto cur = dummyHead_;
      for(int i = 0; i < index && cur && cur->next; ++i) {
        cur = cur->next;
      }

      auto tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;
      --size_;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
  MyLinkedList linkedList;
  linkedList.addAtHead(1);
  linkedList.addAtTail(3);
  linkedList.addAtIndex(1,2);
  linkedList.get(1);
  linkedList.deleteAtIndex(1);
  linkedList.get(1);
}