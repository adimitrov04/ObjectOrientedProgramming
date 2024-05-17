#pragma once

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <istream>

#include "../Containers/ICloneable.h"

#include "../Containers/String.h"
#include "../Containers/PolymorphicVector.h"

#include "CommandParameter.h"

class Command : public ICloneable
{

public:
    Command () = default;
    virtual ~Command () = default;

public:
    virtual void Execute () const = 0;
    virtual Command* clone () const override = 0;

protected:
    PolymorphicVector/*<CommandParameter>*/ params;

};

class CommandGenerator : public ICloneable
{

public:
    CommandGenerator (String commandIdentifier);
    virtual ~CommandGenerator () = default;

public:
    const String GetIdentifier () const
    {
        return identifier;
    }

    virtual Command* generateCommand (const String& inputString) const = 0;

protected:
    String identifier;

};

#endif // __COMMAND_H__