#include "sequential-list.h"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];

}

SequentialList::~SequentialList()
{
    delete [] data_;
    data_ = NULL;
}

unsigned int SequentialList::size() const
{
    unsigned int i = 0;
    while (*(data_ + i) != NULL){
        i++;
    }
    return i;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    for(int i = 0; i < capacity_; i++){
        if(*(data_ + i) != NULL)
            return false;
    }
    return true;
}

bool SequentialList::full() const
{
    for(int i = 0; i < capacity_; i++){
        if(*(data_ + i) = NULL)
            return false;
    }
    return true;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
   if(index >= 0 && index < capacity_)
       return *(data_ + index);
   return *(data_ + capacity_ - 1);

}

unsigned int SequentialList::search(DataType val) const
{
    for(unsigned int i = 0; i < capacity_; i++){
        if(*(data_ + i) == val)
            return i;
    }
    return SequentialList::size();

}

void SequentialList::print() const
{
    
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if(size() == capacity_)
        return false;

    int temp = 0;
    int assign = val;
    if(*(data_ + index - 1) != NULL || index == 0){
        for(int i = 0; i <= size() + 1; i++){
            temp = *(data_ + index + i);
            *(data_ + index + i) = assign;
            assign = temp;
        }
        return true;
    }
    return false;
}

bool SequentialList::insert_front(DataType val)
{
    if(size() == capacity_)
        return false;

    int temp = 0;
    int assign = val;
    for(int i = 0; i < capacity_; i++){
        temp = *(data_ + i);
        *(data_ + i) = assign;
        assign = temp;
    }
    return true;
}

bool SequentialList::insert_back(DataType val)
{
    if(size() == capacity_)
        return false;

    *(data_ + size() + 1) = val;
    return true;
}

bool SequentialList::remove(unsigned int index)
{


}

bool SequentialList::remove_front()
{
    if(size() == 0)
        return false;

    *data_ = NULL;
    data_ += 1;
    return true;
}

bool SequentialList::remove_back()
{
   if(size() == 0)
       return false;

   *(data_ + size() + 1) = NULL;
   return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(*(data_ + index -1) != NULL || index == 0){
        *(data_ + index) = val;
        return true;
    }
    return false;
}

