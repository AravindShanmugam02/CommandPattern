#include "Receiver.h"

void Receiver::Copy()
{
	// Complex logic ;)
	std::cout << "COPY" << std::endl;
}

void Receiver::Cut()
{
	// Complex logic ;)
	std::cout << "CUT" << std::endl;
}

void Receiver::Paste()
{
	// Complex logic ;)
	std::cout << "PASTE" << std::endl;
}

void Receiver::Undo(std::string command)
{
	// More complex logic!!!
	std::cout << "Undoing...  " << command << std::endl;
}

void Receiver::Redo(std::string command)
{
	// More complex logic!!!
	std::cout << "Redoing...  " << command << std::endl;
}