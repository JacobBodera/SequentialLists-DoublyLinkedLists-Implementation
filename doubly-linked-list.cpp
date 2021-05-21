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
    


}
bool DoublyLinkedList::empty() const
{
    

}
unsigned int DoublyLinkedList::size() const
{
    

}
void DoublyLinkedList::print() const
{
    

}
bool DoublyLinkedList::insert_front(DataType value)
{
   


}
bool DoublyLinkedList::remove_front()
{
 


}
bool DoublyLinkedList::insert_back(DataType value)
{
   




}
bool DoublyLinkedList::remove_back()
{
    



}
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
   


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
    

}
