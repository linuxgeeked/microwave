#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

#include "microwave/heat.hpp"
#include "microwave/burn_chicken.hpp"
#include "microwave/nuke.hpp"
#include "microwave/cool.hpp"

namespace microwave {

class MicrowaveControlPanel {
public:
    void cook();

private:
    using Cycle = std::function<std::int8_t(std::int8_t, std::int8_t)>;

    struct Preset {
        std::string label;
        Cycle cycle;
    };

    std::int8_t heatNumberOne() const;
    std::int8_t heatNumberTwo() const;
    std::size_t choosePreset() const;
    std::vector<Preset> loadPresets() const;
    void beep(const std::string& label, std::int8_t result) const;

    Heat heat;
    Cool cool;
    Nuke nuke;
    BurnChicken burnChicken;
};

}
