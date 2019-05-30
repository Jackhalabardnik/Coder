#include <EntryInput.h>

bool EntryInput::isInputGood()
{
	return enteredText.size()>0;
}

void EntryInput::setText(const std::string text)
{
	enteredText = text;
}

std::string EntryInput::getText()
{
	return enteredText;
}