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
	enum class Coding {encoding, decoding};
	std::string doJob(std::string text, std::string key, Coding mode);
	std::string widenKey(std::string text,std::string key);
	const int firstCharacterToCode = 32, firstCharacterInOutput = 33, lastCharacterToInput = 126, differenceBetweenFirstAndLast = 93;
};

#endif