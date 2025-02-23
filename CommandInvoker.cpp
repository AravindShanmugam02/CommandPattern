#include "CommandInvoker.h"

void CommandInvoker::AddCommandToQueue(CommandBase& newCommand)
{
	if (undone)
	{
		undone = false;
		// Clear the remaining commands that are present after the iteratorCounter position from the deque.
		commandDeque.resize(iteratorCounter);
		commandDeque.shrink_to_fit(); // This function requests that the memory usage is adapted to the current size of the container, but the request is non-binding, and the container implementation is free to optimize its memory usage otherwise.
		iteratorCounter = -1; // reset iteratorCounter.
	}
	else if (redone)
	{

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
		if (iteratorCounter == -1)
		{
			// Nothing undone and nothing redone, so undo last recent command.
			commandDeque[commandDeque.size() - 1]->Undo();
			iteratorCounter = commandDeque.size() - 1;
		}
		else if(iteratorCounter != 0)
		{
			commandDeque[iteratorCounter - 1]->Undo();
			iteratorCounter = iteratorCounter - 1;
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
	if (undone)
	{

	}
}

void CommandInvoker::InvokeCommand()
{
	_onCommand->Execute();
}