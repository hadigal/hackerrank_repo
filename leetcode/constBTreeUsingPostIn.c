/********************************* lC 106************************************
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define NULL ((void *)(0))

typedef struct TreeNode TreeNode;

TreeNode *create(int val)
{
    TreeNode *node = (TreeNode *)calloc(1,sizeof(*node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode *helper(int *post, int *in, int start, int end, int *pIdx)
{
    if(start > end)
    {
        return NULL;
    }

    int rootVal = post[*pIdx];
    (*pIdx)--;

    TreeNode *node = create(rootVal);

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

    node->right = helper(post,in,itr+1,end,pIdx);
    node->left = helper(post,in,start,itr-1,pIdx);

    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int pIdx = postorderSize-1;
    //TreeNode *node = helper(postorder,inorder,0,inorderSize-1,&pIdx);
    return helper(postorder,inorder,0,inorderSize-1,&pIdx);;
}
