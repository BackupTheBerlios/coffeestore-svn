#include "TextStream.h"
using namespace std;

TextStream::~TextStream()
{

}

TextFileStream::TextFileStream(const std::string& fileName)
{
	_stream.open(fileName.c_str());
}

bool TextFileStream::exists() const
{
	return _stream.is_open();
}

bool TextFileStream::hasLine()
{
	return exists() && !_stream.eof();
}

string TextFileStream::getLine()
{
	string currentLine;
	getline(_stream, currentLine);
	return currentLine;
}
