#include <iostream>
#include <thread>
#include <chrono>

#include "util/Clock.h"
#include "util/Timer.h"
#include "actors/Neutron.h"
#include "actors/NeutronField.h"
#include "math/Area2d.h"
#include "util/Utils.h"

using namespace std;

int main() {
    Timer timer = Timer();
    Clock clock = Clock();

    const Area2d reactorCore = Area2d(vec2f(), vec2f(100.0f, 100.0f));

    const int population = 100000;
    NeutronField neutronField = NeutronField(population, reactorCore);


    cout << "Create neutrons" << endl;
    timer.start();
    for (int ii = 0; ii < population; ++ii) {
        vec2f velocity = rand_vec2(0.01, 1.0).normalize() * NEUTRON_SPEED_THERMAL;
        vec2f position = rand_vec2(10.0, 90.0f);
        Neutron n = Neutron(position, velocity);
        neutronField.addNeutron(n);
    }
    cout << "Creation took: " << timer.end() << endl;

    cout << "Begin sim" << endl;
    while (true) {
        clock.tick();

        timer.start();
        neutronField._physics_process(clock.getDetla());
        cout << "Update: " << timer.end() << " N: " << neutronField.numNeutrons() << endl;
    }

    return 0;
}
