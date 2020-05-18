#pragma once
#include "../Common.h"


// 下面部分拷贝到答题区域

class Solution {
public:
    long last = INT_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        last--;

        return preOrder(root);
    }

    bool preOrder(TreeNode* root) {
        if (!root)
            return true;

        if (!preOrder(root->left))
            return false;

        if (last >= root->val)
            return false;

        last = root->val;
        return preOrder(root->right);
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
TreeNode * generateTestData() {
    vector<int> ret = { -1,0,1,2,-1,-4 };
    TreeNode*t1 = new TreeNode(1);
    TreeNode*t2 = new TreeNode(1);
    t1->right = t2;
    return t1;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.isValidBST(testData);
    ret = ret;
}