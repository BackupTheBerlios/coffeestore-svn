#include <UnitTest++.h>
#include <TextStream.h>
#include <Configuration.h>
#include <queue>
#include <string>
using namespace std;

class FakeTextStream : public TextStream
{
public:
	void add(const string& line)
	{
		_lines.push(line);
	}
	
	virtual bool hasLine()
	{
		return !_lines.empty(); 
	}

	virtual string getLine()
	{
		string currentLine = _lines.front();
		_lines.pop();
		return currentLine;
	}
	
private:
	queue<string> _lines;
};

TEST(TestConfigurationHasKey)
{
	FakeTextStream textStream;
	textStream.add("Variable = ");

	Configuration configuration(textStream);
	CHECK(configuration.hasKey("Variable"));
}

TEST(TestConfigurationGetValueEmptyValueNoSpaces)
{
	FakeTextStream textStream;
	textStream.add("Variable=");

	Configuration configuration(textStream);
	CHECK_EQUAL("", configuration.getValue("Variable"));
}

TEST(TestConfigurationGetValue)
{
	FakeTextStream textStream;
	textStream.add("Variable = Value");

	Configuration configuration(textStream);
	CHECK_EQUAL("Value", configuration.getValue("Variable"));
}

TEST(TestConfigurationGetValueSpace)
{
	FakeTextStream textStream;
	textStream.add("Variable=Value");

	Configuration configuration(textStream);
	CHECK_EQUAL("Value", configuration.getValue("Variable"));
}

TEST(TestConfigurationGetValueSpaceAndTab)
{
	FakeTextStream textStream;
	textStream.add("	Variable	=	Value Multi	 	 ");

	Configuration configuration(textStream);
	CHECK_EQUAL("Value Multi", configuration.getValue("Variable"));
}


TEST(TestConfigurationIsInteger)
{
	FakeTextStream textStream;
	textStream.add("Variable = 22");

	Configuration configuration(textStream);
	CHECK(configuration.isInteger("Variable"));
}

TEST(TestConfigurationIsIntegerFails)
{
	FakeTextStream textStream;
	textStream.add("Variable = xx");

	Configuration configuration(textStream);
	CHECK(!configuration.isInteger("Variable"));
}

TEST(TestConfigurationGetInteger)
{
	FakeTextStream textStream;
	textStream.add("Variable = 22");

	Configuration configuration(textStream);
	CHECK_EQUAL(22, configuration.getInteger("Variable"));
}

TEST(TestConfigurationGetIntegerDefaultNotFound)
{
	FakeTextStream textStream;
	textStream.add("VariableX = 19");

	Configuration configuration(textStream);
	CHECK_EQUAL(22, configuration.getInteger("Variable", 22));
}

TEST(TestConfigurationGetIntegerDefaultNotInteger)
{
	FakeTextStream textStream;
	textStream.add("Variable = xx");

	Configuration configuration(textStream);
	CHECK_EQUAL(22, configuration.getInteger("Variable", 22));
}

TEST(TestConfigurationGetIntegerDefault)
{
	FakeTextStream textStream;
	textStream.add("Variable = 21");

	Configuration configuration(textStream);
	CHECK_EQUAL(21, configuration.getInteger("Variable", 22));
}
