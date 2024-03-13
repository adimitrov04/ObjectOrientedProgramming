#include <iostream>
#include <cstring>
#include "Beer.h"

Beer::Beer()
{
    nullifyString(this->fBrand, BRAND_NAME_LIMIT);
    this->fVolume = 0;
}

Beer::Beer (const char* brand, const int volume = 0)
{
    
    this->SetName(brand);
    if (strlen(this->fBrand) == 0)
    {
        std::clog << "Initialization of object failed." << std::endl;
        return ;
    }

    this->SetVolume(volume);
}

void Beer::nullifyString (char* const str, const size_t buff_len)
{
    for (int i = 0; i < buff_len; i++)
    {
        str[i] = '\0';
    }
}

int Beer::GetVolume () const
{
    return this->fVolume;
}

const char* Beer::GetName () const
{
    if (strnlen(this->fBrand, BRAND_NAME_LIMIT) == 0)
        return nullptr;

    return this->fBrand;
}

bool Beer::IsGood () const
{
    if (strlen(this->fBrand) == 0 || strnlen(this->fBrand, BRAND_NAME_LIMIT) == BRAND_NAME_LIMIT)
        return false;

    return true;
}

void Beer::SetName (const char* buffer)
{
    if (strnlen(buffer, BRAND_NAME_LIMIT) == BRAND_NAME_LIMIT)
    {
        std::cout << "FAIL: Brand name longer than set limit." << std::endl;
        return ;
    }

    nullifyString(this->fBrand, BRAND_NAME_LIMIT);
    strcpy(this->fBrand, buffer);
}

void Beer::SetVolume (const int volume)
{
    if (this->fVolume == 0)
    {
        this->fVolume = volume;
    }
    else
    {
        std::clog << "Cannot use SetVolume() on non-empty object." << std::endl;
    }

    return ;
}

void Beer::RemoveVolume (const int inVolume)
{
    if (this->fVolume >= inVolume)
    {
        this->fVolume -= inVolume;
    }
}

void Beer::AddFrom (Beer& source, const int inVolume)
{
    if (this->IsGood() == false)
    {
        std::cout << "ERROR: Cannot add volume because current object is not initialized." << std::endl;
        return ;
    }
    
    if (source.GetVolume() >= inVolume)
    {
        if (this->IsGood() == false)
        {
            std::clog << "FAIL: Specified soruce is not in good state." << std::endl;
            return ;
        }
        this->fVolume += inVolume;
        source.RemoveVolume(inVolume);
    }
    else
    {
        std::clog << "FAIL: Specified source does not have the specified volume for transfer." << std::endl;
        return ;
    }
}

void Beer::Print (const char* volumeUnit) const
{
    if (*(this->fBrand) == '\0')
    {
        std::cout << "empty" << std::endl;
        return ;
    }

    std::cout << this->fBrand << ": " << this->fVolume << volumeUnit << std::endl;
}

void Beer::Read (std::istream& inputSrc)
{
    this->ReadName(inputSrc);
    if (*(this->fBrand) == '\0')
    {
        std::cout << "Reading failed at ReadName()" << std::endl;
        return ;
    }

    this->ReadVolume(inputSrc);
    if (this->fVolume == 0)
    {
        std::cout << "Reading failed at ReadVolume()" << std::endl;
        nullifyString(this->fBrand, BRAND_NAME_LIMIT);

        return ;
    }
}

void Beer::ReadName (std::istream& inputSrc)
{
    std::cout << "Enter beer name: ";

    char buff[BRAND_NAME_LIMIT] = { '\0', };
    inputSrc.getline(buff, BRAND_NAME_LIMIT);
    if (inputSrc.good() == false)
    {
        inputSrc.clear();
        inputSrc.ignore(BRAND_NAME_LIMIT, '\n');

        std::cout << "Name inputted incorrectly." << std::endl;
        return ;
    }

    this->SetName(buff);

    inputSrc.clear();
    std::clog << "SetName() completed successfully." << std::endl;
}

void Beer::ReadVolume (std::istream& inputSrc)
{
    std::cout << "Enter the volume of beer contained in " << this->fBrand << std::endl;
    
    int buffer = 0;
    inputSrc >> buffer;
    if (inputSrc.good() == false)
    {
        std::clog << buffer << std::endl;
        std::cout << "FAIL: Incorrect volume format." << std::endl;
        inputSrc.ignore();
        nullifyString(this->fBrand, BRAND_NAME_LIMIT);
        return ;
    }

    this->SetVolume(buffer);
    inputSrc.ignore();

    std::clog << "SetVolume() completed successfully." << std::endl;
}