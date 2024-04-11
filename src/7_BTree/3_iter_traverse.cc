#include <stack>
#include <vector>
#include <iostream>

using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:

  vector<int> preorderTraversal(TreeNode* root)
  {
    stack<TreeNode*> st;
    vector<int> vec;
    if(nullptr == root) return vec;
    st.push(root);

    while (!st.empty())
    {
      auto node = st.top();
      vec.push_back(node->val);
      st.pop();

      if(node->right) st.push(node->right);
      if(node->left) st.push(node->left);
    }

    return vec;
  }

  vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;
      stack<TreeNode*> st;
      TreeNode* cur = root;
      while (cur != NULL || !st.empty()) {
          if (cur != NULL) { // 指针来访问节点，访问到最底层
              st.push(cur); // 将访问的节点放进栈
              cur = cur->left;                // 左
          } else {
              cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
              st.pop();
              result.push_back(cur->val);     // 中
              cur = cur->right;               // 右
          }
      }
      return result;
  }
};

int main()
{
  auto root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3, nullptr, nullptr), nullptr));
  Solution solution;
  auto res = solution.inorderTraversal(root);
  for (auto &&i : res)
  {
    std::cout << i << std::endl;
  }
}