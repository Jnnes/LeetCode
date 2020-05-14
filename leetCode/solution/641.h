#pragma once
#include "../Common.h"

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data_ = vector<int>(k);
        capcity_ = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        else {
            head_++;
            size_++;
            data_[_getIndex(head_ - 1)] = value;
            return true;
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        else {
            tail_--;
            size_++;
            data_[_getIndex(tail_)] = value;
            return true;
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        else {
            head_--;
            size_--;
            return true;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        else {
            tail_++;
            size_--;
            return true;
        }
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;

        return data_[_getIndex(head_ - 1)];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;

        return data_[_getIndex(tail_)];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size_ == capcity_;
    }
    
private:
    vector<int> data_;
    int head_ = 0;
    int tail_ = 0;
    int capcity_ = 0;
    int size_ = 0;

    int _getIndex(int index) {
        return (index + capcity_) % capcity_;
    }
};


class Solution {
public:
    int run() {
        // Your MyCircularDeque object will be instantiated and called as such:
        MyCircularDeque circularDeque(3); // ����������СΪ3
        circularDeque.insertLast(1);			        // ���� true
        circularDeque.insertLast(2);			        // ���� true
        circularDeque.insertFront(3);			        // ���� true
        circularDeque.insertFront(4);			        // �Ѿ����ˣ����� false
        circularDeque.getRear();  				// ���� 2
        circularDeque.isFull();				        // ���� true
        circularDeque.deleteLast();			        // ���� true
        circularDeque.insertFront(4);			        // ���� true
        circularDeque.getFront();				// ���� 4
        return 0;
    }
};


// ���Կ�ܱر�
vector<string> generateTestData() {
    auto ret = vector<string>{ "4", "13", "5", "/", "+" };
    return ret;
}

void run(Solution so) {
    //auto testData = generateTestData();

    // do algrithme
    auto ret = so.run();
    ret = ret;
}