// Abstract class
#pragma once

enum class Commands
{
	COPY,
	CUT,
	PASTE
};

class CommandBase
{
public:
	//CommandBase(){};
	//~CommandBase(){};
	// Even if we don't add explicit constructor and destructor, they will be added by default by the compiler.

	// Pure Virtual methods to make this class abstract
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
	virtual Commands GetCommand() = 0;
};