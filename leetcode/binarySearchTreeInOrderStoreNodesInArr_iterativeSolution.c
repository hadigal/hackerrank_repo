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

// Used stack to implement this solution - o(n) space complexity

void push(struct TreeNode **stack,int32_t *topFlg, struct TreeNode *node)
{
    *topFlg += 1;
    stack[*topFlg] = node;
    return;
}

struct TreeNode *pop(struct TreeNode **stack,int32_t *topFlg)
{
    struct TreeNode *node = stack[*topFlg];
    stack[*topFlg] = NULL;
    *topFlg -= 1;
    return node;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *arr = (int *)calloc(1,sizeof(*arr));
    uint32_t size = 1;

    struct TreeNode *itr = root;

    struct TreeNode **stack = (struct TreeNode **)calloc(1,sizeof(*stack));
    uint32_t stackSize = 1;

    int32_t topFlg = -1;

    while(itr != NULL || topFlg != -1)
    {
        while(itr != NULL)
        {
            if(stackSize > 1)
            {
                stack = realloc(stack,sizeof(*stack)*stackSize);
            }
            push(stack,&topFlg,itr);
            itr = itr->left;
            ++stackSize;
        }
        itr = pop(stack,&topFlg);
        arr = (int *)realloc(arr,sizeof(*arr)*size);
        arr[size-1] = itr->val;
        ++size;
        itr = itr->right;
    }
    // for(size_t i = 0; i < size-1; ++i)
    // {
    //     printf("arr[%d]:%d\n",i,arr[i]);
    // }
    free(stack);
    *returnSize = size - 1;
    return arr;
}
