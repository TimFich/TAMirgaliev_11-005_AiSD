/*
#include <iostream>

using namespace std;

void sort(int *a, int size) {
    for (int *p = a; p < a + size; ++p) {
        if (*p <= 2) {
            *p = 0;
        }
        cout << *p << " ";
    }
}

void enterArray_2(int *a, int size) {

    for (int *p = a; p < a + size; p++) {
        cin >> *p;
    }
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    enterArray_2(a, n);
    sort(a, n);
    return 0;

}*/