#include "long_number.h"

#include <istream>
#include <ostream>

LongNumber::LongNumber(LongNumber const& other) {}

LongNumber::LongNumber(int number) {}

LongNumber::operator int() const {}

LongNumber& LongNumber::operator++()
{
    // TODO: insert return statement here
}

LongNumber LongNumber::operator++(int) { return LongNumber(); }

LongNumber& LongNumber::operator--()
{
    // TODO: insert return statement here
}

LongNumber LongNumber::operator--(int) { return LongNumber(); }

LongNumber& LongNumber::operator+=(LongNumber const& rhs)
{
    // TODO: insert return statement here
}

LongNumber& LongNumber::operator-=(LongNumber const& rhs)
{
    // TODO: insert return statement here
}

LongNumber& LongNumber::operator*=(LongNumber const& rhs)
{
    // TODO: insert return statement here
}

LongNumber& LongNumber::operator/=(LongNumber const& rhs)
{
    // TODO: insert return statement here
}

int LongNumber::operator<=>(LongNumber& rhs) { return 0; }

LongNumber::~LongNumber() {}

istream& operator>>(istream&, LongNumber const&)
{
    // TODO: insert return statement here
}

ostream& operator<<(ostream&, LongNumber const&)
{
    // TODO: insert return statement here
}
