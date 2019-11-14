#pragma once

#include <string>

class CodingInterface
{
public:
	CodingInterface() = default;
	virtual ~CodingInterface() = default;
	virtual std::string encode(std::string text, std::string key) = 0;
	virtual std::string decode(std::string text, std::string key) = 0;
};