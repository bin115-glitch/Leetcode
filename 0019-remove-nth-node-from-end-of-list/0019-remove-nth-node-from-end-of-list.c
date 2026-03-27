/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Bước 1: fast đi trước n+1 bước
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Bước 2: cùng đi
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Bước 3: xóa node
    struct ListNode* temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}