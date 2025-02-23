#pragma once
#include "CommandBase.h"
#include <iostream>
#include <queue>
#include <deque>

class CommandInvoker
{
public:
	CommandInvoker() {
		_onCommand = nullptr;
	};
	~CommandInvoker() {};
	
	void AddCommandToQueue(CommandBase& newCommand);
	void UndoCommand();
	void RedoCommand();
	void ListCommands();
private:
	void InvokeCommand();

	CommandBase* _onCommand;

	// std::queue<CommandBase*> commandQueue; //Todo:: had an error stating pointer to reference is not allowed, when I did std::queue<CommandBase&> commandQueue. Should dig more about this.

	//Switched from Queue to Deque because queue is FIFO.
	std::deque<CommandBase*> commandDeque;

	// undoCounter contains the index of element which was last accessed to perform undo action. Resets to -1, if nothing applicable.
	int undoCounter = -1;
	// redoCounter contains the index of element which was last accessed to perform redo action. Resets to -1, if nothing applicable.
	int redoCounter = -1;

	bool undone = false;
	bool redone = false;
	
	// just for debugging purpose to bring this to screen.
	const std::string commandIdentifier[3] = { "COPY", "CUT", "PASTE" };
};