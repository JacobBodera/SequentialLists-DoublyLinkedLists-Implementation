#include "doubly-linked-list.h"
#include <iostream>
#include <new>

DoublyLinkedList::Node::Node(DataType data):
        value(data), next(NULL), prev(NULL)
{
}
DoublyLinkedList::DoublyLinkedList()
        :head_(NULL), tail_(NULL), size_(0)
{
}
/*DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
:size_(list.size_)
{
	


}*/
DoublyLinkedList::~DoublyLinkedList()
{
    Node* current = head_;
    while (current){
        current = current -> next;
        delete head_;
        head_ = current;
    }
    head_ = tail_ = NULL;
    size_ = 0;
}
bool DoublyLinkedList::empty() const
{
    if(size_ == 0)
        return true;
    return false;

}
unsigned int DoublyLinkedList::size() const
{
    return size_;

}
void DoublyLinkedList::print() const
{
    if(!head_)
        return;

    else {
        Node* current = head_;
        while (current) {
            std::cout << "[ " << current -> value << " ]";
            if (current -> next)
                std:: cout << " -> ";
            current = current -> next;
        }
    }

}
bool DoublyLinkedList::insert_front(DataType value)
{
    if (CAPACITY == size_)
        return false;

    Node* ins = new Node(value);
   if (size_ == 0) {
       head_ = ins;
       tail_ = ins;
   }
   else {
       head_ -> prev = ins;
       ins -> next = head_;
       head_ = ins;
   }
    ++ size_;

}
bool DoublyLinkedList::remove_front()
{
 


}
bool DoublyLinkedList::insert_back(DataType value)
{
    if (CAPACITY == size_)
        return false;

   Node* ins = new Node(value);
    if (size_ == 0) {
        head_ = ins;
        tail_ = ins;
    }
    else {
        ins -> prev = tail_;
        tail_ -> next = ins;
        tail_ = ins;
    }
    ++ size_;

    return true
}
bool DoublyLinkedList::remove_back()
{
    



}
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (CAPACITY == size_ || index > size_ || index < 0)
        return false;

    if (index == 0)
        insert_front(value);
    else if (index == size_)
        insert_back(value);
    else {
        int count = 0;
        Node* ins = new Node(value);
        Node* current = head_;

        while (count < index - 1){
            current = current -> next;
            ++count;
        }
        ins -> prev = current;
        ins -> next = current -> next;
        current -> next = ins;
        ins -> next -> prev = ins;

        ++size_;
    }
    return true;
}
bool DoublyLinkedList::remove(unsigned int index)
{
    


}
unsigned int DoublyLinkedList::search(DataType value) const
{
    


}
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
  


}
bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    

}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
   

}
bool DoublyLinkedList::full() const
{
    if(size_ == CAPACITY)
        return true;
    return false;

}
