#pragma once
#include <iostream>
#include "CommandBase.h"

class Receiver;
class PasteCommand : public CommandBase
{
public:
	PasteCommand(Receiver& receiver) { _receiver = &receiver; }

	void Execute() override;
	void Undo() override;
	void Redo() override;

private:
	Receiver* _receiver;
};