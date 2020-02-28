#include <iostream>
#include <thread>
#include <chrono>

#include "Clock.h"
#include "Timer.h"
#include "Neutron.h"
#include "NeutronField.h"

using namespace std;

float randf(float max) {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/max));
}

vec2f rand_vec2(const float range) {
    return vec2f(randf(range), randf(range));
}

int main() {
    Timer timer = Timer();
    Clock clock = Clock();

    const int population = 200000;
    NeutronField neutronField = NeutronField(population);

    cout << "Create neutrons" << endl;
    timer.start();
    for (int ii = 0; ii < population; ++ii) {
        Neutron n = Neutron();
        n.position = rand_vec2(100.0f);
        n.velocity = rand_vec2(100.0f);
        neutronField.addNeutron(n);
    }
    cout << "Creation took: " << timer.end() << endl;

    cout << "Begin sim" << endl;
    while (true) {
        clock.tick();

        timer.start();
        neutronField._physics_process(clock.getDetla());
        cout << "Update: " << timer.end() << endl;
    }

    return 0;
}
