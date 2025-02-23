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
private:
	void InvokeCommand();

	CommandBase* _onCommand;

	// std::queue<CommandBase*> commandQueue; //Todo:: had an error stating pointer to reference is not allowed, when I did std::queue<CommandBase&> commandQueue. Should dig more about this.

	//Switched from Queue to Deque because queue is FIFO.
	std::deque<CommandBase*> commandDeque;

	// iteratorCounter contains the index of element which was last accessed to perform either undo or redo action. Resets to -1, if nothing applicable.
	int iteratorCounter = -1;

	bool undone = false;
	bool reDid = false;
};