#include "CutCommand.h"
#include "Receiver.h"

void CutCommand::Execute()
{
	_receiver->Cut();
}

void CutCommand::Undo()
{

}

void CutCommand::Redo()
{

}