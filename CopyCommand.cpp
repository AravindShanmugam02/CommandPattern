#include "CopyCommand.h"
#include "Receiver.h"

void CopyCommand::Execute()
{
	_receiver->Copy();
}

void CopyCommand::Undo()
{
	// Basically we clear the recent copied entry from clipboard
	_receiver->Undo("COPY");
}

void CopyCommand::Redo()
{
	// Can't redo copy... or can we? But we will do here!!!
	_receiver->Redo("COPY");
}