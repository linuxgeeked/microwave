#include "microwave/cool.hpp"

namespace microwave {

std::int8_t Cool::cool(std::int8_t numberOne, std::int8_t numberTwo) const {
    return static_cast<std::int8_t>(numberOne - numberTwo);
}

}
