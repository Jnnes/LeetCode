#pragma once
#include "../BaseSolution.h"
#include "../Common.h"

int getDecimalValue(ListNode* head) {    
    int ret = 0;
    while (head)
    {
        ret *= 2;
        ret += head->val;
        head = head->next;
    }

    return ret;
}

class GetDecimal :public BaseSolution
{
public:
    void init(void);
    void run(void);
    void result(void);
};

void GetDecimal::init() {
}

void GetDecimal::run() {
    cout << "½á¹ûÎª£º" << endl;
    
}

void GetDecimal::result() {
}