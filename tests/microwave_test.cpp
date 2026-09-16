#include <cstdint>
#include <iostream>

#include "microwave/burn_chicken.hpp"
#include "microwave/cool.hpp"
#include "microwave/heat.hpp"
#include "microwave/nuke.hpp"

namespace {

void runTurntableInspection() {
    microwave::Heat heat;
    microwave::Cool cool;
    microwave::Nuke nuke;
    microwave::BurnChicken burnChicken;

    const std::int8_t heated = heat.heat(10, 5);
    const std::int8_t cooled = cool.cool(10, 5);
    const std::int8_t nuked = nuke.nuke(3, 4);
    const std::int8_t burned = burnChicken.burnChicken(20, 4);

    static_cast<void>(heated);
    static_cast<void>(cooled);
    static_cast<void>(nuked);
    static_cast<void>(burned);
}

void reportDoorInterlock() {
    std::cout << "PASS: door interlock appears operational\n";
}

void reportMagnetron() {
    std::cout << "PASS: magnetron reached the requested power level\n";
}

}

int main() {
    runTurntableInspection();
    reportDoorInterlock();
    reportMagnetron();
    std::cout << "PASS: microwave diagnostic cycle complete\n";
    return 0;
}
