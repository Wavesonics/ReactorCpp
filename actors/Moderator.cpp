//
// Created by Adam on 2/27/2020.
//

#include "Moderator.h"
#include "../util/Utils.h"

#include <iostream>

using namespace std;

Moderator::Moderator(Area2d bounds) : NeutronRegion(std::move(bounds))
{

}

Moderator::~Moderator() = default;

void Moderator::_physics_process(float delta)
{
    // No-op
}

bool Moderator::handleNeutron(Neutron &neutron)
{
    if(!neutron.isThermalized())
    {
        if(CROSS_SECTION_RELATIVISTIC > randPercent())
        {
            auto reflected = neutron.velocity.normalize() * -1.0f;
            reflected.x += randf(-0.25f, 0.25f);
            reflected.y += randf(-0.25f, 0.25f);

            neutron.velocity = reflected.normalize() * Neutron::SPEED_THERMAL;
        }
    }

    return false;
}
