#pragma once

#include <InputInterface.h>

class EntryInput : public InputInterface
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
