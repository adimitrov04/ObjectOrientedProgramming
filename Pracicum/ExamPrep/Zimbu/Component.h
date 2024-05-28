#pragma once

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <iostream>
#include <string>

enum ComponentType
{
    tCPU,
    tMemory,
    tGPU
};

class Component
{

public:
    Component (const std::string& setLabel, const ComponentType setType): label(setLabel), type(setType) {}
    virtual ~Component () = default;

public:
    virtual const double price () const = 0;
    virtual void output (std::ostream& out = std::cout) const
    {
        out << "Component: " << label << '\n';
        out << "Price: " << price() << '\n';
    }

    const ComponentType getType () const
    {
        return type;
    }

public:
    static const int NUMBER_OF_COMPONENT_TYPES = 3;

private:
    const std::string label;
    const ComponentType type;

};

#endif // __COMPONENT_H__