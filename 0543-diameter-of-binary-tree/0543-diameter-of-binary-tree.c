/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root, int* diameter) {
    if (root == NULL) {
        return 0;  
    }

    int leftHeight = height(root->left, diameter);   
    int rightHeight = height(root->right, diameter); 
    *diameter = fmax(*diameter, leftHeight + rightHeight);
    return 1 + fmax(leftHeight, rightHeight);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    height(root, &diameter); 
    return diameter;  
}
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}