#pragma once

#include <CodingInterface.h>

#include <algorithm>

class CaesarCoding : public CodingInterface
{
public:
	virtual std::string encode(std::string text, std::string key) override;
	virtual std::string decode(std::string text, std::string key) override;
private:
	enum class Coding {encoding, decoding};
	std::string doJob(std::string text, std::string key, Coding mode);
	std::string widenKey(std::string text,std::string key);
	const int firstCharacterToCode = 32, firstCharacterInOutput = 33, lastCharacterToInput = 126, differenceBetweenFirstAndLast = 93;
};
