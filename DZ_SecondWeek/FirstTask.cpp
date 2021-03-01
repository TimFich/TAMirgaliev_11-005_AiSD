#include <iostream>
using namespace std;
int sum(int *a, int size) {
    int sum = 0;
    for (int *p = a; p < a + size; ++p) {
        sum = sum + *p;
    }
    return sum;
}
void enterArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
}
int main() {
    int size;
    cin >> size;
    int array[size];
    enterArray(array, size);
    int *a = &array[0];
    cout << sum(a, size);
}