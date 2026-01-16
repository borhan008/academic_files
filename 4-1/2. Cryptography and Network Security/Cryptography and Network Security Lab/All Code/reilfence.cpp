#include<bits/stdc++.h>
using namespace std;

vector<int> permutation;

string reilFenceEncryption(string &plaintext, int &depth){
    vector<vector<char>> rails(depth, vector<char>(plaintext.length(), '.'));
    string ciphertext = "";

    int row=depth-1, col=0, n=0, dir = 1;
    while(n < plaintext.length()) {
       rails[row][col] = plaintext[n];
        if(row == 0) dir = 1;
        else if(row == depth-1) dir = -1;
        row += dir;
        col++;
        n++;
    }

    for(int l=0; l<depth; l++) {
        for(int j=0; j<plaintext.length(); j++) {
            cout << rails[l][j] << " ";
        }
        cout << "\n";
    }

    for(int i=0; i<depth; i++) {
        int x; cin >> x;
        permutation.push_back(x-1);
    }

    for(auto l:permutation) {
        for(int j=0; j<plaintext.length(); j++) {
            cout << rails[l][j] << " ";
            if(rails[l][j] != '.') ciphertext += rails[l][j];
        }
        cout << "\n";
    }


    return ciphertext;
}

string reilFenceDecryption(string &ciphertext, int &depth){
    vector<vector<char>> rails(depth, vector<char>(ciphertext.length(), '.'));
    string plaintext = "";


    int row=depth-1, col=0, n=0, dir = 1;
    while(n < ciphertext.length()) {
         rails[row][col] = '*';
            if(row == 0) dir = 1;
            else if(row == depth-1) dir = -1;
          row += dir;
          col++;
          n++;
     }
    int index = 0;
    for(auto i:permutation) {
        for(int j=0; j<ciphertext.length(); j++) {
            if(rails[i][j] == '*' && index < ciphertext.length()) {
                rails[i][j] = ciphertext[index++];
            }
        }
    }



  

    row=depth-1, col=0, n=0, dir = 1;
    while(n < ciphertext.length()) {
       plaintext += rails[row][col];
         if(row == 0) dir = 1;
         else if(row == depth-1) dir = -1;
        row += dir;
        col++;
        n++;
    }

    return plaintext;
}

int main() {
    cout << "Input string: ";
    string plaintext; getline(cin, plaintext);

    cout << "Input depth: ";
    int depth; cin >> depth;


    string ciphertext = reilFenceEncryption(plaintext, depth);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedtext = reilFenceDecryption(ciphertext, depth);
    cout << "Decrypted text: " << decryptedtext << endl;
    return 0;

}