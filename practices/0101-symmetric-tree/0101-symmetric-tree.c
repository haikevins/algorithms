/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return true;
    }

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    // Use a stack to perform iterative traversal
    struct TreeNode** stack = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int top = -1;

    // Push the left and right children onto the stack
    stack[++top] = left;
    stack[++top] = right;

    while (top >= 0) 
    {
        struct TreeNode* node1 = stack[top--];
        struct TreeNode* node2 = stack[top--];

        if (node1 == NULL && node2 == NULL) 
        {
            continue;
        }
        if (node1 == NULL || node2 == NULL) 
        {
            free(stack);
            return false;
        }
        if (node1->val != node2->val) 
        {
            free(stack);
            return false;
        }

        // Push the children in opposite order for symmetry check
        stack[++top] = node1->left;
        stack[++top] = node2->right;

        stack[++top] = node1->right;
        stack[++top] = node2->left;
    }

    free(stack);
    return true;
}