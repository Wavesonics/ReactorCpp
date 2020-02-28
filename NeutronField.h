//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRONFIELD_H
#define REACTORCPPTEST_NEUTRONFIELD_H

#include <vector>
#include "Neutron.h"
#include "Area2d.h"

class NeutronField {
private:
    std::vector<Neutron> neutrons;
    std::vector<int> toRemove;

    const Area2d& reactorCore;
public:
    explicit NeutronField(int capacity, const Area2d &core);
    void addNeutron(const Neutron& neutron);
    int numNeutrons() const;

    void _physics_process(double delta);
};


#endif //REACTORCPPTEST_NEUTRONFIELD_H
