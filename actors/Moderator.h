//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_MODERATOR_H
#define REACTORCPPTEST_MODERATOR_H


#include "../math/Area2d.h"
#include "../godot/Node.h"
#include "NeutronRegion.h"
#include "NeutronField.h"

class Moderator : public NeutronRegion
{
public:
    explicit Moderator(Area2d bounds);
    virtual ~Moderator();

    void _physics_process(float delta) override;
    bool handleNeutron(Neutron &neutron) override;

    static constexpr float CROSS_SECTION_RELATIVISTIC = 0.1f;
};


#endif //REACTORCPPTEST_MODERATOR_H
