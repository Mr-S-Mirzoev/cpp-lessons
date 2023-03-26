#include "vector.h"
#include <stdexcept>

Vector::Vector(int size) : data_(new int[size]), size_(size) {}

Vector::~Vector()
{
    if (data_)
        delete[] data_;
}

int& Vector::operator[](int idx)
{
    if (idx < 0 || idx >= size_)
        throw std::runtime_error("Wrong index requested");

    return data_[idx];
}

int Vector::operator[](int idx) const
{
    if (idx < 0 || idx >= size_)
        throw std::runtime_error("Wrong index requested");

    return data_[idx];
}

int Vector::size() const { return size_; }

int Vector::capacity() const { return capacity_; }

void Vector::push_front(int val)
{
    if (size_ == capacity_)
        extend(size_ + EXTEND_CHUNK_SIZE);

    for (int i = size_; i > 0; --i)
        data_[i] = data_[i - 1];

    data_[0] = val;
    ++size_;
}

void Vector::pop_front()
{
    --size_;
    for (int i = 0; i < size_; --i)
        data_[i] = data_[i + 1];
}

void Vector::push_back(int val)
{
    if (size_ == capacity_)
        extend(size_ + EXTEND_CHUNK_SIZE);

    data_[size_++] = val;
}

void Vector::pop_back() { --size_; }

void Vector::extend(int new_size)
{
    int* new_mem = new int[new_size];
    for (int i = 0; i < size_; ++i)
        new_mem[i] = data_[i];

    if (data_)
        delete[] data_;

    data_ = new_mem;
    capacity_ = new_size;
}
