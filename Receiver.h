// RECEIVER

/*
* Receiver is the object that is going to do something with the commands it receives from the invoker.
* Example: If the invoker sends a dance command, the receiver on receiving the dance command will dance.
*/

#pragma once
#include <iostream>

class Receiver
{
public:

	void Copy();
	void Cut();
	void Paste();
};