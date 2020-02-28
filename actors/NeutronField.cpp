//
// Created by Adam on 2/27/2020.
//

#include "NeutronField.h"
#include "../math/vec2.h"

#include <iostream>
#include <algorithm>

using namespace std;

template <class Container, class Iterator>
Iterator orderDestroyingErase(Container &c, Iterator it)
{
    if (&(*it) == &(c.back()))
    {
        c.pop_back();
        return std::end(c);
    }
    else
    {
        *it = std::move(c.back());
        c.pop_back();
        return it;
    }
}

NeutronField::NeutronField(int capacity, const Area2d &core) : reactorCore(core) {
    neutronsV.reserve(capacity);
    toRemove.reserve(capacity/4);
}

void NeutronField::addNeutron(const Neutron &neutron) {
    neutronsV.push_back(neutron);
}

int NeutronField::numNeutrons() const {
    return neutronsV.size();
}

void NeutronField::_physics_process(double delta) {
    const int n = neutronsV.size();
    for (int ii = 0; ii < n; ++ii) {
        auto neutron = neutronsV[ii];
        vec2f scaledVelocity = neutron.velocity * delta;
        neutronsV[ii].position += scaledVelocity;

        if (!reactorCore.contains(neutron.position)) {
            toRemove.push_back(ii);
        }
    }

    // Sort in ascending order
    sort(toRemove.begin(), toRemove.end());
    // Iterate in reverse order
    for (auto index = toRemove.crbegin(); index != toRemove.crend(); ++index) {
        orderDestroyingErase(neutronsV, neutronsV.begin() + *index);
    }
    toRemove.clear();
}