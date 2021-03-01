#include  <iostream>

using namespace std;

void sumArray(int n, int *p1, int *p2, int *p3, int m) {
    for (int i = 0; i < n; i++) {
        *(p3 + i) = *(p1 + i);
    }
    for (int i = 0; i < m; i++) {
        *(p3 + i + n) = *(p2 + i);
    }
}

void enterArray_1(int *a, int size) {

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
    int m;
    cout << "Enter a length of arrays a and b : " << endl;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    int *c = new int[m + n];
    enterArray_1(a, n);
    enterArray_1(b, m);
    sumArray(n, a, b, c, m);
    outPut(c, n + m);
    delete[]a;
    delete[]b;
    return 0;
}