#include "CutCommand.h"
#include "Receiver.h"

void CutCommand::Execute()
{
	_receiver->Cut();
}

void CutCommand::Undo()
{
	// Basically we clear the recent copied entry from clipboard. And make anything that was cut get back to its place.
	_receiver->Undo("CUT");
}

void CutCommand::Redo()
{
	// Can redo cut!!!
	_receiver->Redo("CUT");
}