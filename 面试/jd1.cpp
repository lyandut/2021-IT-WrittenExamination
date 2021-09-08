/* 19. 删除链表的倒数第 N 个结点 */

struct Node {
    int val;
    Node* next;
};


Node* func(Node* root, int k) {
    auto fast = root, slow = root;
    for(int i=0; i<k; ++i) {
        if(fast) fast = fast->next;
        else return root;
    }
    if(!fast) return root->next;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return root;
}
