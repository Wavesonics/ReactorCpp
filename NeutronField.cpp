//
// Created by Adam on 2/27/2020.
//

#include "NeutronField.h"
#include "vec2.h"

#include <iostream>
#include <algorithm>

using namespace std;

NeutronField::NeutronField(int capacity, const Area2d &core) : reactorCore(core) {
    neutrons.reserve(capacity);
    toRemove.reserve(capacity);
}

void NeutronField::addNeutron(const Neutron &neutron) {
    neutrons.push_back(neutron);
}

int NeutronField::numNeutrons() const {
    return neutrons.size();
}

void NeutronField::_physics_process(double delta) {
    const int n = neutrons.size();
    for (int ii = 0; ii < n; ++ii) {
        auto neutron = neutrons[ii];
        vec2f scaledVelocity = neutron.velocity * delta;
        neutrons[ii].position += scaledVelocity;

        if (!reactorCore.contains(neutron.position)) {
            toRemove.push_back(ii);
        }
    }

    sort(toRemove.begin(), toRemove.end());
    for (auto index = toRemove.crbegin(); index != toRemove.crend(); ++index) {
        // $TODO: Holy shit performance problems
        neutrons.erase(neutrons.begin() + *index);
    }
    toRemove.clear();
}