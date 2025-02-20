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
		CopyCommand copyCommandGiven = CopyCommand(r);
		copyCommandGiven.Execute();
	}
	else if (choice == 2)
	{
		CutCommand cutCommandGiven = CutCommand(r);
		cutCommandGiven.Execute();
	}
	else if (choice == 3)
	{
		PasteCommand pasteCommandGiven = PasteCommand(r);
		pasteCommandGiven.Execute();
	}
}