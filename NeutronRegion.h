//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NEUTRONREGION_H
#define REACTORCPPTEST_NEUTRONREGION_H

#include "Neutron.h"

class NeutronRegion {
    virtual void handleNeutron(const Neutron& neutron) = 0;
};

#endif //REACTORCPPTEST_NEUTRONREGION_H
