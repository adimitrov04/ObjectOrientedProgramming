#pragma once

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <iostream>
#include <stdexcept>

#include "Component.h"

class Memory : public virtual Component
{

public:
    Memory (const unsigned short setCap)
    : Component("Memory", tMemory)
    , capacity(setCap)
    {
        if (capacity < 1 || capacity > 10000)
            throw std::invalid_argument("Memory.ctor: Invalid capacity.");
    }

    virtual ~Memory () = default;

public:
    virtual const double price () const override
    {
        return (capacity * PRICE_PER_GIGABYTE);
    }

    virtual void output (std::ostream& out = std::cout) const override
    {
        Component::output(out);
        out << "Capacity: " << capacity << " GB" << '\n'; 
    }

private:
    static constexpr double PRICE_PER_GIGABYTE = 89.99;

protected:
    const unsigned short capacity;

};

#endif // __MEMORY_H__