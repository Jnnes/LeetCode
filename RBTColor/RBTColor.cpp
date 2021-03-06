// RBTColor.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
#include "stdafx.h"

using namespace std;

enum RBTColor { RED, BALCK };

template<class T>
class RBTNode {
public :
    RBTColor color;
    T key;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;
    RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r):key(value),color(c),left(l),right(r),parent(){}
};

template <class T>
class RBTree {
private:
    RBTNode<T> * mRoot;

public:
    RBTree();
    ~RBTree();

    void preOrder();
    void inOrder();
    void postOrder();

    RBTNode<T> * search(T key);
    RBTNode<T> * iterativeSearch(T key);

    T minimum();
    T maximum();

    RBTNode<T> * successor(RBTNode<T> * x);
    RBTColor<T> * predecessor(RBTNode<T> *x);

    void insert(T key);
    void remove(T key);
    void destory();
    void print();

private:
    void preOrder(RBTNode<T> *tree) const;
    void inOrder(RBTNode<T> *tree) const;
    void postOrder(RBTNode<T> *tree) const;

    RBTNode<T> * search(RBTNode *x, T key) const;
    RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

    // 查找最小结点：返回tree为根结点的红黑树的最小结点。
    RBTNode<T>* minimum(RBTNode<T>* tree);
    // 查找最大结点：返回tree为根结点的红黑树的最大结点。
    RBTNode<T>* maximum(RBTNode<T>* tree);

    // 左旋
    void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
    // 右旋
    void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
    // 插入函数
    void insert(RBTNode<T>* &root, RBTNode<T>* node);
    // 插入修正函数
    void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
    // 删除函数
    void remove(RBTNode<T>* &root, RBTNode<T> *node);
    // 删除修正函数
    void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

    // 销毁红黑树
    void destroy(RBTNode<T>* &tree);

    // 打印红黑树
    void print(RBTNode<T>* tree, T key, int direction);
};

#define rb_parent(r) ((r) -> parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)

template <class T>
void RBTree<T>::leftRotate(RBTNode<T> *&root, RBTNode<T> *x) {
    RBTNode<T> *y = x->right;

    if (y == NULL)
        return;

    x->right = y->left
    if(y->left != NULL )
        y->left->parent = x

    if (rb_parent(x) != NULL){
        if (rb_parent(x)->left == x)
            rb_parent(x)->left = y;
        else 
            rb_parent(x)->right = y;

        rb_set_parent(y, rb_parent(x));
        x->parent = y;
        y->left = x;
    }
    else
        root = y;
}

int main()
{
    return 0;
}

