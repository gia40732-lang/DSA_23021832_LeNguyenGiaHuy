
#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int n;

    void init() {
        n = 0;
    }
    // O(1)

    int getAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Vi tri khong hop le!\n";
            return -1;
        }

        return data[i];
    }
    // O(1)

    void insertTail(int val) {
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }

        data[n] = val;
        n++;
    }
    // O(1)

    int deleteHead() {
        if (n == 0) {
            cout << "Danh sach rong!\n";
            return -1;
        }

        int val = data[0];

        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1];
        }

        n--;

        return val;
    }
    // O(n)

    bool isEmpty() {
        return n == 0;
    }
    // O(1)

    int size() {
        return n;
    }
    // O(1)
};

struct Queue {
    List l;

    void init() {
        l.init();
    }
    // O(1)

    bool isEmpty() {
        return l.isEmpty();
    }
    // O(1)

    void enqueue(int item) {
        l.insertTail(item);
    }
    // O(1)

    int dequeue() {
        return l.deleteHead();
    }
    // O(n)

    int size() {
        return l.size();
    }
    // O(1)

    int front() {
        return l.getAt(0);
    }
    // O(1)
};
