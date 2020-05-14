#pragma once
#include "../Common.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* curNode = head;
        ListNode *minNode = NULL;
        int minIndex = -1;
        while (true) {
            bool haveData = false;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i])
                    continue;

                haveData = true;
                auto node = lists[i];
                if (!minNode) {
                    minNode = node;
                    minIndex = i;
                }                    
                else if (node->val < minNode->val) {
                    minNode = node;
                    minIndex = i;
                }

            }

            if (!haveData)
                break;

            curNode->next = minNode;
            curNode = minNode;
            lists[minIndex] = lists[minIndex]->next;

            minNode = NULL;
        }

        return head->next;
    }
};

// ≤‚ ‘øÚº‹±ÿ±∏
vector<ListNode*> generateTestData() {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(4);
    n3->next = n4;

    return {n1, n2, n3};
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.mergeKLists(testData);
    ret = ret;
}