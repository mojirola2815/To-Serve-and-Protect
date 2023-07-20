#include <iostream> 
#include <string> 
#include <cstdlib>
using namespace std; 

// Function to display a welcome message 
void greet() 
{ 
	cout << "Welcome to the 'To Serve and Protect' program!" << endl; 
} 

// Function to check if the user is qualified to be in the program 
bool isQualified(int age, bool isCitizen) 
{ 
	// Check if the user is 18 or older and a citizen
	if (age >= 18 && isCitizen == true) 
		return true; 

	// User is not qualified
	return false; 
} 

// Function that takes a character as an input and returns the corresponding 
// output string depending on the user's input 
string evaluateCharacterInput(char character) 
{ 
	// Switch statement to evaluate user's choice 
	switch (character) 
	{ 
	case 'A': 
		return "Courageous"; 
		break; 
	case 'B': 
		return "Loyal"; 
		break; 
	case 'C': 
		return "Honest"; 
		break; 
	case 'D': 
		return "Responsible"; 
		break; 
	case 'E': 
		return "Diligent"; 
		break; 
	case 'F': 
		return "Patient"; 
		break; 
	case 'G': 
		return "Accountable"; 
		break; 
	case 'H': 
		return "Selfless"; 
		break; 
	case 'I': 
		return "Respectful"; 
		break; 
	default: 
		return "Invalid"; 
		break; 
	} 
} 

// Function to display the program requirements to the user
void programRequirements(int age, bool isCitizen) 
{ 
	// Check if the user is qualified for the program
	if (isQualified(age, isCitizen)) 
	{ 
		cout << "You meet the qualifications! Please answer the following "
				"questions to continue: " 
			 << endl; 
		cout << "What are the core values of the program?  Enter one letter"
				" at a time followed by enter: " 
			 << endl; 
		cout << "A. Courageous\nB. Loyal\nC. Honest\nD. Responsible\nE. Diligent"
				"\nF. Patient\nG. Accountable\nH. Selfless\nI. Respectful"
			 << endl; 
	} 
	else 
	{ 
		cout << "You do not meet the qualifications for the program. Please"
				" contact the office for more information." 
			 << endl; 
		exit(0); 
	} 
} 

// Main function 
int main() 
{ 
	// Variables to store user input 
	int age = 0; 
	bool isCitizen = false; 
	string answer; 

	// Greet the user 
	greet(); 

	// Get the user's age 
	cout << "What is your age? "; 
	cin >> age; 

	// Get the user's citizenship status 
	cout << "Are you a US citizen? (y/n) "; 
	cin >> answer; 

	// Set the corresponding boolean value 
	if (answer == "y" || answer == "Y") 
		isCitizen = true; 

	// Display the program requirements 
	programRequirements(age, isCitizen); 

	// Variable to store user input 
	char character; 

	// Get user input 
	cin >> character; 

	// Display the output 
	cout << evaluateCharacterInput(character) << endl; 

	return 0; 
}