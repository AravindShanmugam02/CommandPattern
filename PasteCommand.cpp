#include "PasteCommand.h"
#include "Receiver.h"

void PasteCommand::Execute()
{
	_receiver->Paste();
}

void PasteCommand::Undo()
{
	// Basically we clear the recent pasted entry from the screen.
	_receiver->Undo("PASTE");
}

void PasteCommand::Redo()
{
	_receiver->Redo("PASTE");
}