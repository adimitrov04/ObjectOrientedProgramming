#pragma once

#ifndef __ICLONABLE_H__
#define __ICLONABLE_H__

class ICloneable
{

public:
    ICloneable() = default;
    virtual ~ICloneable() = default;

public:
    virtual ICloneable* clone () const = 0;

};

#endif // __ICLONABLE_H__