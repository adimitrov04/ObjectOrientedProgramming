#ifndef __BEER_CLASS__
#define __BEER_CLASS__

#include <iostream>

const int BRAND_NAME_LIMIT = 128;
const char DEFAULT_VOL_UNIT[] = "ml";

class Beer
{
public:
    Beer();
    Beer(const char* brand, const int volume);

    void Read (std::istream& inputSrc = std::cin);

    int GetVolume () const;
    const char* GetName () const;
    bool IsGood () const;
    
    void SetName (const char* buffer);
    void SetVolume (const int volume);
    void RemoveVolume (const int inVolume);
    void AddFrom (Beer& source, const int inVolume);

    void Print (const char* volumeUnit = DEFAULT_VOL_UNIT) const;

private:
    char fBrand[BRAND_NAME_LIMIT];
    int fVolume;

    void ReadName (std::istream& inputSrc = std::cin);
    void ReadVolume (std::istream& inputSrc = std::cin);

    void nullifyString (char* const str, const size_t buff_len);
    bool nameIsValid (const char* name) const;
};

#endif // __BEER_CLASS__