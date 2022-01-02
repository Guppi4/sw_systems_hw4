#ifndef POINT_H
#define POINT_H
#include "miheap.h"
struct Graph;

struct MinHeap;
struct MinHeapNode;
struct Node;
void removenode(struct Graph* graph,int key);
void deleteNode(struct Node** head_ref, int key);

void deleteListgraph(struct Node** head_ref);
void ifwehavenode(struct Graph* graph,int key);
void freegraph(struct Graph* graph);
void minHeapify(struct MinHeap* minHeap, int idx);
int dijkstra(struct Graph* graph, int src,int dest);
int isInMinHeap(struct MinHeap *minHeap, int v);
void decreaseKey(struct MinHeap* minHeap, int v, int dist) ;
struct MinHeapNode* extractMin(struct MinHeap* minHeap) ;
int isEmpty(struct MinHeap* minHeap);                                  
  
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
struct MinHeap* createMinHeap(int capacity);
struct MinHeapNode* newMinHeapNode(int v,int dist);

void addEdge(struct Graph* graph, int src,int dest, int weight);
struct Graph* createGraph();
struct Node* new_Node(int dest, int weight);

                   
                   
                                 
                                                                          


#endif /* POINT_H */