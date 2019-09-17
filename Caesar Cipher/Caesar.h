// include file for Caesar cipher code
//

#ifndef CAESAR_H
#define CAESAR_H

#include <string>

class Caesar {

private:
	//pointers used to refer to the standard alphabet array and the Caesar shift array
	char* std_alphabet;
	char* c_alphabet;

public:
	// The constructor . . . 
	// create the two arrays with the c_alphabet array contents representing the std_alphabet 
	// characters shifted by a value of the shift parameter
	Caesar(int shift = 0);

	// encrypt a message. Returns count of characters processed
	// first string is message, second is encrypted string
	int encrypt(const std::string& message, std::string& emessage);

	// decrypt a message. Returns count of characters processed
	// first string is encrypted string, second is decrypted string
	int decrypt(const std::string& message, std::string& dmessage);

	//delete any memory resources used by the class
	~Caesar();

}; // end of class . . .
#endif