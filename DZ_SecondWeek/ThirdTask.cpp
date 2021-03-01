#include <iostream>

using namespace std;

void sort(int *a, int size) {
    int temp = 0;
    for (int out = size - 1; out > 0; --out) {
        for (int in = 0; in < out; ++in) {
            if (*(a + in) > *(a + in + 1)) {
                temp = *(a + in);
                *(a + in) = *(a + in + 1);
                *(a + in + 1) = temp;
            }
        }
    }
}

void enterArray_2(int *a, int size) {

    for (int *p = a; p < a + size; p++) {
        cin >> *p;
    }
}

void outPut(int *a, int size) {
    for (int *p = a; p < a + size; ++p) {
        cout << *p << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    enterArray_2(a, n);
    sort(a, n);
    outPut(a , n);
    return 0;
}
