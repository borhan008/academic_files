// Version : 01
#include<bits/stdc++.h>
using namespace std;
uint16_t Fletcher_16(string data, int n)
{
 uint16_t R = 0, L = 0, check_sum = 0;
 for (int i = 0; i < n; i++)
 {
 R = (R + data[i]) % 256;
 L = (L + R) % 256;
 }
 check_sum = L * 256 + R;
 return check_sum;
}
int main()
{
 string input = "BFH2001048F";
 cout << "Fletcher's checksum code for the input in hexadecimal is: ";
 printf("%X\n", Fletcher_16(input, input.size()));
}

// Version : 02
#include<bits/stdc++.h>
using namespace std;

#define uint uint16_t

uint Fletcher(string str){
	uint sum1=0, sum2=0;
	for(int i=0; i<(int)str.size(); i++)		{
		sum1 += (str[i]); sum1 %= 255;
		sum2 += sum1; sum2 %= 255;
	}
	
	return (sum2 << 8) | sum1;
}

int main()
{
		cout << "Write the roll : \n";
		string str;  getline(cin, str);
		printf("%x", Fletcher(str));
    return 0;
}