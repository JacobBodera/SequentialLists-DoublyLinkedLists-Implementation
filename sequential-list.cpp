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
    if(size_ == 0)
        return true;
    return false;
}

bool SequentialList::full() const
{
    if(size_ == capacity_)
        return true;
    return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
   if(index >= 0 && index < capacity_) {
       return *(data_ + index);
   }
   if(size_ != 0) {
       return *(data_ + size_ - 1);
   }
   else
       return *data_;
}

unsigned int SequentialList::search(DataType val) const
{
    for(unsigned int i = 0; i < size_; i++){
        if(*(data_ + i) == val) {
            return i;
        }
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

    for(int i = size_; i > index; i--){
        *(data_ + i) = *(data_ + i - 1);
    }
    *(data_ + index) = val;
    size_++;
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    if(size_ == capacity_) {
        return false;
    }

    *data_ = val;
    size_++;
    return true;


}

bool SequentialList::insert_back(DataType val)
{
    if(size_ == capacity_) {
        return false;
    }
    data_[size_] = val;
    *(data_ + size_) = val;
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
    if(size_ == 0) {
        return false;
    }

    for(int i = index; i < size_ - 1; i++){
        *(data_ + i) = *(data_ + i + 1);
    }
    size_--;
    return true;
}

bool SequentialList::remove_front()
{
    if(size_ == 0) {
        return false;
    }


    size_--;
    return true;
}

bool SequentialList::remove_back()
{
   if(size_ == 0) {
       return false;
   }

   size_--;
   return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index >= size_ || index < 0) {
        return false;
    }

    *(data_ + index) = val;
    return true;
 }

