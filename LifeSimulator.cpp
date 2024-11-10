#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    gridSizeX = sizeX;
    gridSizeY = sizeY;
    grid.resize(sizeX, std::vector<bool>(sizeY, false));
}

std::uint8_t LifeSimulator::getSizeX() const { return gridSizeX; }

std::uint8_t LifeSimulator::getSizeY() const { return gridSizeY; }

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x >= this->getSizeX() || y >= this->getSizeY())
    {
        return false;
    }

    return this->grid[x][y];
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX,
                                  std::uint8_t startY)
{
    for (std::uint8_t i = 0; i < pattern.getSizeX(); i++)
    {
        for (std::uint8_t j = 0; j < pattern.getSizeY(); j++)
        {
            if (this->getSizeX() > startX + i && this->getSizeY() > startY + j)
            {
                grid[startX + i][startY + j] = pattern.getCell(i, j);
            }
        }
    }
}

std::uint8_t LifeSimulator::checkNeighbors(std::uint8_t x, std::uint8_t y)
{
    std::uint8_t count = 0;

    if (this->getCell(x + 1, y + 1))
    {
        count++;
    }
    if (this->getCell(x + 1, y - 1))
    {
        count++;
    }
    if (this->getCell(x - 1, y + 1))
    {
        count++;
    }
    if (this->getCell(x - 1, y - 1))
    {
        count++;
    }
    if (this->getCell(x + 1, y))
    {
        count++;
    }
    if (this->getCell(x - 1, y))
    {
        count++;
    }
    if (this->getCell(x, y + 1))
    {
        count++;
    }
    if (this->getCell(x, y - 1))
    {
        count++;
    }

    return count;
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> updated(
        this->getSizeX(), std::vector<bool>(this->getSizeY(), false));

    for (std::uint8_t i = 0; i < grid.size(); i++)
    {
        for (std::uint8_t j = 0; j < grid[i].size(); j++)
        {
            std::uint8_t count = this->checkNeighbors(i, j);

            if (this->getCell(i, j))
            {
                updated[i][j] = count >= 2 && count <= 3;
            }
            else if (!this->getCell(i, j) && count == 3)
            {
                updated[i][j] = true;
            }
        }
    }
    grid = updated;
}