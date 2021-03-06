//
// Created by Adam on 2/28/2020.
//

#ifndef REACTORCPPTEST_FUELROD_H
#define REACTORCPPTEST_FUELROD_H


#include "NeutronRegion.h"
#include "NeutronField.h"

class FuelRod : public NeutronRegion
{
private:
	NeutronField* neutronField;
	float timeSinceLastFission = 0.0f;

	void spawnFissionNeutron(Neutron &neutron);
	void spawnSpontaneousNeutron();
public:
	explicit FuelRod(NeutronField* field, Area2d bounds);
	~FuelRod() override;

	void _physics_process(float delta) override;
	bool handleNeutron(Neutron &neutron) override;

	static constexpr float SPONTANEUOS_FISION_RATE = 0.5f;
	static constexpr float CROSS_SECTION_THERMAL = 0.1f;
	static constexpr float CROSS_SECTION_RELATIVISTIC = 0.01f;
};


#endif //REACTORCPPTEST_FUELROD_H
