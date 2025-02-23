#include "CommandInvoker.h"

void CommandInvoker::AddCommandToQueue(CommandBase& newCommand)
{
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
			// nothing undone and nothing redone, so undo last recent command.
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