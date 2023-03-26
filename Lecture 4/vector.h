#pragma once

class Vector
{
    int* data_ = nullptr;
    int size_ = 0;
    int capacity_ = 0;

    static const int EXTEND_CHUNK_SIZE = 8;

public:
    Vector() = default;
    Vector(int size);

    ~Vector();

    int& operator[](int idx);
    int operator[](int idx) const;
    int size() const;
    int capacity() const;

    void push_front(int val);
    void pop_front();

    void push_back(int val);
    void pop_back();

private:
    void extend(int new_size);
};
