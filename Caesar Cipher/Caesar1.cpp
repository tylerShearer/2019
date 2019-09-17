//# Written by Tyler Shearer 9/17/19 #
//####################################
#include "Caesar.h"	
using namespace std;

Caesar::Caesar(int shift)
{
	if (shift < 0)//this wraps shift's index if a negative number is given
	{
		shift = (shift + 26);
	}

	std_alphabet = new char[26];
	c_alphabet = new char[26];
	for (int i = 0; i < 26; i++)
	{
		std_alphabet[i] = 'a' + i;//creates lowercase alphabet a-z
	}
	for (int k = 0; k < 26; k++)
	{
		c_alphabet[k] = std_alphabet[(k + shift) % 26];	//populate c_alphabet with std_alphabet moved by "shift" amount
	}
		
}	
	
int Caesar::encrypt(const std::string& message, std::string& emessage)
{
	int encCount = 0;//tracks number of encrypted letters
	emessage = message;

	for (int i = 0; i < message.length(); i++)//for the length of the message
	{
		if (!isalpha(message[i]))//if the character at [i] is not a letter
		{
			emessage[i]= message[i];//put it into emessage, unchanged
		}
		else
		{
			++encCount;//we are going to encrypt so add to encCount		
			char lower = tolower(message[i]);//lower the character's case at [i] and assign it to lower, compare lower to std_alphabet
			int j = 0;
			while (lower != std_alphabet[j])//loop to find std_aphabet index where lower is found	
			{
				++j;
			}
			emessage[i] = c_alphabet[j];//once you find the character's index in std_alphabet[j], use c_alphabet[j] to assign emessage the caesar shifted letter
		}

	}
	return encCount;//after the loop ends return the number of encrypted letters
}

int Caesar::decrypt(const std::string& message, std::string& dmessage)
{
	int decCount = 0;//tracks number of decrypted letters
	dmessage = message;

	for (int i = 0; i < message.length(); i++)//for the length of the message
	{
		if (!isalpha(message[i]))//if the character at [i] is not a letter
		{
			dmessage[i] = message[i];//put it into dmessage unchanged
		}
		else
		{
			++decCount;//add to the count of characters decrypted			
			char lower = tolower(message[i]);
			int j = 0;
			while (lower != c_alphabet[j])//loop to find the character in c_aphabet array
			{
				++j;
			}
			dmessage[i] = std_alphabet[j];//once you find the character's index in c_alphabet[j], use std_alphabet[j] to assign dmessage the caesar shifted character
		}
	}
	return decCount;//number of letters decrypted
}

Caesar::~Caesar()
{
	delete[] std_alphabet;
	delete[] c_alphabet;
}