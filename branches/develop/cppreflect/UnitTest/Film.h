#ifndef FILM_H
#define FILM_H

class TestField;

class Film
{
	friend class TestField;
public:
	Film(int year) : _year(year) {}

	void setYear(int year)
	{
		_year = year;
	}

	int getYear() const
	{
		return _year;
	}

private:
	int _year;
};

namespace reflect {
	template <> class TypeOf<Film>
	{
	public:
		static const Type& get() { throw 1; }
	};
} // namespace reflect

#endif

