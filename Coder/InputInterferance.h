#ifndef INPUT_INTERFERANCE_H
#define INPUT_INTERFERANCE_H

#include <string>

class InputInterferance
{
	public:
	InputInterferance() = default;
	virtual ~InputInterferance() = default;
	virtual bool isInputGood() = 0;
	virtual void setText(const std::string text) = 0;
	virtual std::string getText() = 0;
};

#endif