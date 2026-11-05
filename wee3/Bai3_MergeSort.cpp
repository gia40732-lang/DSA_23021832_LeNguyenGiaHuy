
#include <iostream>
using namespace std;

const int MAX = 100;

void merge(int a[], int left, int mid, int right) {
    int temp[MAX];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++) {
        a[left + p] = temp[p];
    }
}

void mergeSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}

int main() {
    int a[MAX];
    int n;

    cout << "Nhap so phan tu: ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "So phan tu khong hop le!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
