/**
 * C++ 语言: 二叉查找树
 *
 * @author skywang
 * @date 2013/11/07
 */

#include <iostream>
#include "stdafx.h"
#include "BSTree.h"
using namespace std;

static int arr[]= {1,5,4,3,2,6};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

// 获取前驱和后继
void GetPrevNext(BSTNode<int> *tag, BSTNode<int> *now, BSTNode<int> *&pre, std::pair<BSTNode<int> *, BSTNode<int> *> & ans)
{   
    if (now == NULL)
        return;

    GetPrevNext(tag, now->left, pre, ans);

    if (now == tag)
        ans.first = pre;
    else if (pre == tag)
        ans.second = now;

    pre = now;
    GetPrevNext(tag, now->right, pre, ans);
}

int main()
{
    int i, ilen;
    BSTree<int>* tree=new BSTree<int>();

    cout << "== 依次添加: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++) 
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    std::pair<BSTNode<int> *, BSTNode<int> *> ans;
    BSTNode<int> *pre = NULL;
    BSTNode<int> *root = tree->search(1);
    BSTNode<int> *tag = tree->search(4);
    GetPrevNext(tag, root, pre, ans);

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    cout << "\n== 删除根节点: " << arr[3];
    tree->remove(arr[3]);

    cout << "\n== 中序遍历: ";
    tree->inOrder();
    cout << endl;

    // 销毁二叉树
    tree->destroy();

    return 0;
}