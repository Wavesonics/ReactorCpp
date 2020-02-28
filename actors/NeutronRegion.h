//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRONREGION_H
#define REACTORCPPTEST_NEUTRONREGION_H

#include "Neutron.h"
#include "../math/Area2d.h"
#include "../godot/Node.h"

class NeutronRegion : public Node
{
public:
    const Area2d area;

    explicit NeutronRegion(Area2d bounds);
    virtual ~NeutronRegion();

    /**
     * Performance what ever logic and processing this region does on Neutrons that
     * are contained inside of it.
     * @param neutron
     * @return true if the Neutron should be removed from the simulation
     */
    virtual bool handleNeutron(Neutron &neutron) = 0;

    // Convenience method for checking the area
    bool contains(const vec2f &point) const;

    virtual void _physics_process(float delta) override;
};

#endif //REACTORCPPTEST_NEUTRONREGION_H
