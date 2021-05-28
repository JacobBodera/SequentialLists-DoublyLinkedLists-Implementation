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
{}
	*/



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
    if(size_ == 0) {
        return true;
    }
    return false;
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

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
bool DoublyLinkedList::remove_front()
{
    if(size_ == 0 || !head_)
        return false;

    if(!head_ -> next){
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

bool DoublyLinkedList::remove_back()
{
    if(size_ == 0 || !head_)
        return false;

    if(!head_ -> next){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    else {
        int count = 0;
        Node *current = head_;
        while (count < size_ - 1) {
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
    if(size_ == 0 || index < 0 || index >= size_)
        return false;

    if (index == 0)
        remove_front();
    else if (index == size_)
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
    }
    --size_;
    return true;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* found = head_;
    unsigned int index = 0;
    while (found -> value != value && found -> next != NULL && index <= size_) {
        found = found -> next;
        ++index;
    }

    if (found -> value != value)
        return size_;
    else
        return index;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    int count = 0;
    Node* found = head_;

    if (index > size_ || index < 0) {
        while (count < size_ - 1) {
            found = found -> next;
            ++count;
        }
        return found -> value;
    }
    else {
        while (count < index) {
            found = found->next;
            ++count;
        }
        std::cout << found -> value << "   ";
        return found -> value;
    }
}

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

bool DoublyLinkedList::full() const
{
    if(size_ == CAPACITY)
        return true;
    return false;

}
