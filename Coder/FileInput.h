#pragma once

#include <InputInterface.h>
#include <fstream>

class FileInput : public InputInterface
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
