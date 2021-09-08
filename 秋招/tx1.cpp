/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向这些数链的开头
     * @return ListNode类
     */
    ListNode* solve(vector<ListNode*>& a) {
        int cnt = 0;
        for(auto aa : a) {
            auto curr = aa;
            int tmp = 0;
            while(curr) {
                curr = curr->next;
                tmp++;
            }
            cnt = max(cnt, tmp);
        }
        ListNode* dummy = new ListNode(-1);
        auto curr = dummy;
        for(int i=0; i<cnt; ++i) {
            for(auto& aa : a) {
                if(aa == nullptr) continue;
                curr->next = aa;
                curr = curr->next;
                aa = aa->next;
            }
        }
        return dummy->next;
    }
};