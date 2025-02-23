#pragma once
#include <iostream>
#include "CommandBase.h"

class Receiver;
// When forward declaring, we can only do certain things like:
// Declare variables (or members) of type "pointer to A" and "reference to A"
// Declare functions which take arguments of type A or return type A
// You can't:
// Declare variables(nor members) of type A
// Dereference pointers to A or access any members of references to A
// Define subclasses of A.

class CopyCommand : public CommandBase
{
public:
	CopyCommand(Receiver& receiver) { _receiver = &receiver; }
	//~CopyCommand(){}
	// Even if we didn't give one destructor, the compiler will create one by default.

	Commands GetCommand() override { return command; }

	void Execute() override;
	void Undo() override;
	void Redo() override;

private:
	Receiver* _receiver;
	Commands command = Commands::COPY;
};