#include "freeList.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

long int* RAM; // basically simulating RAM at the start of this
	       // program as a dynamically allocated array of unsigned
	       // chars, which are byte sized long its because the OS
	       // this program is running on is 64bit system. 64 bits
	       // means each spot takes up 8 bytes.

int main() {
  RAM = new long int[8192];

  freeList me(RAM,8192);
  me.print();

  printf("Reserve 100\n");
  long int* addr1 = me.reserve_space(100);
  me.print();

  printf("Reserve 200\n");
  long int* addr2 = me.reserve_space(200);
  me.print();

  printf("Free Address 1\n");
  me.free_space( addr2 );
  me.free_space( addr1 );
  me.print();

  printf("Coalesce\n");
  me.coalesce_forward();
  me.print();

  // printf("Free Address 2\n");
  
  // me.print();

  // printf("Coalesce\n");
  // me.coalesce_forward();
  // me.print();
  
  
  delete RAM;
  return 0;
}
