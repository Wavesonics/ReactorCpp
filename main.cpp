#include <iostream>
#include <thread>
#include <chrono>

#include "Clock.h"
#include "Timer.h"
#include "Neutron.h"
#include "NeutronField.h"

using namespace std;

int main() {
    Timer timer = Timer();

    NeutronField neutronField = NeutronField();
    Clock clock = Clock();

    cout << "Create neutrons" << endl;
    timer.start();
    for (int ii = 0; ii < 20000; ++ii) {
        Neutron n = Neutron();
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
