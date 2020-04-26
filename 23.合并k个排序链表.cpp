/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }
        if (size == 1) {
            return lists[0];
        }
        queue<ListNode*> waiting(deque<ListNode*>(lists.begin(), lists.end())); //将vector转为队列
        //如果队列元素大于1，则取出两个进行合并，合并后的链表继续添加到链表尾部
        while (waiting.size() > 1) {
            ListNode *l1 = waiting.front();
            waiting.pop();
            ListNode *l2 = waiting.front();
            waiting.pop();
            waiting.push(merge2(l1, l2));
        } 
        return waiting.front();
    }
    ListNode* merge2(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }
};
// @lc code=end