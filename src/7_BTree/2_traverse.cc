#include <vector>

using std::vector;

struct TreeNode
{
  int val_;
  TreeNode* left_;
  TreeNode* right_;

  TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr)
  :val_(val)
  ,left_(left)
  ,right_(right)
  {
  }
};

class Solution {
  public:

    void preorderTraverse(TreeNode* node, vector<int>& vec)
    {
      if(node == nullptr) return;
      vec.push_back(node->val_);
      preorderTraverse(node->left_, vec);
      preorderTraverse(node->right_, vec);
    }

    vector<int> preTraverse(TreeNode* node)
    {
      vector<int> vec;
      preorderTraverse(node, vec);
      return vec;
    }

    void inorderTraverse(TreeNode* node, vector<int>& vec)
    {
      if(node == nullptr) return;
      inorderTraverse(node->left_, vec);
      vec.push_back(node->val_);
      inorderTraverse(node->right_, vec);
    }

    vector<int> inTraverse(TreeNode* node)
    {
      vector<int> vec;
      inorderTraverse(node, vec);
      return vec;
    }

    void postorderTraverse(TreeNode* node, vector<int>& vec)
    {
      if(node == nullptr) return;
      postorderTraverse(node->left_, vec);
      postorderTraverse(node->right_, vec);
      vec.push_back(node->val_);
    }

    vector<int> postTraverse(TreeNode* node)
    {
      vector<int> vec;
      postorderTraverse(node, vec);
      return vec;
    }
};

int main()
{

}