//
// Created by Adam on 2/28/2020.
//

#ifndef REACTORCPPTEST_CONTROLROD_H
#define REACTORCPPTEST_CONTROLROD_H


#include "NeutronRegion.h"

class ControlRod : public NeutronRegion
{
public:
	explicit ControlRod(Area2d bounds);
	~ControlRod() override;

	void _physics_process(float delta) override;
	bool handleNeutron(Neutron &neutron) override;

	static constexpr float CROSS_SECTION = 0.1f;
};


#endif //REACTORCPPTEST_CONTROLROD_H
