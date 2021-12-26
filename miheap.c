#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
  #include <stdbool.h>
#include "miheap.h"
#define ve 1000000
// A structure to represent a 
// node in adjacency list
struct MinHeap
{
      
    // Number of heap nodes present currently
    int size;     
    
    // Capacity of min heap
    int capacity;  
    
    // This is needed for decreaseKey()
    int *pos;    
    struct MinHeapNode **array;
};
  
struct Node
{
    
    int dest;
    int weight;
    struct Node* next;
};
  
// A structure to represent 
// an adjacency list
struct List
{
  int src_vi;    
   // Pointer to head node of list
   struct Node *head; 
};
  
// A structure to represent a graph. 
// A graph is an array of adjacency lists.
// Size of array will be V (number of 
// vertices in graph)
struct Graph
{
    int here;
    int vertex;
    struct List* array;
};
  
// A utility function to create 
// a new adjacency list node
struct Node* new_Node(
                   int dest, int weight)
{
    struct Node* newNode =
            (struct Node*) 
      malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
  
// A utility function that creates 
// a graph of V vertices
struct Graph* createGraph(int V)
{
    
    struct Graph* graph = (struct Graph*) 
            malloc(ve*sizeof(struct Graph));
    graph->vertex = 0;
    
    
    // Create an array of adjacency lists.  
    // Size of array will be V
    graph->array = (struct List*) 
       malloc(ve * sizeof(struct List));
  
    // Initialize each adjacency list 
    // as empty by making head as NULL
    for (int i = 0; i < ve; ++i){
        
        graph->array[i].head = NULL;
       graph->array[i].src_vi=1;
    }
    return graph;
}
  
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, 
                   int dest, int weight)
{
   if(src==dest){
    if((graph)->array[src].src_vi==1){
    (graph)->array[src].src_vi==0;
       (graph)->vertex+=1;
       return;
    }
   }
  
    if((graph)->array[src].src_vi==1){
        
        (graph)->vertex+=1;
        (graph)->array[src].src_vi=0;
       
    }
     if((graph)->array[dest].src_vi==1){
        (graph)->vertex+=1;
        (graph)->array[dest].src_vi=0;
        
    }
  
    
     //
             
    struct Node* newNode = 
            new_Node(dest, weight);
    newNode->next = (graph)->array[src].head;
    (graph)->array[src].head = newNode;
   
  //free(graph1);
}
// Structure to represent a min heap node
struct MinHeapNode
{
    int  v;
    int dist;
};
  
// Structure to represent a min heap

// A utility function to create a 
// new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, 
                                 int dist)
{
    struct MinHeapNode* minHeapNode =
           (struct MinHeapNode*) 
      malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}
  
// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) 
      malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(
            capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (struct MinHeapNode**) 
                 malloc(capacity * 
       sizeof(struct MinHeapNode*));
    return minHeap;
}
  
// A utility function to swap two 
// nodes of min heap. 
// Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, 
                     struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
  
// A standard function to 
// heapify at given idx
// This function also updates 
// position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, 
                                  int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
  
    if (left < minHeap->size &&
        minHeap->array[left]->dist < 
         minHeap->array[smallest]->dist )
      smallest = left;
  
    if (right < minHeap->size &&
        minHeap->array[right]->dist <
         minHeap->array[smallest]->dist )
      smallest = right;
  
    if (smallest != idx)
    {
        // The nodes to be swapped in min heap
        struct MinHeapNode *smallestNode = 
             minHeap->array[smallest];
        struct MinHeapNode *idxNode = 
                 minHeap->array[idx];
  
        // Swap positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
  
        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], 
                         &minHeap->array[idx]);
  
        minHeapify(minHeap, smallest);
    }
}
  
// A utility function to check if 
// the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}
  
// Standard function to extract 
// minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* 
                                   minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
  
    // Store the root node
    struct MinHeapNode* root = 
                   minHeap->array[0];
  
    // Replace root node with last node
    struct MinHeapNode* lastNode = 
         minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
  
    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
  
    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);
  
    return root;
}
  
// Function to decreasy dist value 
// of a given vertex v. This function
// uses pos[] of min heap to get the
// current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, 
                         int v, int dist)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];
  
    // Get the node and update its dist value
    minHeap->array[i]->dist = dist;
  
    // Travel up while the complete 
    // tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->dist < 
           minHeap->array[(i - 1) / 2]->dist)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = 
                                      (i-1)/2;
        minHeap->pos[minHeap->array[
                             (i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  
                 &minHeap->array[(i - 1) / 2]);
  
        // move to parent index
        i = (i - 1) / 2;
    }
}
  
// A utility function to check if a given vertex
// 'v' is in min heap or not
int isInMinHeap(struct MinHeap *minHeap, int v)
{
   if (minHeap->pos[v] < minHeap->size)
     return true;
   return false;
}
  
// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

    
    
}
  
// The main function that calculates 
// distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(struct Graph* graph, int src)
{
    
    // Get the number of vertices in graph
    int V = graph->vertex;
    //printf("%d", graph->vertex);  
    // dist values used to pick
    // minimum weight edge in cut
    int dist[V];     
  
    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);
  
    // Initialize min heap with all 
    // vertices. dist value of all vertices 
    for (int v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, 
                                      dist[v]);
        minHeap->pos[v] = v;
    
    }
  
    // Make dist value of src vertex 
    // as 0 so that it is extracted first
    minHeap->array[src] = 
          newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
  
    // Initially size of min heap is equal to V
    minHeap->size = V;
  
    // In the followin loop, 
    // min heap contains all nodes
    // whose shortest distance 
    // is not yet finalized.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with 
        // minimum distance value
        struct MinHeapNode* minHeapNode = 
                     extractMin(minHeap);
        
        // Store the extracted vertex number
        int u = minHeapNode->v; 
  
        // Traverse through all adjacent 
        // vertices of u (the extracted
        // vertex) and update 
        // their distance values
        struct Node* pCrawl =
                     graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
            printf(" %d ",dist[1]);
            // If shortest distance to v is
            // not finalized yet, and distance to v
            // through u is less than its 
            // previously calculated distance
            if (isInMinHeap(minHeap, v) && 
                      dist[u] != INT_MAX && 
              pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                
                // update distance 
                // value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
  
    printf("%d\n",graph->vertex);
    // print the calculated shortest distances
    printArr(dist, V);
}