#pragma once
#include "../BaseSolution.h"
#include "../custom.h"

class ReverseListSo:public BaseSolution
{
public:
    ListNode* reverseList(ListNode* head);
    void init(void);
    void run(void );
    void result(void);
    ListNode * root;
};

void ReverseListSo::init() {
    // 准备测试数据
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2); n1->next = n2;
    ListNode *n3 = new ListNode(3); n2->next = n3;
    ListNode *n4 = new ListNode(4); n3->next = n4;
    ListNode *n5 = new ListNode(5); n4->next = n5;
    root = n1;
    Print(root);
}

void ReverseListSo::run() {
    // 执行测试算法
    root = reverseList(root);
}

void ReverseListSo::result() {
    // 打印结果
    Print(root);
}

ListNode* ReverseListSo::reverseList(ListNode* head) {
    if (!head) {
        return NULL;
    }

    ListNode *root;
    if (head->next) {
        root = reverseList(head->next);
        head->next->next = head;
    }
    else {
        root = head;
    }

    head->next = NULL;
    return root;
}