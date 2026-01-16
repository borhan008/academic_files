#include<bits/stdc++.h>
using namespace std;

int main() {
   
    string cipher;
    getline(cin, cipher);

    string ciphermap;
    cin >> ciphermap;

    string ciphermapNew=ciphermap;
    cout << ciphermapNew << "\n";
    char ch = 'A';
    for(auto l:ciphermap){
        ciphermapNew[l-'A'] = ch++;
    }
    // PQRSTUVWXABCDEFGHIJKLMNOYZ
    // ASDFGHJKLQWERTYUIOPZXCVBNM
    if(ciphermap.length() != 26) {
        cout << "Cipher Map error." << endl;
        return 1;
    }

    string plaintext = "";
    for(char c : cipher) {
     plaintext += ciphermapNew[(c-'A')];
    }
    cout << plaintext << endl;
    return 0;
}