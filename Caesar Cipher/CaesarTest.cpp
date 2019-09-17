#include <iostream>
#include "Caesar.h"
using namespace std;
int main()
{
	string str1, str2, str3, str4;
	cout << "Enter your cipher shift number\n";
	int x = 0;
	cin >> x;
	Caesar c(x);
	cin.ignore(1, '\n');
	cout << "Enter the message you wish to encrypt.\n";
	getline(cin, str1);

	cout << "\n" << "Number of letters encrypted: " << c.encrypt(str1, str2)<<"\n";
	cout<< "Encryted message: "<< (str2)<<"\n"; 

	cout << "\nNow you can try decrypting a message.\nFirst, you need to enter the cipher shift number corresponding to your encryted message\n";
	int y = 0;
	cin >> y;
	Caesar d(y);
	cout << "Now enter the encrypted message you wish to decrypt.\n";
	cin.ignore(1, '\n');
	getline(cin, str3);

	cout << "\n" << "Number letters decrypted: " << d.decrypt(str3, str4) << "\n";
	cout << "Decryped message: " << (str4) << "\n";
	return(0);
};