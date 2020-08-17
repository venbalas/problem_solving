#include<iostream>
#include<queue>
#include<string>
#include<memory>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
        
        queue<TreeNode *> level_order_queue;
        string tree_str;
        
        level_order_queue.push(root);
        
        while(!level_order_queue.empty())
        {
            TreeNode * element = level_order_queue.front();
            level_order_queue.pop();
            
            if(element==NULL)
                tree_str+="NULL,";
            else
            {
                tree_str+=element->val+",";
                
                // Enqueue the children
                level_order_queue.push(element->left);
                level_order_queue.push(element->right);
            }
        }
        
        return tree_str;
    }


int main()
{

    // Test
    TreeNode* root = new TreeNode(5);

    cout<<"Serialized:"<<serialize(root);
    return 0;
}
