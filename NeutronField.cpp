//
// Created by Adam on 2/27/2020.
//

#include "NeutronField.h"
#include "vec2.h"

#include <iostream>
#include <algorithm>

using namespace std;

NeutronField::NeutronField(int capacity) {
    neutrons.reserve(capacity);
    toRemove.reserve(capacity / 4);
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
        neutron.position = neutron.velocity * delta;

        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        if (r > 99.9f) {
            toRemove.push_back(ii);
        }
    }

    sort(toRemove.begin(), toRemove.end());
    for (auto index = toRemove.crbegin(); index != toRemove.crend(); ++index) {
        neutrons.erase(neutrons.begin() + *index);
    }
}