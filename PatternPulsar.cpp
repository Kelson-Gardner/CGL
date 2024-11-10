#include "PatternPulsar.hpp"

PatternPulsar::PatternPulsar() { pulsar = {{false, false, true, true, true}}; }

std::uint8_t PatternPulsar::getSizeX() const
{
    return static_cast<std::uint8_t>(13);
}

std::uint8_t PatternPulsar::getSizeY() const
{
    return static_cast<std::uint8_t>(13);
}

bool PatternPulsar::getCell(std::uint8_t x, std::uint8_t y) const
{
    return this->pulsar[y][x];
}