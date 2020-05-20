#pragma once
#pragma once
#include "../Common.h"


// ���沿�ֿ�������������

class Solution {
public:
    /*
        52. ��������ĵ�һ�������ڵ�
        һ�ַǳ��������д�����������ҵ����Ȳ�࣬Ȼ��ƫ�Ʋ����ͬ�������ң�����й����ڵ���ô�϶��ܹ��ҵ�һ����
        
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode * pa = headA, *pb = headB;

        int cnta = 0;
        while (pa) {
            cnta++;
            pa = pa->next;
        }

        int cntb = 0;
        while (pb) {
            cntb++;
            pb = pb->next;
        }

        int diff = abs(cnta - cntb);
        pa = headA, pb = headB;
        if (cnta > cntb) {
            while (diff--)
                pa = pa->next;
        }
        else {
            while (diff--)
                pb = pb->next;
        }

        while (pa != pb && pa != NULL) {
            pa = pa->next;
            pb = pb->next;
        }

        return pa;
    }
};
// ���沿�ֿ�������������


// ���Կ�ܱر�
string generateTestData() {
    return "leetcodeisgreat";
}

void run(Solution so) {
    //auto testData = generateTestData();
    //auto ret = so.getIntersectionNode(testData);
    //ret = ret;
}