#include "CopyCommand.h"
#include "Receiver.h"

void CopyCommand::Execute()
{
	_receiver->Copy();
}

void CopyCommand::Undo()
{

}

void CopyCommand::Redo()
{

}