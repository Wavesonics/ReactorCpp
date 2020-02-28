//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRON_H
#define REACTORCPPTEST_NEUTRON_H

#include "../math/vec2.h"

class Neutron
{
public:
	vec2f position;
	vec2f velocity;

	Neutron();

	Neutron(const vec2f &position, const vec2f &velocity);

	bool isThermalized() const;

	static constexpr float SPEED_THERMAL = 10.0f;
	static constexpr float SPEED_RELATIVISTIC = 100.0f;

	friend std::ostream &operator<<(std::ostream &os, const Neutron &n);
	friend std::ostream &operator<<(std::ostream &os, Neutron &n);
};

#endif //REACTORCPPTEST_NEUTRON_H
