#pragma once
#include <iostream>
#include "CommandBase.h"

class Receiver;
class CutCommand : public CommandBase
{
public:
	CutCommand(Receiver& receiver) { _receiver = &receiver; }

	void Execute() override;
	void Undo() override;
	void Redo() override;

private:
	Receiver* _receiver;
};