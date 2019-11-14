#pragma once

#include <InputInterferance.h>

class EntryInput : public InputInterferance
{
public:
	EntryInput() = default;
	virtual ~EntryInput() = default;
	virtual bool isInputGood() override;
	virtual void setText(const std::string text) override;
	virtual std::string getText() override;
private:
	std::string enteredText;
};
