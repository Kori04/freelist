#include "freeList.h"


freeList::freeList( long int*inRAM, int size ) {
  head = inRAM;
  head[0] = size - 2;
  head[1] = NULL;
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;
  long int* current = head;

  while (current != NULL)
    if (size <= current[0]){
      head = current + size + 2;
      head[1] = current[1];
      head[0] = current[0] - size - 2;
      current[0] = size;
      loc = current;
      break;
    }
    else{
      current = (long int *)current[1];
      loc = NULL;
    }
  return loc;
}

void
freeList::free_space( long int* location ) {
  location[1] = (long int)head;
  head = location;
}

void
freeList::coalesce_forward() {
  long int* current = head;
  long int* next = (long int*)head[1];
  // Check if next free space begins where current one ends
  while(next != NULL){
    if (current + current[0] + 2 == next){
      current[0] = current[0] + next[0] + 2;
      current[1] = next[1];
    }
    else{
      if (next[1] == 0){
        break;
      }
      else{
        current = (long int*)next[1];
      }
    }
    next = (long int *)current[1]; 
  }
    //If so, make size size of both & next equal to next for the last one
    //Keep checking until NULL is hit indicating end of the list
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}