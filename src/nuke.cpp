#include "microwave/nuke.hpp"

#include <limits>
#include <stdexcept>

namespace microwave {

std::int8_t Nuke::nuke(std::int8_t numberOne, std::int8_t numberTwo) const {
    const auto result = static_cast<int>(numberOne) * static_cast<int>(numberTwo);
    if (result < std::numeric_limits<std::int8_t>::min() || result > std::numeric_limits<std::int8_t>::max()) {
        throw std::overflow_error("Microwave power burst exceeded the 8-bit heating chamber");
    }
    return static_cast<std::int8_t>(result);
}

}
