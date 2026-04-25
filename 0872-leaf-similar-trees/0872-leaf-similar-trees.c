/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void collectLeaves(struct TreeNode* root, int* leaves, int* index) {
    if (root == NULL) {
        return;
    }
        if (root->left == NULL && root->right == NULL) {
        leaves[*index] = root->val;
        (*index)++;
        return;
    }
    collectLeaves(root->left, leaves, index);
    collectLeaves(root->right, leaves, index);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[100], leaves2[100];  // Arrays to store leaf values
    int index1 = 0, index2 = 0;
        collectLeaves(root1, leaves1, &index1);
    collectLeaves(root2, leaves2, &index2);
    
    if (index1 != index2) {
        return false;  
    }

    for (int i = 0; i < index1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;  
        }
    }

    return true; 
}