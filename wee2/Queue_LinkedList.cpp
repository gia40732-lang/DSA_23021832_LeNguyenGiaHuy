
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
    int n;

    void init() {
        head = nullptr;
        tail = nullptr;
        n = 0;
    }
    // O(1)

    Node* createNode(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        return newNode;
    }
    // O(1)

    int getAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Vi tri khong hop le!\n";
            return -1;
        }

        Node* temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }

        return temp->data;
    }
    // O(n)

    void insertTail(int val) {
        Node* newNode = createNode(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        n++;
    }
    // O(1)

    int deleteHead() {
        if (head == nullptr) {
            cout << "Danh sach rong!\n";
            return -1;
        }

        Node* temp = head;
        int val = temp->data;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        n--;

        return val;
    }
    // O(1)

    bool isEmpty() {
        return n == 0;
    }
    // O(1)

    int size() {
        return n;
    }
    // O(1)

    void clear() {
        while (head != nullptr) {
            deleteHead();
        }
    }
    // O(n)
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
    // O(1)

    int size() {
        return l.size();
    }
    // O(1)

    int front() {
        if (l.isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        return l.head->data;
    }
    // O(1)

    void clear() {
        l.clear();
    }
    // O(n)
};
