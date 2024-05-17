#pragma once

#ifndef __COMMAND_PARAMETER_H__
#define __COMMAND_PARAMETER_H__

#include "../Containers/ICloneable.h"
#include "../Containers/String.h"

struct CommandParameter : public ICloneable
{

protected:
    String name;

};

struct TextParameter : public CommandParameter
{

public:
    TextParameter (const String& setName, const String& setValue)
    {
        name = setName;
        value = setValue;
    }

    void set_value (const String& val);

public:
    String value;

};

struct BoolParameter : public CommandParameter
{

public:
    BoolParameter (const String& setName, const bool setValue)
    {
        name = setName;
        value = setValue;
    }

public:
    bool value;

};

struct IntegralParameter : public CommandParameter
{

public:
    IntegralParameter (const String& setName, const int setValue)
    {
        name = setName;
        value = setValue;
    }

public:
    int value;

};

#endif // __COMMAND_PARAMETER_H__