// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[21]; //Modified char array to 21 to take into account null character

  std::cout << "Enter a value: ";
  std::cin.get(user_input, 21); // Places the first 21 characters of the stream into the char array.  Last char is null character.

  if (std::cin.rdbuf()->in_avail() > 1) { //Checks input buffer to see if there are remaining characters
	  std::cout << "Buffer overflow has been detected" << std::endl; // Prints statement that an overflow would have occurred if all chars were read.
  }
  
  std::cout << "You entered: " << user_input << std::endl;

  std::cout << "Account Number = " << account_number << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
