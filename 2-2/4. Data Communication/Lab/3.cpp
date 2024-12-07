// Version : 01
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int i, j, divlen, msglen;
 char input[100], div[100], temp[100];
 char quot[100], rem[100], div1[100];
 printf("Enter Data: ");
 gets(input);
 printf("Enter divisor: ");
 gets(div);
 divlen = strlen(div);
 msglen = strlen(input);
 strcpy(div1, div);
 for (i = 0; i < divlen - 1; i++)
 input[msglen + i] = '0';
 for (i = 0; i < divlen; i++)
 temp[i] = input[i];
 for (i = 0; i < msglen; i++)
 {
 quot[i] = temp[0];
 if (quot[i] == '0')
 {
 for (j = 0; j < divlen; j++)
 div[j] = '0';
 }
 else
 {
 for (j = 0; j < divlen; j++)
 div[j] = div1[j];
 }
 for (j = divlen - 1; j > 0; j--)
 {
 if (temp[j] == div[j])
 rem[j - 1] = '0';
 else
 rem[j - 1] = '1';
 }
 rem[divlen - 1] = input[i + divlen];
 strcpy(temp, rem);
 }
 strcpy(rem, temp);
 printf("\nQuotient is ");
 for (i = 0; i < msglen; i++)
 printf("%c", quot[i]);
 printf("\nRemainder is ");
 for (i = 0; i < divlen - 1; i++)
 printf("%c", rem[i]);
 printf("\nCodeword: ");
 for (i = 0; i < msglen; i++)
 printf("%c", input[i]);
 for (i = 0; i < divlen - 1; i++)
 printf("%c", rem[i]);
 printf("\n");
}

// Version : 02
#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
    string msg,crc,encoded=""; 
    cout<<"enter your message : \n"; 
    getline(cin,msg); 
    cout<<"enter your crc generator : \n"; 
    getline(cin,crc); 
    int m=msg.length(),n=crc.length(); 
    encoded+=msg; 
    for(int i=1;i<=n-1;i++) 
    { 
        encoded+='0'; 
    } 
 
    for(int i=0;i<=encoded.length()-n; ) 
    { 
        for(int j=0;j<n;j++) 
        encoded[i+j]=(encoded[i+j]==crc[j])? '0' : '1'; 
        for( ;i<encoded.length()&&encoded[i]!='1';i++); 
    } 
    cout<< "Codeward : " <<  msg+encoded.substr(m) << "\n"; 
}

// Version : 03 
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    string data;
    string divisor;
    cout << "Enter Data : ";
    cin >> data;
    cout << "Enter Divisor : ";
    cin >> divisor;

    string temp_data = data;

    temp_data.append(divisor.length() - 1, '0');
    for (int i = 0; i < temp_data.length();)
    {
        bool flag = false;
        int temp;
        for (int j = 0; j < divisor.length(); j++)
        {
            if (temp_data[i] == divisor[j])
            {
                temp_data[i] = '0';
            }
            else
            {
                temp_data[i] = '1';
                if (!flag)
                {
                    temp = i;
                    flag = true;
                }
            }
            i++;
        }
        if (flag)
            i = temp;
        if (temp_data.length() - i < divisor.length())
            break;
    }
    string remainde;
    remainde.append(temp_data, data.length(), divisor.length() - 1);
    data.append(temp_data, data.length(), divisor.length() - 1);
    cout << "Remainder : " << remainde << endl;
    cout << "Code Word : " << data << endl;
}