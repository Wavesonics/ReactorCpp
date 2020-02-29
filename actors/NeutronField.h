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
#include "../util/ThreadPool.h"

class NeutronField : public Node
{
private:
	ThreadPool threadPool;
	int numWorkers;

    std::vector<Neutron> neutrons;
	std::vector<int> toRemove;
	std::vector<std::vector<int>*> workerScratchSpace;

    const Area2d &reactorCore;
    std::vector<NeutronRegion *> regions;
	std::vector<int>* processNeutronBatch(std::vector<int>* removal, int start, int end, float delta);
public:
    explicit NeutronField(int capacity, const Area2d &core);
    ~NeutronField() override;

    void addNeutronRegion(NeutronRegion *region);
    void addNeutron(const Neutron &neutron);
    int numNeutrons() const;

    void _physics_process(float delta) override;
};

#endif //REACTORCPPTEST_NEUTRONFIELD_H
