#pragma once

class istream;
class ostream;

class LongNumber
{
private:
    int* data_ = nullptr;
    int size = 0;

public:
    LongNumber() = default;
    LongNumber(LongNumber const& other);

    LongNumber(int number);

    operator int() const;

    LongNumber& operator++();
    LongNumber operator++(int);

    LongNumber& operator--();
    LongNumber operator--(int);

    LongNumber& operator+=(LongNumber const& rhs);
    LongNumber& operator-=(LongNumber const& rhs);
    LongNumber& operator*=(LongNumber const& rhs);
    LongNumber& operator/=(LongNumber const& rhs);

    int operator<=>(LongNumber& rhs);

    friend istream& operator>>(istream&, LongNumber const&);
    friend ostream& operator<<(ostream&, LongNumber const&);

    ~LongNumber();
};
