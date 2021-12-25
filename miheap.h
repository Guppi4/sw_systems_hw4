#ifndef POINT_H
#define POINT_H

struct Graph;

struct MinHeap;
struct MinHeapNode;
void minHeapify(struct MinHeap* minHeap, int idx);
void dijkstra(struct Graph* graph, int src);
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