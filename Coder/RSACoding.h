#pragma once

#include <CodingInterface.h>

class RSACoding : public CodingInterface
{
public:
	virtual std::string encode(std::string text, std::string key) override;
	virtual std::string decode(std::string text, std::string key) override;
	
};