# Long number

Implement a long number calculator. That insludes the fully operable long number with all the same operations as `int` type.

```cpp
class LongNumber
{
    // ...
public:
    operator int() const;
    operator++(int);
    operator--(int);
    operator+();
    operator>>(istream);
    operator<<(ostream);
    // ...
}
```