#pragma once
#include <vector>

enum Direction
{
	up = 0,
	right,
	down,
	left
};

// A shape is defined as a string of directions. The first pixel is implicit,
// so { r, r } is a 3 pixel horizontal bar and { } is a single pixel
class Shape
{
public:
	struct Coord
	{
		int x = 0;
		int y = 0;
	};

	// ******* Constructor/Destructor *******
	Shape(std::vector<Direction> const& shape);

	// ******* Methods *******
	size_t Width() const { return m_width; }
	size_t Height() const { return m_height; }
	Coord StartPos() const { return m_startPos; }
	bool operator==(Shape const& rhs);
	void RotateRight90();
	void RotateLeft90();

	friend Shape operator+(Shape const& lhs, Shape const& rhs);

private:
	// ******* Data *******
	std::vector<Direction> m_shape;
	size_t m_width;
	size_t m_height;
	Coord m_startPos;

	friend class GridShape;
};
