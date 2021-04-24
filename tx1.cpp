#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    // 完全二叉树
    TreeNode *solve(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr == nullptr && flag == false)
                flag = true;
            if (curr)
            {
                q.push(curr->left);
                q.push(curr->right);
                if (flag)
                    curr->val = -1; // 删除标记
            }
        }
        q.push(root);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr->left)
            {
                if (curr->left->val == -1)
                    curr->left = nullptr;
                else
                    q.push(curr->left);
            }
            if (curr->right)
            {
                if (curr->right->val == -1)
                    curr->right = nullptr;
                else
                    q.push(curr->right);
            }
        }
        return root;
    }
};

class Solution
{
public:
    // 满二叉树
    TreeNode *solve(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr || root->right == nullptr)
        {
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        root->left = solve(root->left);
        root->right = solve(root->right);
        return root;
    }
};
