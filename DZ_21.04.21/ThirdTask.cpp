#include <iostream>

using namespace std;

int BinarySearch(int x, int right, int left) {
    int buf = right - left;
    int mid = left + (right - left) / 2;
    if (mid * mid == x)
        return mid;
    if (buf == 1 || buf == 0) {
        if (x - (left - 1) * (left - 1) < mid)
            return left - 1;
        if (x - left * left < right)
            return left;

        return left + 1;

    }

    if (mid * mid > x)
        return BinarySearch(x, mid, left);

    if (mid * mid < x)
        return BinarySearch(x, right, mid + 1);


}

int main() {
    int x;
    cin >> x;
    int value = BinarySearch(x, x, 0);
    cout << value;
    return 0;
}