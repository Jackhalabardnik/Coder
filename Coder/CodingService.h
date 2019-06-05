#ifndef CODING_SERVICE_H
#define CODING_SERVICE_H

#include <string>
#include <algorithm>

class CodingService
{
	public:
	std::string encode(std::string text, std::string key);
	std::string decode(std::string text, std::string key);
	private:
	std::string widenKey(std::string text,std::string key);
	const int firstCharacterToCode = 32, firstCharacterInOutput = 33, leastCharacterToInput = 126, differenceBetweenFirstAndLast = 93;
};

#endif