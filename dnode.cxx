#include "dnode.h"


void dlist_head_insert(dnode*& head_ptr, const dnode::value_type& entry)
{
    // If there is no other node(s)
    if (head_ptr == NULL) {
        // Create a new node with the right data and links to NULL
        dnode* newHead = new dnode();
        newHead->set_data(entry);
        
        // Update the head_ptr
        head_ptr = newHead;
    
    // If there is 1 or more nodes already
    } else {

        dnode* newHead = new dnode();
        newHead->set_data(entry);
        newHead->set_fore(head_ptr);
        
        head_ptr->set_back(newHead);
        
        head_ptr = newHead;
    }

}

void dlist_insert(dnode* previous_ptr, const dnode::value_type& entry)
{
    // Previous pointer is at the tail
    if (previous_ptr->fore() == NULL) {

        dnode* newNode = new dnode();
        newNode->set_data(entry);
        newNode->set_back(previous_ptr);
        
        previous_ptr->set_fore(newNode);
        
    } else { // Previous pointer is in the middle
        
        dnode* newNode = new dnode();
        newNode->set_data(entry);
        newNode->set_fore(previous_ptr->fore());
        newNode->set_back(previous_ptr);
        
        // Set the next node's back link to the new node
        previous_ptr->fore()->set_back(newNode);
        
        // Set previous node's fore link to the new node
        previous_ptr->set_fore(newNode);
    }
}
  
void dlist_head_remove(dnode*& head_ptr)
{

    // If there are no nodes in the list, print an error message and return.
    if (head_ptr == NULL) {
        std::cout << "Error: no nodes to delete." << std::endl;
        return;
    }
    
    // If there is only one node in the list
    if (head_ptr->fore() == NULL) {
        
        dnode* delete_ptr = head_ptr;
        delete delete_ptr;
        head_ptr = NULL;
        
    } else { // There is more than one node in the list

        dnode* delete_ptr = head_ptr;
        head_ptr = head_ptr->fore();
        head_ptr->set_back(NULL);
        delete delete_ptr;
        
    }
}

void dlist_remove(dnode* previous_ptr)
{
    dnode* delete_ptr = previous_ptr->fore();
    
    // If there is no node after the node to delete
    if (delete_ptr->fore() == NULL) {
        
        previous_ptr->set_fore(NULL);
        delete delete_ptr;
        
    } else { // There is a node after the node to delete
        // Update the next node's back link to point to the previous node
        delete_ptr->fore()->set_back(previous_ptr);
        
        // Set previous node's fore to point to next node
        previous_ptr->set_fore(delete_ptr->fore());
        
        delete delete_ptr;
    }
}

dnode* dlist_search(dnode* head_ptr, const dnode::value_type& target)
{
    // head_ptr is passed by value, so we can use that same pointer to look down the list
    
    // Loop over every value in the list, stopping at the end when the pointer points to null
    while (head_ptr != NULL) {
        // If the node the check_ptr points to has the right value, return the head_ptr
        if (head_ptr->data() == target) {
            return head_ptr;
        }
        // Otherwise, move the check_ptr forward to point at the next node
        if (head_ptr->fore() != NULL) {
            head_ptr = head_ptr->fore();
        } else { // return NULL if the current node's fore link is pointing to NULL since we failed to find the desired node
            return NULL;
        }
    }
    return NULL;
}

void print_fore(const dnode* head_ptr)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
		std::cout << cursor->data() << " ";
	std::cout << std::endl;
}

void print_back(const dnode* head_ptr)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor->fore() != NULL; cursor = cursor->fore())
		cursor = cursor->fore();
	for (;cursor != NULL; cursor = cursor->back())
		std::cout << cursor->data() << " ";
	std::cout << std::endl;
}



