/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* build(struct ListNode* head, struct ListNode* tail) {
    if (head == tail) return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->val;

    root->left = build(head, slow);
    root->right = build(slow->next, tail);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return build(head, NULL);
}
    
