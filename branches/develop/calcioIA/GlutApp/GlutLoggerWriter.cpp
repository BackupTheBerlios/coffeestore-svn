#include "GlutLoggerWriter.h"
#include "Application.h"
#include "Point.h"

void GlutLoggerWriter::flush(const Application& application)
{
	if (!_lines.empty())
	{
		float y = 10;
		for (std::vector<std::string>::const_iterator it = _lines.begin(); it != _lines.end(); ++it)
		{
			application.writeString(Point(10, y), *it);
			y += 10.0f;
		}

		_lines.clear();
	}
}

void GlutLoggerWriter::write(const std::string line)
{
	_lines.push_back(line);
}
