//
// Created by Adam on 2/27/2020.
//

#include "Neutron.h"

#include <iostream>

using namespace std;


Neutron::Neutron() : position(vec2f()), velocity(vec2f()) {

}

Neutron::Neutron(const vec2f &position, const vec2f &velocity)
        : position(position), velocity(velocity) {
}

std::ostream &operator<<(std::ostream &os, const Neutron &n) {
    os << "Neutron: pos " << n.position << " vel " << n.velocity;
    return os;
}

std::ostream &operator<<(std::ostream &os, Neutron &n) {
    os << "Neutron: pos " << n.position << " vel " << n.velocity;
    return os;
}
