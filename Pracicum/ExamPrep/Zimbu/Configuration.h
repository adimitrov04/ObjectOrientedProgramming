#pragma once

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <cstddef>
#include <stdexcept>

#include <string>
#include <vector>

#include "Component.h"
#include "CPU.h"
#include "Memory.h"

const Component* create_component (std::istream& in = std::cin)
{
    std::string label;
    in >> label;

    try
    {
        if (label == "CPU" || label == "cpu")
        {
            unsigned short setCores(0), setClockSpeed(0);
            in >> setCores >> setClockSpeed;
            if (!in)
                throw std::invalid_argument("ERROR: Incorrect input.");

            return new CPU(setCores, setClockSpeed);
        }
        else if (label == "Memory" || label == "memory")
        {
            unsigned short setCap(0);
            in >> setCap;
            if (!in)
                throw std::invalid_argument("ERROR: Incorrect input.");

            return new Memory(setCap);
        }
        else
        {
            throw std::invalid_argument("create_component: Component name not recognized.");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return nullptr;
    }
}

class Configuration
{

public:
    static Configuration* create_configuration ()
    {
        static Configuration* instance = new Configuration;

        while (instance->components.size() < Component::NUMBER_OF_COMPONENT_TYPES)
        {
            std::cout << "Enter component: ";
            try
            {
                instance->insert(create_component());
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << '\n';

                delete instance;
                return nullptr;
            }

            if ( instance->components.back() == nullptr)
            {
                delete instance;
                return nullptr;
            }
        }

        return instance;
    }

    ~Configuration ()
    {
        for (size_t i = 0; i < components.size(); i++)
            delete components[i];
    }

public:
    const Component* operator[] (const size_t index) const
    {
        if (index >= components.size())
            throw std::domain_error("Configuration.[]: Given index outside of array.");

        return components[index];
    }

    friend std::ostream& operator<< (std::ostream& out, const Configuration* config)
    {
        for (size_t i = 0; i < config->components.size(); i++)
        {
            (*config)[i]->output(out);
            out << '\n';
        }

        out << "TOTAL PRICE: " << config->price() << '\n';

        return out;
    }

    const double price () const
    {
        double total = 0.0;

        for (size_t i = 0; i < components.size(); i++)
            total += components[i]->price();

        return total;
    }

private:
    void insert (const Component* comp)
    {
        for (size_t i = 0; i < components.size(); i++)
        {
            if (components[i]->getType() == comp->getType())
                throw std::invalid_argument("Configuration.insert: Component type already in configuration");
        }

        components.push_back(comp);
    }

    Configuration() = default;
    Configuration(const Configuration& other) = delete;
    Configuration& operator= (const Configuration& other) = delete;

private:
    std::vector<const Component*> components;

};

#endif // __CONFIGURATION_H__