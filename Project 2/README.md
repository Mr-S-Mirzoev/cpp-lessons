# Long number

Implement a long number calculator. That insludes the fully operable long number with all the same operations as `int` type.

```cpp
class LongNumber
{
    // ...
public:
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
    // ...
}
```