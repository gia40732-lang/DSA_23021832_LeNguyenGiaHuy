
#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int a[MAX];
    int n;

    cout << "Nhap so phan tu (so le): ";
    cin >> n;

    if (n <= 0 || n > MAX || n % 2 == 0) {
        cout << "So phan tu phai la so le va nam trong khoang 1 den 100!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nTrung vi: " << a[n / 2] << endl;

    return 0;
}
