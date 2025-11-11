#include <stdlib.h> 

/**
 * @brief 
 * @param nums 
 * @param left 
 * @param right 
 * @return 
 */
struct TreeNode* buildRecursive(int* nums, int left, int right) {
    
    if (left > right) {
        return NULL;
    }

    int maxIdx = left;
    int maxVal = nums[left];
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIdx = i;
        }
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = maxVal;

    root->left = buildRecursive(nums, left, maxIdx - 1);
    
    root->right = buildRecursive(nums, maxIdx + 1, right);

    return root;
}

/**
 * @brief
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    
    return buildRecursive(nums, 0, numsSize - 1);
}