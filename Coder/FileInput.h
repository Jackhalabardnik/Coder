#ifndef FILE_INPUT_H
#define FILE_INPUT_H

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
	std::fstream fileStream;
	bool hasOpenedSth = false, hasSum = false;
	std::string sum; 
};

#endif