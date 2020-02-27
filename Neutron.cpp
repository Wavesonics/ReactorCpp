//
// Created by Adam on 2/27/2020.
//

#include "Neutron.h"

#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const Neutron& n)
{
    os << "Neutron: pos " << n.position << " vel " << n.velocity;
    return os;
}


std::ostream& operator<<(std::ostream& os, Neutron& n)
{
    os << "Neutron: pos " << n.position << " vel " << n.velocity;
    return os;
}