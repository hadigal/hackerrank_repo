/************************* Leetcode ****************************
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

************************************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define NULL ((void *)(0))

struct TreeNode *create(int val)
{
    struct TreeNode *node = (struct TreeNode *)calloc(1,sizeof(*node));
    if(node == NULL)
    {
        return NULL;
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode *helper(int *pre, int *in, int start, int end, int *pIdx)
{
    if(start > end)
    {
        return NULL;
    }
    int rootVal = pre[*pIdx];
    struct TreeNode *node = create(rootVal);
    (*pIdx)++;

    if(start == end)
    {
        return node;
    }

    size_t itr = start;

    for(;itr <= end; ++itr)
    {
        if(in[itr] == rootVal)
        {
            break;
        }
    }

    node->left = helper(pre,in,start,itr-1,pIdx);
    node->right = helper(pre,in,itr+1,end,pIdx);

    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    // if(preorderSize != inorderSize || preorder == NULL || inorder == NULL)
    // {
    //     return NULL;
    // }

    //struct TreeNode *node;
    int pIdx = 0;
    return helper(preorder,inorder,0,inorderSize-1,&pIdx);
}
