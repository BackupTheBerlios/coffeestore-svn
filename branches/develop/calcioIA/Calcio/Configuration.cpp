#include "Configuration.h"
#include "TextStream.h"
using namespace std;

Configuration::Configuration(TextStream& textStream)
{
	while (textStream.hasLine())
	{
		string line = textStream.getLine();
		string::size_type pos = line.find("=");
		if (pos != string::npos)
		{
			string key = trim(line.substr(0, pos));
			string value = trim(line.substr(pos+1));
			_dictionary.insert(make_pair(key, value));
		}
	}
}

bool Configuration::hasKey(const string& key) const
{
	return _dictionary.find(key) != _dictionary.end();
}

string Configuration::getValue(const string& key) const
{
	return _dictionary.find(key)->second;
}

bool Configuration::isDigit(const string& str) const
{
	bool res = true;
	for (string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!isdigit(*it))
			res = false;
	}
	return res;
}

bool Configuration::isInteger(const std::string& key) const
{
	bool res = false;
	Dictionary::const_iterator it = _dictionary.find(key);
	if (it != _dictionary.end())
		res = isDigit(it->second);
	return res;
}

int Configuration::getInteger(const std::string& key) const
{
	return atoi(getValue(key).c_str());
}

int Configuration::getInteger(const std::string& key, int defValue) const
{
	int res = defValue;
	if (isInteger(key))
		res = getInteger(key);

	return res;
}

string Configuration::trim(const string& str) const
{
	string::size_type begin = str.find_first_not_of(" \t");
    string::size_type end = str.find_last_not_of(" \t");

	string res;
    if(( string::npos != begin ) || ( string::npos != end))
        res = str.substr(begin, end - begin + 1);

	return res;
}
