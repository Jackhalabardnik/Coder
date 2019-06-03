#include <FileInput.h>

bool FileInput::isInputGood()
{
	return sum.size()>2;
}

void FileInput::setText(const std::string text)
{
	if(hasOpenedSth)
	{
		fileStream.close();
	}
	fileStream.open(text);
	readTextFromFileStream();
	hasOpenedSth = true;
}

std::string FileInput::getText()
{
	if(isInputGood())
	{
		return sum;
	}
	return std::string();
}

void FileInput::readTextFromFileStream()
{
	sum.erase(sum.begin(),sum.end());
	std::string temp;
	while(fileStream.good()) 
	{
		std::getline(fileStream,temp);
		sum += temp + "\n";
	}
	if(sum.size()>2)
	{
		sum.erase(sum.end()-2,sum.end());
	}
}