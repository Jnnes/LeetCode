#pragma once
#include "../Common.h"

class ReverseListSo:public BaseSolution
{
public:
    ListNode* reverseList(ListNode* head);
    ListNode* reverseList1(ListNode* head);
    void init(void);
    void run(void );
    void result(void);
    std::string getTAG();
    ListNode * root;
    

private:
    std::string TAG = "ReverseListSo";
};

std::string ReverseListSo::getTAG() {
    return TAG;
}

void ReverseListSo::init() {
    // 准备测试数据
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2); n1->next = n2;
    ListNode *n3 = new ListNode(3); n2->next = n3;
    ListNode *n4 = new ListNode(4); n3->next = n4;
    ListNode *n5 = new ListNode(5); n4->next = n5;
    root = n1;
    print(root);
}

void ReverseListSo::run() {
    // 执行测试算法
    root = reverseList(root);
}

void ReverseListSo::result() {
    // 打印结果
    print(root);
}

// 链表反转：递归
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

// 链表反转：迭代
ListNode* ReverseListSo::reverseList1(ListNode* head) {
    ListNode* last, *cur, *pre;
    last = NULL;
    cur = head;
    pre = NULL;

    while (cur) {
        pre = cur->next;

        cur->next = last;

        last = cur;
        cur = pre;
    }

    return last;
}