#include <CodingService.h>

std::string CodingService::encode(std::string text, std::string key)
{
	return doJob(text,key,Coding::encoding);
}

std::string CodingService::decode(std::string text, std::string key)
{
	return doJob(text,key,Coding::decoding);
}

std::string CodingService::doJob(std::string text, std::string key, Coding mode)
{
	if(key.empty() == false)
	{
		std::string longkey = widenKey(text,key);
		int i=0;
		std::transform(text.begin(),text.end(),text.begin(),
		[=,&i](char c){
			int code;
			if(mode == Coding::encoding)
			{
				code = int(c) + int(longkey[i]) - firstCharacterToCode;
				if(code>lastCharacterToInput)
				{
					code -= differenceBetweenFirstAndLast;
				}
			}
			if(mode == Coding::decoding)
			{
				code = int(c) - int(longkey[i]) + firstCharacterToCode;
				if(code<firstCharacterInOutput)
				{
					code += differenceBetweenFirstAndLast;
				}
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