
#include <iostream>
using namespace std;

const int MAX = 100;

void quickSort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(a, left, j);
    }

    if (i < right) {
        quickSort(a, i, right);
    }
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

    quickSort(a, 0, n - 1);

    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
