#pragma once

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
