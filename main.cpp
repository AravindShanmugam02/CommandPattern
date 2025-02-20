#include <iostream>
#include "CopyCommand.h"
#include "CutCommand.h"
#include "PasteCommand.h"
#include "Receiver.h"

// CLIENT

int main()
{
	// To create a command pattern, we need 5 components
	//		- Abstract Command
	//		- Concrete Command
	//		- Invoker
	//		- Receiver
	//		- Client

	Receiver r;

	std::cout << "Let's Begin" << std::endl;
	std::cout << "Enter a command to perform:" << "\n 1. Copy" << "\n 2. Cut" << "\n 3. Paste" << std::endl;
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		CommandBase* copyCommandGiven = new CopyCommand(r); //Note: You cannot create an object of an abstract class like CommandBase copyCommandGiven, but you can create a pointer to an abstract class like CommandBase* copyCommandGiven;
		copyCommandGiven->Execute();
	}
	else if (choice == 2)
	{
		CommandBase* cutCommandGiven = new CutCommand(r);
		cutCommandGiven->Execute();
	}
	else if (choice == 3)
	{
		CommandBase* pasteCommandGiven = new PasteCommand(r);
		pasteCommandGiven->Execute();
	}
}