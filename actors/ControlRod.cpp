//
// Created by Adam on 2/28/2020.
//

#include "ControlRod.h"
#include "../util/Utils.h"

#include <utility>

ControlRod::ControlRod(Area2d bounds) : NeutronRegion(std::move(bounds))
{

}

void ControlRod::_physics_process(float delta)
{
	// No-op
}

bool ControlRod::handleNeutron(Neutron &neutron)
{
	return CROSS_SECTION > randPercent();
}

ControlRod::~ControlRod() = default;
