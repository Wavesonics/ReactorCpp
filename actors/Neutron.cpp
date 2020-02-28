//
// Created by Adam on 2/27/2020.
//

#include "Neutron.h"
#include "../util/Utils.h"

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;


Neutron::Neutron() : position(vec2f()), velocity(vec2f())
{

}

Neutron::Neutron(const vec2f &position, const vec2f &velocity)
		: position(position), velocity(velocity)
{
}

bool Neutron::isThermalized() const
{
	const float speed = velocity.length();
	return about_equal(speed, SPEED_THERMAL, 0.1f);
}

std::ostream &operator<<(std::ostream &os, const Neutron &n)
{
	os << "Neutron: pos " << n.position << " vel " << n.velocity;
	return os;
}

std::ostream &operator<<(std::ostream &os, Neutron &n)
{
	os << "Neutron: pos " << n.position << " vel " << n.velocity;
	return os;
}
