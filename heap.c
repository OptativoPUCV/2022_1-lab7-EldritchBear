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
  int i;
  
  if (pq->size == pq->capac){
    pq->capac = (2*pq->capac)+1;
    pq->heapArray = realloc(pq->heapArray,pq->capac);
  }

  for(i = 0; i < pq->capac ; i++){
    if(pq->heapArray[i].priority == 0)
    {
      pq->heapArray[i].data = data;
      pq->heapArray[i].priority = priority;
      break;
    }
  }

  while(pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority){
    heapElem aux = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = aux;
    i = (i-1)/2;
  }
  pq->size += 1;
}


void heap_pop(Heap* pq){
  int i = 0;
  heapElem aux;
  pq->heapArray[0] = pq->heapArray[pq->size];
  pq->heapArray[pq->size].data = NULL;
  pq->heapArray[pq->size].priority = 0;
  pq->size += -1;

  while(1){
    if(pq->heapArray[i].priority > pq->heapArray[(2*i)+1].priority && pq->heapArray[i].priority > pq->heapArray[(2*i)+2].priority)break;

    if(pq->heapArray[i].priority < pq->heapArray[(2*i)+1].priority){
      aux = pq->heapArray[(2*i)+1];
      pq->heapArray[(2*i)+1] = pq->heapArray[i];
      pq->heapArray[i] = aux;
    }

    if(pq->heapArray[i].priority < pq->heapArray[(2*i)+2].priority){
      aux = pq->heapArray[(2*i)+2];
      pq->heapArray[(2*i)+2] = pq->heapArray[i];
      pq->heapArray[i] = aux;
    }
    
    i++;
    if(i == pq->capac)break;
    if(i == pq->size)break;
  }
}

Heap* createHeap(){  
  Heap *pq = (Heap*) malloc (sizeof(Heap));
  pq->heapArray = (heapElem*) calloc (3,sizeof(heapElem));
  pq->capac = 3;
  pq->size = 0;
  return pq;
}
