
#include <iostream>
using namespace std;

const int MAX = 1000;

int a[MAX + 1];
int n = 0;

void exch(int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

bool lessValue(int i, int j) {
    return a[i] < a[j];
}

void swim(int k) {
    while (k > 1 && lessValue(k / 2, k)) {
        exch(k, k / 2);
        k = k / 2;
    }
}

void sink(int k) {
    while (2 * k <= n) {
        int j = 2 * k;

        if (j < n && lessValue(j, j + 1))
            j++;

        if (!lessValue(k, j))
            break;

        exch(k, j);
        k = j;
    }
}

void insert(int x) {
    if (n == MAX) return;

    a[++n] = x;
    swim(n);
}

int getMax() {
    if (n == 0) return -1;

    return a[1];
}

int extractMax() {
    if (n == 0) return -1;

    int maxValue = a[1];

    exch(1, n);
    n--;

    if (n > 0)
        sink(1);

    return maxValue;
}

void deleteAt(int k) {
    if (k < 1 || k > n) return;

    exch(k, n);
    n--;

    if (k > n) return;

    if (k > 1 && lessValue(k / 2, k))
        swim(k);
    else
        sink(k);
}

int search(int x) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == x)
            return i;
    }

    return -1;
}

void increaseKey(int k, int x) {
    if (k < 1 || k > n || x < a[k])
        return;

    a[k] = x;
    swim(k);
}

void decreaseKey(int k, int x) {
    if (k < 1 || k > n || x > a[k])
        return;

    a[k] = x;
    sink(k);
}

void buildHeap() {
    for (int k = n / 2; k >= 1; k--)
        sink(k);
}

bool isMaxHeap() {
    for (int i = 1; i <= n / 2; i++) {
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l <= n && a[i] < a[l])
            return false;

        if (r <= n && a[i] < a[r])
            return false;
    }

    return true;
}

void display() {
    if (n == 0) {
        cout << "Heap rong!\n";
        return;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main() {
    int choice, x, k;

    do {
        cout << "\n===== PRIORITY QUEUE MAX HEAP =====\n";
        cout << "1. Insert\n";
        cout << "2. Get Max\n";
        cout << "3. Extract Max\n";
        cout << "4. Delete at index\n";
        cout << "5. Search\n";
        cout << "6. Increase Key\n";
        cout << "7. Decrease Key\n";
        cout << "8. Build Heap\n";
        cout << "9. Display\n";
        cout << "10. Check Max Heap\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                if (n == 0)
                    cout << "Heap rong!\n";
                else
                    cout << "Max = " << getMax() << endl;
                break;

            case 3:
                if (n == 0)
                    cout << "Heap rong!\n";
                else
                    cout << "Da xoa: " << extractMax() << endl;
                break;

            case 4:
                cout << "Nhap index: ";
                cin >> k;
                deleteAt(k);
                break;

            case 5:
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                k = search(x);

                if (k == -1)
                    cout << "Khong tim thay!\n";
                else
                    cout << "Tim thay tai index: " << k << endl;
                break;

            case 6:
                cout << "Nhap index va gia tri moi: ";
                cin >> k >> x;
                increaseKey(k, x);
                break;

            case 7:
                cout << "Nhap index va gia tri moi: ";
                cin >> k >> x;
                decreaseKey(k, x);
                break;

            case 8:
                buildHeap();
                cout << "Da Build Heap!\n";
                break;

            case 9:
                display();
                break;

            case 10:
                if (isMaxHeap())
                    cout << "La Max Heap!\n";
                else
                    cout << "Khong phai Max Heap!\n";
                break;

            case 0:
                cout << "Ket thuc!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
