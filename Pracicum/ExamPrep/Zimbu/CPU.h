#pragma once

#ifndef __CPU_H__
#define __CPU_H__

#include <ostream>
#include <stdexcept>
#include <limits>

#include "Component.h"

class CPU : public virtual Component
{

public:
    CPU (const unsigned short setCores, const unsigned short setSpeed)
    : Component("CPU", tCPU)
    , numberOfCores(setCores)
    , clockSpeed(setSpeed)
    {
        if (numberOfCores < 1 || numberOfCores > 8)
            throw std::invalid_argument("CPU.ctor: Invalid number of cores");
    }

    virtual ~CPU() = default;

public:
    virtual const double price () const override
    {
        return (numberOfCores * PRICE_PER_CORE);
    }

    virtual void output (std::ostream& out) const override
    {
        Component::output(out);
        out << "Cores: " << numberOfCores << '\n';
        out << "Clock speed: " << clockSpeed << " MHz" << '\n';
    }

private:
    static constexpr double PRICE_PER_CORE = 29.99;

protected:
    const unsigned short numberOfCores;
    const unsigned short clockSpeed;

};

#endif // __CPU_H__