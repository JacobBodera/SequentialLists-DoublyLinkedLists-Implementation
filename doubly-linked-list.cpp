#include "doubly-linked-list.h"
#include <iostream>
#include <new>

// parametric constructor for the class
DoublyLinkedList::Node::Node(DataType data):
        value(data), next(NULL), prev(NULL)
{
}
// default constructor for the class
DoublyLinkedList::DoublyLinkedList()
        :head_(NULL), tail_(NULL), size_(0)
{
}
// deconstructor for the class
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
// outputs whether or not the list is empty
bool DoublyLinkedList::empty() const
{
    return size_ == 0;
}
// outputs the size of the list
unsigned int DoublyLinkedList::size() const
{
    return size_;
}
// prints a visual representation for the list
void DoublyLinkedList::print() const
{
    if(!head_) {
        return;
    }

    else {
        Node* current = head_;
        while (current) {
            std::cout << "[ " << current -> value << " ]";
            if (current -> next)
                std:: cout << " -> ";
            current = current -> next;
        }
        std::cout << "\n";
    }
}
// inserts a new value at the front of the list
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
    return true;

}
// removes the value at the front of the list
bool DoublyLinkedList::remove_front()
{
    if(size_ == 0 || !head_)
        return false;

    if(!head_ -> next || size_ == 1){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    else {
        Node* newHead = head_ -> next;
        newHead -> prev = NULL;
        delete head_;
        head_ = newHead;
    }
    --size_;
    return true;
}
// inserts a value at the back of the list
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
    return true;
}
// removes the value at the back of the list
bool DoublyLinkedList::remove_back()
{
    if(size_ == 0 || !head_) {
        return false;
    }

    if(!head_ -> next || size_ == 1){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    else {
        int count = 0;
        Node *current = head_;
        while (count < (size_ - 2)) {
            current = current->next;
            ++count;
        }
        tail_ = current;
        delete (current->next);
        current->next = NULL;
    }

    --size_;
    return true;
}
// inserts a value at a given index in the list
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (CAPACITY == size_ || index > size_ || index < 0) {
        return false;
    }

    if (index == 0) {
        insert_front(value);
    }
    else if (index == size_) {
        insert_back(value);
    }

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
// removes the value at the given index
bool DoublyLinkedList::remove(unsigned int index)
{
    if(size_ == 0 || index < 0 || index >= size_)
        return false;

    if (index == 0)
        remove_front();
    else if (index == (size_ - 1))
        remove_back();
    else {
        int count = 0;
        Node* current = head_;
        while (count < index - 1) {
            current = current -> next;
            ++count;
        }

        Node* temp = current -> next -> next;
        temp -> prev = current;
        delete (current -> next);
        current -> next = temp;
        --size_;
    }
    return true;
}
// searches the list for a value and returns the index at which it first appears
// if the value is not found, the size of the list is output
unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* found = head_;
    unsigned int index = 0;
    while (found -> value != value && found -> next != NULL) {
        found = found -> next;
        ++index;
    }

    if (found -> value != value)
        return size_;
    else
        return index;
}
// return the value at a given index
// if the index is invalid, it return the last element in the list
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    int count = 0;
    Node* found = head_;

    if (index >= size_ || index < 0) {
        while (count < size_ - 1) {
            found = found -> next;
            ++count;
        }
    }
    else {
        while (count < index) {
            found = found->next;
            ++count;
        }
    }
    return found -> value;
}
// replaces the value at a given index with a new value
bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if (index > size_ || index < 0)
    return false;

    int count = 0;
    Node* temp = head_;
    while (count < index){
        temp = temp -> next;
        ++count;
    }
    temp -> value = value;
    return true;
}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
}
// outputs whether the list is full
bool DoublyLinkedList::full() const
{
    return size_ == CAPACITY;
}
