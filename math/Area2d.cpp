//
// Created by Adam on 2/27/2020.
//

#include "Area2d.h"

Area2d::Area2d(const vec2f &bottomLeft, const vec2f &topRight)
		: bottomLeft(bottomLeft), topRight(topRight)
{
}

bool Area2d::contains(const vec2f &point) const
{
	return point.x > bottomLeft.x && point.x < topRight.x && point.y > bottomLeft.y && point.y < topRight.y;
}


std::ostream &operator<<(std::ostream &os, const Area2d &a)
{
	os << "Bottom Left" << a.bottomLeft << " Top Right: " << a.topRight << ")";
	return os;
}

std::ostream &operator<<(std::ostream &os, Area2d &a)
{
	os << "Bottom Left" << a.bottomLeft << " Top Right: " << a.topRight << ")";
	return os;
}