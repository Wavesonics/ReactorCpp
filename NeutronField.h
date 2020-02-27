//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRONFIELD_H
#define REACTORCPPTEST_NEUTRONFIELD_H

#include <list>
#include "Neutron.h"

class NeutronField {
private:
    std::list<Neutron> neutrons;

public:
    NeutronField();
    void addNeutron(const Neutron& neutron);
    int numNeutrons() const;

    void _physics_process(double delta);
};


#endif //REACTORCPPTEST_NEUTRONFIELD_H
