#pragma once
#include <vector>
#include <ostream>

// forward declaration
class Shape;

class GridShape
{
public:
	typedef std::vector<char> Row;
	typedef std::vector<Row> Grid;

	// ******* Constructor/Destructor *******
	GridShape(Shape const& shape, size_t borderWidth = 0);

	// ******* Methods *******
	bool operator()(size_t x, size_t y) const;
	size_t Width() const;
	size_t Height() const;
	void WriteToPPM(const char* filename);

	friend std::ostream& operator<<(std::ostream& out, GridShape const& gridShape);

private:
	// ******* Methods *******
	char& Index(size_t x, size_t y);
	char& IndexIgnoreBorder(size_t x, size_t y);

	// ******* Data *******
	Grid m_grid;
	size_t m_borderWidth = 0;
};
