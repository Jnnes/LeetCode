
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include<unordered_set>
#include<math.h>

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

    Node() {}

        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class NodeEx {
public:
    int val;
    vector<NodeEx*> children;

    NodeEx() {}

    NodeEx(int _val, vector<NodeEx*> _children) {
        val = _val;
        children = _children;
    }
};

struct Point
{
    int x;
    int y;
    Point(int x, int y) :x(x), y(y) {}
};

void  Print(vector<Point> &PointList) {
    for (int i = 0; i < PointList.size(); i++) {
        std::cout << PointList[i].x << " " << PointList[i].y << std::endl;
    }
    std::cout << std::endl << std::endl;
}



class Solution {
public:
    int findShortestSubArray(vector<int> nums) {
        map<int, pair<int, pair<int, int>>> mn;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mn.find(num) != mn.end()) {
                mn[num].first++;
                //mn[num].second.second = i;
                auto t = mn[num].second;
                t.second = i;

                auto p = t;
            }
            else {
                mn[num] = make_pair(1, make_pair(i, i));
            }
        }

        int mf = 0;
        int ml = 0;
        for (auto iter = mn.begin(); iter != mn.end(); iter++) {
            int f = iter->second.first;
            int l = iter->second.second.second - iter->second.second.first + 1;
            if (f > mf) {
                ml = l;
                mf = f;
            }
            else if (f == mf) {
                ml = min(ml, l);
            }
        }

        return ml;
    }
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
    // Ñ°ÕÒ×î³¤×Ó´®
    string newstr;
    vector<int> p;

    // Íù×Ö·û´®ÖÐ²åÈë#
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
}

int main() {
    auto temp = PlalindromeString("cc");
#if true
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2); n1->next = n2;
    ListNode *n3 = new ListNode(3); n2->next = n3;
    ListNode *n4 = new ListNode(4); n3->next = n4;
    ListNode *n5 = new ListNode(5); n4->next = n5;

    ListNode *n6 = new ListNode(5); //n5->next = n6;
    ListNode *n7 = new ListNode(0); //n6->next = n7;
    ListNode *n8 = new ListNode(1); n7->next = n8; n8->next = n3;


    TreeNode *T1 = new TreeNode(1);
    TreeNode *T2 = new TreeNode(2);
    TreeNode *T3 = new TreeNode(3);
    TreeNode *T4 = new TreeNode(4);
    TreeNode *T5 = new TreeNode(5);
    TreeNode *T6 = new TreeNode(6);
    TreeNode *T7 = new TreeNode(7);
    T1->left = T2; 
    T1->right = T3;
    T2->left = T4; 
    T2->right = T5;
    //T3->left = T4; //T3->right = T7;
    //T4->left = T5;

    NodeEx *e1 = new NodeEx();
    NodeEx *e2 = new NodeEx();
    NodeEx *e3 = new NodeEx();
    NodeEx *e4 = new NodeEx();
    NodeEx *e5 = new NodeEx();
    NodeEx *e6 = new NodeEx();
    e1->val = 1; e1->children = { e3,e2,e4 };
    e2->val = 2;
    e3->val = 3; e3->children = { e5, e6 };
    e4->val = 4;
    e5->val = 5;
    e6->val = 6;

#endif
    stack<int> st;
    st.empty();
    st.size();

    Solution so;
    vector<string> vecStr = { "aa", "a" };
    vector<int> vecInt1 = { 4, 1, 2};
    vector<int> vecInt2 = { 1, 4, 3, 2 };
    vector<vector<int>> vvecint1 = {
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0} };
    vector<vector<int>> vvecint2 = { {1,3,1},{1,5,1} ,{4,2,1} };

    vector<string> vecstr = { 
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com" };
    vector<char> vecchar = { 'a', 'a', 'b', 'b', 'c', 'c','c' };
    vector<int> vecvec = { 0 };
    auto ret = so.findShortestSubArray({ 1, 2, 2, 3, 1 });
    set<int> seti;
    string a = "12345";
    auto c =a.substr(0, 1);
    auto b = a.find('5');
    MyStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.pop();
    typedef pair<int, int> pairii;
    //unordered_set<vector<int> *> obstacleSet;
    pairii jk = { 1,1 };
    //obstacleSet.insert(move(make_pair(1,1)));
    queue<int> q;
    q.push(1);
    auto aa = find(vecInt1.begin() + 2, vecInt1.end(), 5);
    rand();
    vector<vector<int>> asda(3, vector<int> (3));
    return 0;
}