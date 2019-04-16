/***********************************************************
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 *
 A complete binary is represented as follows:
 Input:
    1
   / \
  2   3
 / \  /
4  5 6
 ***********************************************************/

// not so optimal!!
void count(struct TreeNode *root, int *ct)
{
    if(root == NULL)
    {
        return;
    }
    *ct += 1;
    count(root->left,ct);
    count(root->right,ct);
}

int countNodes(struct TreeNode* root)
{
    int ct = 0;
    if(root == NULL)
    {
        return 0;
    }
    // ++count;
    // count = countNodes(root->left);
    // //printf("val:%d\n",root->val);
    // count = countNodes(root->right);

    count(root,&ct);
    return ct;
}
