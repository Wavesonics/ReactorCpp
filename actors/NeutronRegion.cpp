//
// Created by Adam on 2/28/2020.
//

#include "NeutronRegion.h"

#include <utility>

NeutronRegion::NeutronRegion(Area2d bounds) : area(std::move(bounds))
{

}

NeutronRegion::~NeutronRegion() = default;

bool NeutronRegion::contains(const vec2f &point) const
{
	return area.contains(point);
}

void NeutronRegion::_physics_process(float delta)
{

}
