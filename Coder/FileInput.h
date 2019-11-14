#pragma once

#include <InputInterferance.h>
#include <fstream>

class FileInput : public InputInterferance
{
	public:
	FileInput() = default;
	virtual ~FileInput() = default;
	virtual bool isInputGood();
	virtual void setText(const std::string text);
	virtual std::string getText();
private:
	void readTextFromFileStream();
	std::fstream fileStream;
	bool hasOpenedSth = false;
	std::string sum; 
};
