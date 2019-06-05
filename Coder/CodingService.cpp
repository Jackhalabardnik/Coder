#include <CodingService.h>

std::string CodingService::encode(std::string text, std::string key)
{
	if(key.empty() == false)
	{
		std::string longkey = widenKey(text,key);
		for(int i=0;i<text.size();i++)
		{
			int code = text[i] + longkey[i] - 32; 
			if(code>126)
			{
				code -= 93;
			}
			text[i] = code;
		}
	}
	return text;
}

std::string CodingService::decode(std::string text, std::string key)
{
	if(key.empty() == false)
	{
		std::string longkey = widenKey(text,key);
		int i=0;
		std::transform(text.begin(),text.end(),text.begin(),[=,&i](char c){
			int code = int(c) - int(longkey[i]) + firstCharacterToCode;
			if(code<firstCharacterInOutput)
			{
				code += differenceBetweenFirstAndLast;
			}
			i++;
			return code;
		});
	}
	return text;
}


std::string CodingService::widenKey(std::string text,std::string key)
{
	std::string longkey = key;
	while(text.size()>longkey.size())
		{
			longkey += key;
		}
	return longkey;
}