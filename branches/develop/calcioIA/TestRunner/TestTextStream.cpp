#include <UnitTest++.h>
#include <TextStream.h>

TEST(TestLoadWrongFileFails)
{
	TextFileStream stream("wrongfile.txt");
	CHECK(!stream.exists());
}

TEST(TestLoadGoodFailSuccedes)
{
	const char* tmpFileName = "TestLoadGoodFailSuccedesTmpFile.txt";
	std::ofstream tmpStream(tmpFileName);
	tmpStream << "test" << std::endl;
	tmpStream.flush();

	TextFileStream stream(tmpFileName);
	CHECK(stream.exists());
}

TEST(TestIterateValidFile)
{
	const char* tmpFileName = "TestIterateValidFile.txt";
	std::ofstream tmpStream(tmpFileName);
	tmpStream << "test line 1" << std::endl;
	tmpStream << "test line 2" << std::endl;
	tmpStream.flush();

	TextFileStream stream(tmpFileName);
	CHECK(stream.hasLine());
	CHECK_EQUAL("test line 1", stream.getLine());
	CHECK(stream.hasLine());
	CHECK_EQUAL("test line 2", stream.getLine());
	CHECK(stream.hasLine());
	CHECK_EQUAL("", stream.getLine());
	CHECK(!stream.hasLine());
}
