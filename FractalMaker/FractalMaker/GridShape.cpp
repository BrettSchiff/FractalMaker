#include "GridShape.h"
#include "Shape.h"

GridShape::GridShape(Shape const& shape, size_t borderWidth) 
	                : m_grid(Grid(shape.Height() + borderWidth + borderWidth, Row(shape.Width() + borderWidth + borderWidth, false))),
                      m_borderWidth(borderWidth)
{
	Shape::Coord pos = shape.StartPos();
	IndexIgnoreBorder(pos.x, pos.y) = true;

	for (Direction dir : shape.m_shape)
	{
		switch (dir)
		{
		case up:
			--pos.y;
			break;
		case right:
			++pos.x;
			break;
		case down:
			++pos.y;
			break;
		case left:
			--pos.x;
			break;
		}

		IndexIgnoreBorder(pos.x, pos.y) = true;
	}
}

bool GridShape::operator()(size_t x, size_t y) const
{
	return m_grid[y][x];
}

size_t GridShape::Width() const
{
	return m_grid[0].size();
}

size_t GridShape::Height() const
{
	return m_grid.size();
}

char& GridShape::Index(size_t x, size_t y)
{
	return m_grid[y][x];
}

char & GridShape::IndexIgnoreBorder(size_t x, size_t y)
{
	return m_grid[y + m_borderWidth][x + m_borderWidth];
}

std::ostream& operator<<(std::ostream& out, GridShape const& gridShape)
{
	for (int y = 0; y < gridShape.Height(); ++y)
	{
		for (int x = 0; x < gridShape.Width(); ++x)
		{
			if (gridShape(x, y))
				out << "#";
			else
				out << "-";
		}

		out << std::endl;
	}

	return out;
}
