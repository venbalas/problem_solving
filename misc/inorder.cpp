#include<iostream>
#include<stack>
#include<vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

std::vector<int> inorderTraversal(TreeNode *root)
{

    std::stack<TreeNode *> s;
    std::vector<int> traversal;

    if (!root)
        return traversal;

    s.push(root);

    while (s.size() > 0)
    {
        TreeNode *current = s.top();
        s.pop();

        // push it back and add left subtree
        if (current->left != nullptr)
        {
            s.push(current);
            s.push(current->left);
        }

        else
        {

            // Add current to result
            traversal.push_back(current->val);

            // Add right subtree if it exists
            if (current->right != nullptr)
                s.push(current->right);
        }
    }

    return traversal;
}

int main(int argc, char **argv) {

    std::cout<<"Test";



    return 0;
}