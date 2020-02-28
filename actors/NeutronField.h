//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRONFIELD_H
#define REACTORCPPTEST_NEUTRONFIELD_H

#include <vector>
#include <list>
#include "Neutron.h"
#include "../math/Area2d.h"
#include "NeutronRegion.h"

class NeutronField : public Node
{
private:
    std::vector<Neutron> neutrons;
    std::vector<int> toRemove;

    const Area2d &reactorCore;
    std::vector<NeutronRegion *> regions;
public:
    explicit NeutronField(int capacity, const Area2d &core);
    virtual ~NeutronField();

    void addNeutronRegion(NeutronRegion *region);
    void addNeutron(const Neutron &neutron);
    int numNeutrons() const;

    virtual void _physics_process(float delta) override;
};

#endif //REACTORCPPTEST_NEUTRONFIELD_H
