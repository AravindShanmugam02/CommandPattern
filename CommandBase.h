// Abstract class
#pragma once

class CommandBase
{
public:
	// Abstract methods to make this class abstract
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};