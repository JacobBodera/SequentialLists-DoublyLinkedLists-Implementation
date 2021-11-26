#include "sequential-list.h"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];
    size_ = 0;
    capacity_ = cap;
}

SequentialList::~SequentialList()
{
    delete [] data_;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    return size_ == 0;
}

bool SequentialList::full() const
{
    return size_ == capacity_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
   if (index < 0 || index >= size_)
       return data_[size_ - 1];
   return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i < size_; i++) {
        if (data_[i] == val)
            return i;
    }
    return size_;
}

void SequentialList::print() const
{
    for(int i = 0; i < size_; i++) {
        std::cout << *(data_ + i) << "\t";
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if(size_ == capacity_ || index > size_ || index < 0) {
        return false;
    }

    for (int i = size_; i > index; i--){
        data_[i] = data_[i-1];
    }
    data_[index] = val;
    size_++;
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
    insert(val, size_);
}

bool SequentialList::remove(unsigned int index)
{
    if(size_ == 0 || index < 0 || index >= size_) {
        return false;
    }

    for(int i = index; i < size_ - 1; i++){
        data_[i] = data_[i + 1];
    }
    size_--;
    return true;
}

bool SequentialList::remove_front()
{
    remove(0);
}

bool SequentialList::remove_back()
{
   remove(size_ - 1);
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index >= size_ || index < 0) {
        return false;
    }

    data_[index] = val;
    return true;
 }

