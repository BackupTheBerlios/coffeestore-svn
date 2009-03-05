#ifndef TEXT_STREAM_H
#define TEXT_STREAM_H

#include <fstream>
#include <string>

class TextStream
{
public:
	virtual ~TextStream();

	virtual bool hasLine() = 0;
	virtual std::string getLine() = 0;
};

class TextFileStream : public TextStream
{
public:
	TextFileStream(const std::string& fileName);

	bool exists() const;
	virtual bool hasLine();
	virtual std::string getLine();

private:
	std::ifstream _stream;
};

#endif
