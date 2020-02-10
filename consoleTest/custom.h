/*
    各种常用数据结构定义
    常用函数定义
*/

#pragma once

#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {};

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    };
};

class NodeEx {
    public:
        int val;
        std::vector<NodeEx*> children;

        NodeEx() {};

        NodeEx(int _val, std::vector<NodeEx*> _childrens) {
            val = _val;
            children = _childrens;
        };
};

struct Point
{
    int x;
    int y;
    Point(int x, int y) :x(x), y(y) {};
};

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size() - 1;
        while (size--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        int top = q.front();
        q.pop();
        return top;
    }

    /** Get the top element. */
    int top() {
        int size = q.size() - 1;
        while (size--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }


        int top = q.front();
        q.pop();
        q.push(top);
        return top;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int size = st.size() - 1;
        int res = 0;

        stack<int> tempst;
        while (size--) {
            res = st.top();
            st.pop();
            tempst.push(res);
        }

        size = tempst.size();
        while (size--) {
            int temp = tempst.top();
            tempst.pop();
            st.push(temp);
        }

        return res;
    }

    /** Get the front element. */
    int peek() {
        int size = st.size();
        int res = 0;

        stack<int> tempst;
        while (size--) {
            res = st.top();
            st.pop();
            tempst.push(res);
        }

        size = tempst.size();
        while (size--) {
            int temp = tempst.top();
            tempst.pop();
            st.push(temp);
        }

        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

string PlalindromeString(string str) {
    // 寻找最长子串
    string newstr;
    vector<int> p;

    // 往字符串中插入#
    for (int i = 0; i < str.length(); i++) {
        newstr.push_back(str[i]);
        newstr.push_back('#');
        p.push_back(0);
        p.push_back(0);
    }
    newstr.pop_back();
    p.pop_back();

    int right = 0;
    int mid = 0;
    int longest = 0;
    int longestIndex = 0;
    for (int i = 0; i < newstr.size(); i++) {
        bool needExt = true;
        if (i < right) {
            int j = mid * 2 - i;
            if (i + p[j] < right) {
                p[i] = p[j];
                needExt = false;
            }
            else
            {
                p[i] = right - i;
            }
        }

        if (needExt) {
            while (i + p[i] + 1 < newstr.length() && i - p[i] - 1 >= 0) {
                if (newstr[i + p[i] + 1] == newstr[i - p[i] - 1])
                    p[i]++;
                else
                    break;
            }

            right = i + p[i];
            mid = i;

            if (p[i] > longest) {
                longest = p[i];
                longestIndex = i;
            }
        }
    }

    string ret = "";
    for (int i = longestIndex - longest; i <= longest + longestIndex; i++) {
        if (newstr[i] != '#')
            ret.push_back(newstr[i]);
    }

    return ret;
};

void  Print(vector<Point> &PointList) {
    for (int i = 0; i < PointList.size(); i++) {
        std::cout << PointList[i].x << " " << PointList[i].y << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void Print(ListNode * root) {
    if (!root) {
        std::cout << "NULL"<< std::endl;
    }
    else
    {
        std::cout << root->val << " -> ";
        Print(root->next);
    }
}