#include<bits/stdc++.h>
using namespace std;

// all letters, special characters, numbers and spaces as ASCII values from 0 to 255
char caesar_cipher(char c, int shift) {
    if(c==' ') return ' ';
    return (c+256+shift)%256;
}


int main() {
    cout << "Plaintext: ";
    string x; getline(cin, x);

    cout << "Shift: ";
    int shift; cin >> shift;
    string ciphertext = "";

    for(char c : x) ciphertext += caesar_cipher(c, shift);
    cout << "Ciphertext: " << ciphertext << endl;


    cout << "Decrypted Text: ";
    for(char c : ciphertext) cout << caesar_cipher(c, -shift);
    cout << endl;

    return 0;
}