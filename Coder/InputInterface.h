#pragma once

#include <string>

class InputInterface
{
	public:
	InputInterface() = default;
	virtual ~InputInterface() = default;
	virtual bool isInputGood() = 0;
	virtual void setText(const std::string text) = 0;
	virtual std::string getText() = 0;
};