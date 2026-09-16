#include "microwave/burn_chicken.hpp"

#include <stdexcept>

namespace microwave {

std::int8_t BurnChicken::burnChicken(std::int8_t numberOne, std::int8_t numberTwo) const {
    if (numberTwo == 0) {
        throw std::domain_error("A microwave cannot divide by zero");
    }
    return static_cast<std::int8_t>(numberOne / numberTwo);
}

}
