#include <iostream>
#include <vector>
using namespace std;

void exch(vector<int>& a, int i, int j) {
    swap(a[i], a[j]);
}

void sink(vector<int>& a, int k, int n) {
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;

        if (j + 1 < n && a[j] < a[j + 1]) {
            j++;
        }

        if (a[k] >= a[j]) {
            break;
        }

        exch(a, k, j);
        k = j;
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();

    for (int k = n / 2 - 1; k >= 0; k--) {
        sink(a, k, n);
    }

    while (n > 1) {
        exch(a, 0, n - 1);
        n--;
        sink(a, 0, n);
    }
}

void display(const vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a = {12, 5, 8, 20, 3, 15, 10, 1};

    cout << "Mang ban dau: ";
    display(a);

    heapSort(a);

    cout << "Mang sau khi sap xep: ";
    display(a);

    return 0;
}
