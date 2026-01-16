#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cout << "Input two integers: ";
    int a, b; cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}