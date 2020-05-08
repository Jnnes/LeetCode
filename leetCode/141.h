#pragma once
#include "Common.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;

        ListNode *fast, *slow;
        fast = head->next;
        slow = head;

        while (fast != NULL && fast ->next != NULL) {
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};

// ²âÊÔ¿ò¼Ü±Ø±¸
ListNode* generateTestData() {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2); n1->next = n2;
    ListNode* n3 = new ListNode(0); n2->next = n3;
    ListNode* n4 = new ListNode(4); n3->next = n4;
    //n4 -> next = n2;

    return n1;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.hasCycle(testData);
    ret = ret;
}