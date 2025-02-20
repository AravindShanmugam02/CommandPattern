#include "PasteCommand.h"
#include "Receiver.h"

void PasteCommand::Execute()
{
	_receiver->Paste();
}

void PasteCommand::Undo()
{

}

void PasteCommand::Redo()
{

}