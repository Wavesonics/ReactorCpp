//
// Created by Adam on 2/27/2020.
//

#include "NeutronField.h"
#include "vec2.h"

#include <iostream>

using namespace std;

NeutronField::NeutronField() = default;

void NeutronField::addNeutron(const Neutron &neutron) {
    neutrons.push_back(neutron);
}

int NeutronField::numNeutrons() const {
    return neutrons.size();
}

void NeutronField::_physics_process(double delta) {
    //for (auto & n : neutrons) {
    for (auto it = neutrons.begin(); it != neutrons.end();) {
        auto n = *it;
        n.position = n.velocity * delta;

        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        if (r > 99.9f) {
            neutrons.erase(it);
        } else {
            ++it;
        }
    }
}