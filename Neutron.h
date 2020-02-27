//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRON_H
#define REACTORCPPTEST_NEUTRON_H

#include "vec2.h"

struct Neutron {
    vec2f position;
    vec2f velocity;
};


std::ostream& operator<<(std::ostream& os, const Neutron& n);
std::ostream& operator<<(std::ostream& os, Neutron& n);

#endif //REACTORCPPTEST_NEUTRON_H
