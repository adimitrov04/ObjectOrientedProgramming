#pragma once

#ifndef __GPU_H__
#define __GPU_H__

#include <stdexcept>

#include "Component.h"
#include "CPU.h"
#include "Memory.h"

class GPU : public CPU, public Memory
{

public:
    GPU (const unsigned short setCores, const unsigned short setSpeed, const unsigned short setVRAM)
    : Component("GPU", tGPU)
    , CPU(setCores, setSpeed)
    , Memory(setVRAM)
    {
        if (clockSpeed < 1 || clockSpeed > 4)
            throw std::invalid_argument("GPU.ctor: Invalid clock speed.");
    }

    virtual ~GPU() = default;

public:
    virtual const double price () const override
    {
        return ( CPU::price() + Memory::price() + (clockSpeed * PRICE_PER_GHZ) );
    }

    virtual void output (std::ostream& out) const override
    {
        Component::output(out);
        out << "Cores: " << numberOfCores << '\n';
        out << "Clock speed: " << clockSpeed << " GHz" << '\n';
        out << "VRAM: " << capacity << " GB" << '\n';
    }

private:
    static constexpr double PRICE_PER_GHZ = 259.99;

};

#endif // __GPU_H__