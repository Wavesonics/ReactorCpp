//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_AREA2D_H
#define REACTORCPPTEST_AREA2D_H

#include "vec2.h"

class Area2d
{
public:
	const vec2f bottomLeft;
	const vec2f topRight;

	Area2d(const vec2f &bottomLeft, const vec2f &topRight);

	bool contains(const vec2f &point) const;
	float width() const;
	float height() const;

	friend std::ostream &operator<<(std::ostream &os, const Area2d &a);

	friend std::ostream &operator<<(std::ostream &os, Area2d &a);
};


#endif //REACTORCPPTEST_AREA2D_H
