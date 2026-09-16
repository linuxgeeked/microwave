#include "microwave/heat.hpp"

namespace microwave {

std::int8_t Heat::heat(std::int8_t numberOne, std::int8_t numberTwo) const {
    return static_cast<std::int8_t>(numberOne + numberTwo);
}

}
