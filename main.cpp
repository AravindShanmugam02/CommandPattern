#include <iostream>
#include "CopyCommand.h"
#include "CutCommand.h"
#include "PasteCommand.h"
#include "CommandInvoker.h"
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
	CommandInvoker* cI = new CommandInvoker();

	std::cout << "Let's Begin" << std::endl;
	std::cout << "Enter a command to perform:" << "\n 1. Copy" << "\n 2. Cut" << "\n 3. Paste" << "\n 4. Undo" << "\n 5. Redo" << "\n 6. List of commands stored" << "\n 0. Exit" << std::endl;
	int choice = 0;

	do
	{
		if (choice == 1)
		{
			CommandBase* copyCommandGiven = new CopyCommand(r); //Note: You cannot create an object of an abstract class like CommandBase copyCommandGiven, but you can create a pointer to an abstract class like CommandBase* copyCommandGiven;
			cI->AddCommandToQueue(*copyCommandGiven);
		}
		else if (choice == 2)
		{
			CommandBase* cutCommandGiven = new CutCommand(r);
			cI->AddCommandToQueue(*cutCommandGiven);
		}
		else if (choice == 3)
		{
			CommandBase* pasteCommandGiven = new PasteCommand(r);
			cI->AddCommandToQueue(*pasteCommandGiven);
		}
		else if (choice == 4)
		{
			cI->UndoCommand();
		}
		else if (choice == 5)
		{
			cI->RedoCommand();
		}
		else if (choice == 6)
		{
			cI->ListCommands();
		}

		std::cin >> choice;
	} while (choice != 0);
}