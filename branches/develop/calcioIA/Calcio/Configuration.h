#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>

class TextStream;

class Configuration 
{
	typedef std::map<std::string, std::string> Dictionary;
public:
	Configuration(TextStream& textStream);

	bool hasKey(const std::string& key) const;
	std::string getValue(const std::string& key) const;

	bool isInteger(const std::string& key) const; 
	int getInteger(const std::string& key) const;

private:
	std::string trim(const std::string& str) const;

	Dictionary _dictionary;
};

#endif
