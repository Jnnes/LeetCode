#pragma once
#include "../BaseSolution.h"
#include "../Common.h"

class Sort :public BaseSolution
{
private :
    int *testArr;

public:
    static const string MAOPAO;
    static const string INSERT;
    static const string MERGE;
    static const string QUICK;

    void init(void);
    void run(void);
    void run(string);
    void result(void);

    // 冒泡
    void maopao(int a[], int n) {
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    flag = true;
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }

            if (!flag)
                break;
        }
    }

    // 插入
    void insertSort(int a[], int n) {
        if (n <= 1) return;

        for (int i = 1; i < n; i++) {
            int value = a[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (a[j] > value) {
                    a[j + 1] = a[j];
                }
                else
                    break;
            }

            a[j + 1] = value;
        }
    }

    // 合并两个数组
    void merge(int a[], int left, int center, int right) {
        int *m = (int *)malloc((right - left + 1) * sizeof(int));
        int i = left, j = center + 1;
        int index = 0;
        while (i <= center && j <= right) {
            if (a[j] < a[i])
                m[index++] = a[j++];
            else
                m[index++] = a[i++];
        }

        while (i <= center)
        {
            m[index++] = a[i++];
        }

        while (j <= right)
        {
            m[index++] = a[j++];
        }

        for (int i = 0; i < index; i++) {
            a[left + i] = m[i];
        }

    }

    // 归并
    void mergeSort(int a[], int left, int right) {
        if (left == right) return;

        int center = (left + right) / 2;
        mergeSort(a, left, center);
        mergeSort(a, center + 1, right);
        merge(a, left, center, right);
    }

    int part(int a[], int left, int right) {
        int value = a[right];
        int i = left, j = left;
        while (j < right) {
            if (a[j] < value) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
            }

            j++;
        }

        a[right] = a[i];
        a[i] = value;
        return i;
    }

    // 快速排序
    void quickSort(int a[], int left, int right) {
        if (left >= right) return;

        int p = part(a, left, right);
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
};

const string Sort::MAOPAO = "冒泡排序";
const string Sort::INSERT = "插入排序";
const string Sort::MERGE = "归并排序";
const string Sort::QUICK = "快速排序";

void Sort::init() {
    this->testArr = (int *)malloc(6 * sizeof(int));

    this->testArr[0] = 3;
    this->testArr[1] = 2;
    this->testArr[2] = 4;
    this->testArr[3] = 5;
    this->testArr[4] = 6;
    this->testArr[5] = 1;

    cout << "测试数据：" << endl;
    print(this->testArr, 6);
}

void Sort::run() {
    cout << "默认算法：" << endl;
    this->run(this->QUICK);
}

void Sort::run(string str) {
    cout << "运行算法："<< str << endl;

    if (str == this->QUICK) {
        quickSort(this->testArr, 0, 5);
    }
    else if (str == this->MAOPAO) {
        maopao(this->testArr, 6);
    }
    else if (str == this->MERGE) {
        mergeSort(this->testArr, 0, 5);
    }
    else if (str == this->INSERT) {
        insertSort(this->testArr, 6);
    }    
}

void Sort::result() {
    cout << "结果为：" << endl;    
    print(this->testArr, 6);
}