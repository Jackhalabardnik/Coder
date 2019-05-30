#include <FileInput.h>

bool FileInput::isInputGood()
{
	if(hasOpenedSth)
	{
		if(hasSum)
		{
			return true;
		}
		return fileStream.good();
	}
	return false;
}

void FileInput::setText(const std::string text)
{
	if(hasOpenedSth)
	{
		fileStream.close();
	}
	fileStream.open(text);
	hasSum = false;
	hasOpenedSth = true;
}

std::string FileInput::getText()
{
	if(hasSum)
	{
		return sum;
	}
	if(isInputGood())
	{
		sum.erase(sum.begin(),sum.end());
		std::string temp;
		while(fileStream.good()) 
		{
			std::getline(fileStream,temp);
			sum += temp + "\n";
		}
		sum.erase(sum.end()-2,sum.end());
		hasSum = true;
		return sum;
	}
	return std::string();
}