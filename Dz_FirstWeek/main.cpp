#include <iostream>
#include <cmath>

using namespace std;

void numbers() {
    int n;
    int f = 0;
    int s = 0;
    cout << "Enter n : ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        f = f + s;
    }
    cout << f << endl;
}

void dec() {
    double a, b, c, x1, x2 ;
    cin >> a >> b >> c;
    double dec1 ;
    dec1 = b * b - 4 * a * c;
    if (dec1 == 0) {
        x1 = (-b + 0) / (2 * a);
        cout << "Root : " << x1 <<endl;
    }
    if (dec1 < 0) {
        cout << "The are no roots"<<endl;
    }
    if (dec1 > 0) {
        x1 = ((-b + sqrt(dec1)) / (2 * a));
        x2 = ((-b - sqrt(dec1)) / (2 * a));
        cout << "Root #1 : " << x1 << " Root #2 : " << x2 <<endl;
    }
}

void log() {
    int p = 0;
    double x;
    int f = 1;
    cin >> x;
    while (f < x) {
        f = f * 2;
        p = p + 1;
    }
    p = p-1;
    cout << p << endl;
}

int power (int x, unsigned p){
    int f = x;
    for (int i = 1; i < p; ++i) {
        f = f * x ;
    }
    return f;
}

int main() {
    int x = 0;
    unsigned  p = 0;
    numbers();
    dec();
    log();
    cin >> x >> p;
    cout << power(x , p) << endl;

    return 0;
}