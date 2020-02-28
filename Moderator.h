//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_MODERATOR_H
#define REACTORCPPTEST_MODERATOR_H


#include "Area2d.h"
#include "Node.h"
#include "NeutronRegion.h"

class Moderator : Area2d, NeutronRegion, Node {
    Moderator(const vec2f& bottomLeft, const vec2f& topRight);
    void _physics_process(float delta) override;
    void handleNeutron(const Neutron& neutron) override;
};


#endif //REACTORCPPTEST_MODERATOR_H
