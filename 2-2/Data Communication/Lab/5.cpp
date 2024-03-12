#include<bits/stdc++.h>
using namespace std;
int p = 0;
vector<char> generate_hamming(string message)
{
int n = message.size(), hammingLength, k = 0;
int currentPower = 1;
string str = message;
while (currentPower < p + n + 1) {
p++;
currentPower *= 2;
}
hammingLength = n + p;
reverse(str.begin(), str.end());
vector<char> ans(hammingLength + 1, '0');
for (int i = 1; i <= hammingLength; i++) {
if (i & (i - 1)) { //check if 'i' is a power of 2 or not, if 0 then power of 2 else not
ans[i] = str[k];
k++;
}
}
for (int i = 0; i <= p - 1; i++) {
int XOR = 0, flag = 1, skipBit = (1 << i);
for (int j = skipBit; j <= hammingLength; j += skipBit) {
if (!flag) {
flag ^= 1;
continue;
}
flag ^= 1;
int l = j, limit = skipBit;
while (limit > 0 && l <= hammingLength) { //check limit and skipBit limit
XOR ^= (ans[l] - '0');
l++, limit--;
}
}
if (XOR) ans[(1 << i)] = '1';
else ans[(1 << i)] = '0';
}
return ans;
}
bool check_error(vector<char> v)
{
int hammingLength = v.size() - 1;
for (int i = 0; i <= p - 1; i++) {
int XOR = 0, skipBit = (1 << i);
for (int j = (1 << i); j <= hammingLength; j += skipBit)
 {
int l = j, limit = skipBit;
while (limit > 0 && l <= hammingLength) { //check limit and skipBit limit
XOR ^= (v[l] - '0');
l++, limit--;
}
}
if (XOR == 1) return true;
}
return false;
}
int main()
{
string message;
bool error = 0;
vector<char> hammingCode;
cout << "Enter dataword: ";
cin >> message;
hammingCode = generate_hamming(message);
error = check_error(hammingCode);
if (error) cout << "Error found.\n";
else cout << "No error found.\n";
cout << "Generated hamming code: ";
for (int i = hammingCode.size() - 1; i >= 1; i--)
cout << hammingCode[i];
cout << "\n";
}