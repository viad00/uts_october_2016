#include <iostream>

using namespace std;

int fact(int n) {
    int fact = 1;
    for(int i = n; i > 0; i--) {
        fact = i * fact;
    }
    return fact;
}

int first(int n, int p) {

}

int main() {
    int n = 0, p = 0;
    cout << "n:\n>";
    cin >> n;
    cout << "num:\n>";
    cin >> p;
    cout << fact(n);
}

