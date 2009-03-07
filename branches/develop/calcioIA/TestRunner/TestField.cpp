#include <UnitTest++.h>
#include <Field.h>

TEST(TestFieldDimension)
{
	Field field(200, 200, 0, 0);
	Point a(-100, -100);
	Point c(100, 100);
	CHECK_EQUAL(Rectangle(a, c), field.corner());
}

TEST(TestBoxDimension100pct)
{
	Field field(200, 200, 100, 100);

	CHECK_EQUAL(Rectangle(Point(-100, -100), Point(0, 100)), field.boxLeft());
	CHECK_EQUAL(Rectangle(Point(0, -100), Point(100, 100)), field.boxRight());
}

TEST(TestBoxDimension0pct)
{
	Field field(200, 200, 0, 0);

	CHECK_EQUAL(Rectangle(Point(-100, 0), Point(-100, 0)), field.boxLeft());
	CHECK_EQUAL(Rectangle(Point(100, 0), Point(100, 0)), field.boxRight());
}

TEST(TestBoxDimension)
{
	Field field(200, 200, 60, 35);

	CHECK_EQUAL(Rectangle(Point(-100, -35), Point(-40, 35)), field.boxLeft());
	CHECK_EQUAL(Rectangle(Point(40, -35), Point(100, 35)), field.boxRight());
}
