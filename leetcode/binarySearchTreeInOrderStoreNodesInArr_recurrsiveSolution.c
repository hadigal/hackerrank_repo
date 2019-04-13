/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int *arr;
static uint32_t size;

int inOrder(struct TreeNode *root, uint32_t currSize)
{
    if(root == NULL)
    {
        return currSize;
    }
    //printf("currSize:%d\n",currSize);
    currSize = inOrder(root->left,currSize);
    arr = (int *)realloc(arr,sizeof(*arr)*currSize);
    *(arr+currSize-1) = root->val;
    currSize += 1;
    currSize = inOrder(root->right,currSize);
    return currSize;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    arr = (int *)calloc(1,sizeof(*arr));
    size = 1;
    // the size returned here is one more than the actual size of the returned arr!!!
    // therefore store the value as size - 1!!
    size = inOrder(root,size);
    //printf("size:%d\n",size);
    // for(size_t itr = 0; itr < size-1; ++itr)
    // {
    //     printf("arr[%d]:%d\n",itr,arr[itr]);
    // }
    *returnSize = size-1;
    return arr;
}
