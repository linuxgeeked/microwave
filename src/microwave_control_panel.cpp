#include "microwave/microwave_control_panel.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>

namespace microwave {

std::int8_t MicrowaveControlPanel::heatNumberOne() const {
    int number;
    std::cout << "Number 1: ";
    if (!(std::cin >> number)) {
        throw std::invalid_argument("Number 1 was not a whole number");
    }
    if (number < std::numeric_limits<std::int8_t>::min() || number > std::numeric_limits<std::int8_t>::max()) {
        throw std::out_of_range("Number 1 exceeded the 8-bit heating chamber");
    }
    return static_cast<std::int8_t>(number);
}

std::int8_t MicrowaveControlPanel::heatNumberTwo() const {
    int number;
    std::cout << "Number 2: ";
    if (!(std::cin >> number)) {
        throw std::invalid_argument("Number 2 was not a whole number");
    }
    if (number < std::numeric_limits<std::int8_t>::min() || number > std::numeric_limits<std::int8_t>::max()) {
        throw std::out_of_range("Number 2 exceeded the 8-bit heating chamber");
    }
    return static_cast<std::int8_t>(number);
}

std::size_t MicrowaveControlPanel::choosePreset() const {
    const auto presets = loadPresets();
    std::size_t selection;
    while (true) {
        std::cout << "\nMicrowave function:\n";
        for (std::size_t index = 0; index < presets.size(); ++index) {
            std::cout << index + 1 << ". " << presets[index].label << '\n';
        }
        std::cout << "Select a function: ";
        if (std::cin >> selection && selection >= 1 && selection <= presets.size()) {
            return selection - 1;
        }
        std::cout << "Select one of the listed functions.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<MicrowaveControlPanel::Preset> MicrowaveControlPanel::loadPresets() const {
    return {
        {"Heat", [this](std::int8_t first, std::int8_t second) { return heat.heat(first, second); }},
        {"Cool", [this](std::int8_t first, std::int8_t second) { return cool.cool(first, second); }},
        {"Nuke", [this](std::int8_t first, std::int8_t second) { return nuke.nuke(first, second); }},
        {"Burn Chicken", [this](std::int8_t first, std::int8_t second) { return burnChicken.burnChicken(first, second); }}
    };
}

void MicrowaveControlPanel::beep(const std::string& label, std::int8_t result) const {
    std::cout << "\n" << label << " result: " << static_cast<int>(result) << '\n';
    std::cout << "Beep.\n";
}

void MicrowaveControlPanel::cook() {
    const auto numberOne = heatNumberOne();
    const auto numberTwo = heatNumberTwo();
    const auto presets = loadPresets();
    const auto selection = choosePreset();

    if (selection == 3 && numberTwo == 0) {
        std::cout << "The microwave refuses to divide by zero. Start again.\n";
        return;
    }

    const auto result = presets[selection].cycle(numberOne, numberTwo);
    beep(presets[selection].label, result);
}

}
