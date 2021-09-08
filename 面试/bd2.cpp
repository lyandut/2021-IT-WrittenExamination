/* 查找链表中点 */

ListNode* func(ListNode* root) {
    if(!root || !root->next) return root;
    auto fast = root, slow = root;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}