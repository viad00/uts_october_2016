#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
    int a = 0, n = 0;
    cout << "a:\n>";
    cin >> a;
    cout << "n:\n>";
    cin >> n;
-   if (n % 2 == 0) {
-        cout << pow(pow(a,n/2),2)<< endl;
-   } else {
-        cout << pow(pow(a,n/2),2)*a << endl;
-   }
    return 0;
}
