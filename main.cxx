/*
  The correct output is:

  7 8 3 2 11 9 5 
  7 8 3 11 9 5 
  8 3 11 9 5 
  5 9 11 3 8 
  3 11 9 5 
  3 11 9 
  3 11 9 13 
  3 9 13 
  13 9 3 
  3 13 
  13
 */

#include <iostream>
#include "dnode.h"

using namespace std;

int main()
{
	dnode* head_ptr = NULL;
	double data[7] = {5,9,11,2,3,8,7};

	for (int i=0; i<7; ++i)
	 	dlist_head_insert(head_ptr, data[i]);
	print_fore(head_ptr);

	dnode* cursor = dlist_search(head_ptr, 2);
	dlist_remove(cursor->back());
	print_fore(head_ptr);

	dlist_head_remove(head_ptr);
	print_fore(head_ptr);
	print_back(head_ptr);

	dlist_head_remove(head_ptr);
	print_fore(head_ptr);

	dnode* cursor2 = dlist_search(head_ptr, 5);
	dlist_remove(cursor2->back());
	print_fore(head_ptr);

	dnode* cursor3 = dlist_search(head_ptr, 9);
	dlist_insert(cursor3,13);
	print_fore(head_ptr);

	dlist_remove(head_ptr);
	print_fore(head_ptr);
	print_back(head_ptr);

	dlist_remove(head_ptr);
	print_fore(head_ptr);

	dlist_head_remove(head_ptr);
	print_fore(head_ptr);

	return 0;
}

