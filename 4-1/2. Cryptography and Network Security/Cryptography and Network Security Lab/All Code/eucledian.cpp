#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "Input multiplier, a : ";
    int a; cin >> a;
    cout << "Inpur increment, b : ";
    int b; cin >> b;

    cout << "Input initial value or seed, X0 : ";
    int X0; cin >> X0;

    cout << "Input modulus, m : ";
    int m; cin >> m;

    cout << "Input number of random values to generate, n: ";
    int n; cin >> n;

    vector<int> random_values;  
    random_values.push_back(X0);

    for(int i=1; i<n; i++){
        int Xi = (a * random_values[i-1] + b) % m;
        random_values.push_back(Xi);
    }

    for(int val : random_values){
        cout << val << " ";
    }
    cout << endl;
}