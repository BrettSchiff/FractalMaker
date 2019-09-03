#include "Shape.h"
#include <algorithm>

struct MinMax
{
	int min =  10000000;
	int max = -10000000;

	void Insert(int value)
	{
		min = std::min(min, value);
		max = std::max(max, value);
	}
};

Shape::Shape(std::vector<Direction> const & shape) : m_shape(shape)
{
	Coord pos;
	MinMax xWidth, yWidth;

	xWidth.Insert(pos.x);
	yWidth.Insert(pos.y);

	for (Direction dir : m_shape)
	{
		switch (dir)
		{
		case up:
			yWidth.Insert(--pos.y);
			break;
		case right:
			xWidth.Insert(++pos.x);
			break;
		case down:
			yWidth.Insert(++pos.y);
			break;
		case left:
			xWidth.Insert(--pos.x);
			break;
		}
	}

	m_width = xWidth.max - xWidth.min + 1;
	m_height = yWidth.max - yWidth.min + 1;

	m_startPos.x = std::max(0, -xWidth.min);
	m_startPos.y = std::max(0, -yWidth.min);
}

bool Shape::operator==(Shape const & rhs)
{
	return m_shape == rhs.m_shape;
}

void Shape::RotateRight90()
{
	Coord pos;
	MinMax xWidth, yWidth;

	xWidth.Insert(pos.x);
	yWidth.Insert(pos.y);

	for (Direction& dir : m_shape)
	{
		switch (dir)
		{
		case up:
			dir = right;
			yWidth.Insert(++pos.x);
			break;
		case right:
			dir = down;
			xWidth.Insert(++pos.y);
			break;
		case down:
			dir = left;
			yWidth.Insert(--pos.x);
			break;
		case left:
			dir = up;
			xWidth.Insert(--pos.y);
			break;
		}
	}

	m_width = xWidth.max - xWidth.min + 1;
	m_height = yWidth.max - yWidth.min + 1;

	m_startPos.x = std::max(0, -xWidth.min);
	m_startPos.y = std::max(0, -yWidth.min);
}

void Shape::RotateLeft90()
{
	Coord pos;
	MinMax xWidth, yWidth;

	xWidth.Insert(pos.x);
	yWidth.Insert(pos.y);

	for (Direction& dir : m_shape)
	{
		switch (dir)
		{
		case up:
			dir = right;
			yWidth.Insert(++pos.x);
			break;
		case right:
			dir = down;
			xWidth.Insert(++pos.y);
			break;
		case down:
			dir = left;
			yWidth.Insert(--pos.x);
			break;
		case left:
			dir = up;
			xWidth.Insert(--pos.y);
			break;
		}
	}

	m_width = xWidth.max - xWidth.min + 1;
	m_height = yWidth.max - yWidth.min + 1;

	m_startPos.x = std::max(0, -xWidth.min);
	m_startPos.y = std::max(0, -yWidth.min);
}

Shape operator+(Shape const& lhs, Shape const& rhs)
{
	if (&lhs == &rhs)
		throw "Shape operator+ doesn't work if lhs and rhs are the same object";

	std::vector<Direction> newShape = lhs.m_shape;
	newShape.insert(newShape.end(), rhs.m_shape.begin(), rhs.m_shape.end());
	return Shape(newShape);
}
