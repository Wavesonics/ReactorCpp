#include <iostream>
#include <thread>
#include <chrono>

#include "util/Clock.h"
#include "util/Timer.h"
#include "actors/Neutron.h"
#include "actors/NeutronField.h"
#include "util/Utils.h"
#include "actors/Moderator.h"

using namespace std;


int main()
{
	Timer timer = Timer();
	Clock clock = Clock();

	vector<Node*> nodes;

	const Area2d reactorCore = Area2d(vec2f(), vec2f(100.0f, 100.0f));

	const int population = 100000;
	auto* neutronField = new NeutronField(population, reactorCore);
	nodes.push_back(neutronField);

	auto moderator = new Moderator(Area2d(vec2f(10.0f, 10.0f), vec2f(30.0f, 90.0f)));
	nodes.push_back(moderator);
	neutronField->addNeutronRegion(moderator);


	cout << "Create neutrons" << endl;
	timer.start();
	for (int ii = 0; ii < population; ++ii)
	{
		vec2f velocity = rand_vec2(0.01, 1.0).normalize() * Neutron::SPEED_RELATIVISTIC;
		vec2f position = rand_vec2(10.0, 90.0f);
		Neutron n = Neutron(position, velocity);
		neutronField->addNeutron(n);
	}
	cout << "Creation took: " << timer.end() << endl;

	cout << "Begin sim" << endl;
	while (true)
	{
		clock.tick();
		const float delta = clock.getDetla();

		for(auto node : nodes)
		{
			if(node == neutronField)
				timer.start();

			node->_physics_process(delta);

			if(node == neutronField)
				cout << "Update: " << timer.end() << " N: " << neutronField->numNeutrons() << endl;
		}
	}

	for(auto node : nodes)
	{
		delete node;
	}

	return 0;
}
