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

	m_startPos.x = 0;
	m_startPos.y = 0;
}
