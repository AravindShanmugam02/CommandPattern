#include "CommandInvoker.h"

void CommandInvoker::InvokeCommand()
{
	_onCommand->Execute();
}

void CommandInvoker::AddCommandToQueue(CommandBase& newCommand)
{
	if (undone)
	{
		redone = false;
		undone = false;

		// Clear the remaining commands that are present after the undoCounter position from the deque. The resize command takes in a value representing the number of elements to be left from the start.
		commandDeque.resize(undoCounter);
		commandDeque.shrink_to_fit(); // This function requests that the memory usage is adapted to the current size of the container, but the request is non-binding, and the container implementation is free to optimize its memory usage otherwise.
		
		undoCounter = -1; // Reset undoCounter.
		redoCounter = -1; // Reset redoCounter.
	}
	else if (redone)
	{
		redone = false;
		undone = false;
		
		// Clear the remaining commands that are present after the redoCounter position from the deque. The resize command takes in a value representing the number of elements to be left from the start.
		commandDeque.resize(redoCounter + 1);
		commandDeque.shrink_to_fit(); // This function requests that the memory usage is adapted to the current size of the container, but the request is non-binding, and the container implementation is free to optimize its memory usage otherwise.
		
		undoCounter = -1; // Reset undoCounter.
		redoCounter = -1; // Reset redoCounter.
	}

	// Add this new command.
	commandDeque.push_back(&newCommand);
	_onCommand = &newCommand;
	InvokeCommand();
}

void CommandInvoker::UndoCommand()
{
	// Iterate through the Deque in reverse order.

	if (commandDeque.empty())
	{
		std::cout << "Cannot Undo. No Actions Done Yet." << std::endl;
	}
	else
	{
		if (redone)
		{
			// Something is redone
			undoCounter = redoCounter;
			redone = false;
		}

		if (undoCounter == -1)
		{
			// Nothing undone and nothing redone, so undo last recent command.
			commandDeque[commandDeque.size() - 1]->Undo();
			undoCounter = commandDeque.size() - 1;
		}
		else if(undoCounter != 0)
		{
			commandDeque[undoCounter - 1]->Undo();
			undoCounter -= 1;
		}
		else
		{
			std::cout << "Cannot Undo. No More Actions Left." << std::endl;
		}
		undone = true;
	}
}

void CommandInvoker::RedoCommand()
{
	if (commandDeque.empty())
	{
		std::cout << "Cannot Redo. No Actions Done Yet." << std::endl;
	}
	else
	{
		if (!redone)
		{
			// Something is undone
			redoCounter = undoCounter;
		}

		// Redo can only be done when something is Undone.
		if (undone)
		{
			if (redoCounter >= commandDeque.size())
			{
				undone = false; // Setting this to false only when all the undone has been redone.
				std::cout << "Cannot Redo. No More Actions Left To Redo." << std::endl;
			}
			else if (redoCounter != -1)
			{
				commandDeque[redoCounter]->Redo();
				redoCounter += 1; // The redo logic alone increases the redoCounter after performing a redo for the next iteration and also for passing the count to undo when required.
			}

			redone = true;
		}
		else
		{
			std::cout << "Cannot Redo. No Actions Undone Yet." << std::endl;
		}
	}
}