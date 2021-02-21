#include  <iostream>

using namespace std;

void sumArray(int pointer, int *p1, int *p2, int *p3, int length) {
    for (int i = 0; i < pointer; i++) {
        *(p3 + i) = *(p1 + i);
    }
    for (int i = 0; i < length; i++) {
        *(p3 + i + pointer) = *(p2 + i);
        cout << *(p3 + i) << " ";
    }
}

void enterArray_1(int *a, int size) {

    for (int *p = a; p < a + size; p++) {
        cin >> *p;
    }

}

int main() {
    int n;
    int m;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    int *c = new int[m + n];
    enterArray_1(a, n);
    enterArray_1(b, m);
    sumArray(n, a, b, c, m + n);
    delete[]a;
    delete[]b;
    return 0;
}

