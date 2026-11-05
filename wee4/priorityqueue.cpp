
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxPQ {
private:
    vector<int> pq;
    int n;

    void exch(int i, int j) {
        swap(pq[i], pq[j]);
    }

    bool less(int i, int j) {
        return pq[i] < pq[j];
    }

    void swim(int k) {
        while (k > 1 && less(k / 2, k)) {
            exch(k, k / 2);
            k = k / 2;
        }
    }

    void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;

            if (j < n && less(j, j + 1)) {
                j++;
            }

            if (!less(k, j)) {
                break;
            }

            exch(k, j);
            k = j;
        }
    }

public:
    MaxPQ() {
        pq.push_back(0);
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    int getMax() {
        if (isEmpty()) {
            throw underflow_error("Priority Queue rong!");
        }

        return pq[1];
    }

    void insert(int x) {
        pq.push_back(x);
        n++;

        swim(n);
    }

    int delMax() {
        if (isEmpty()) {
            throw underflow_error("Priority Queue rong!");
        }

        int maxValue = pq[1];

        exch(1, n);

        pq.pop_back();
        n--;

        if (n > 0) {
            sink(1);
        }

        return maxValue;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxPQ pq;

    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);
    pq.insert(40);
    pq.insert(5);

    cout << "Max Heap: ";
    pq.display();

    cout << "Phan tu lon nhat: "
         << pq.getMax() << endl;

    cout << "Xoa phan tu lon nhat: "
         << pq.delMax() << endl;

    cout << "Heap sau khi xoa: ";
    pq.display();

    cout << "So phan tu hien tai: "
         << pq.size() << endl;

    return 0;
}
