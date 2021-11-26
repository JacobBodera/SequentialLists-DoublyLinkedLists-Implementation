#include "sequential-list.h"
#include <iostream>

// default constructor for SequentialList class
SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];
    size_ = 0;
    capacity_ = cap;
}
// deconstructor for SequentialList class
SequentialList::~SequentialList()
{
    delete [] data_;
}
// outputs the size of the list
unsigned int SequentialList::size() const
{
    return size_;
}
// outputs the capacity of the list
unsigned int SequentialList::capacity() const
{
    return capacity_;
}
// outputs whether or not the list is empty
bool SequentialList::empty() const
{
    return size_ == 0;
}
// outputs whether or not the list is full
bool SequentialList::full() const
{
    return size_ == capacity_;
}
// given an index, the function outputs the value of that index
// if the index is invalid, it outputs the last value in the list
SequentialList::DataType SequentialList::select(unsigned int index) const
{
   if (index < 0 || index >= size_)
       return data_[size_ - 1];
   return data_[index];
}
// given a value, the function outputs the index at which that value appears first
// if the value is not found, then the size of the list is output
unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i < size_; i++) {
        if (data_[i] == val)
            return i;
    }
    return size_;
}
// prints a visual representation of the list
void SequentialList::print() const
{
    for(int i = 0; i < size_; i++) {
        std::cout << data_[i] << "\t";
    }
}
// inserts a value at a certain index and shifts all subsequent values up the list
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
// inserts a value at the front of the list
bool SequentialList::insert_front(DataType val)
{
    insert(val, 0);
}
// inserts a value at the back of the list
bool SequentialList::insert_back(DataType val)
{
    insert(val, size_);
}
// given an index, removes the value at that index and shifts all subsequent values down the list
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
// removes the first item in the list
bool SequentialList::remove_front()
{
    remove(0);
}
// removes the last item in the list
bool SequentialList::remove_back()
{
   remove(size_ - 1);
}
// replaces the value at an index with a new value
bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index >= size_ || index < 0) {
        return false;
    }

    data_[index] = val;
    return true;
 }

