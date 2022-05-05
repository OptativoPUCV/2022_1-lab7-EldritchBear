#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0)return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){  
  Heap *pq = (Heap*) calloc (3,sizeof(Heap));
  pq->heapArray = (heapElem*) malloc (sizeof(heapElem));
  pq->capac = 3;
  pq->size = 0;
  return heapArray;
}
