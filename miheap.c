#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
  #include <stdbool.h>
#include "miheap.h"
#define ve 100

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

struct Graph
{
    int here;
    int vertex;
    struct List* array;
};
 

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
            malloc(sizeof(struct Graph));
    graph->vertex = 0;
    
    
    // Create an array of adjacency lists.  
    
    graph->array = (struct List*) 
       malloc(ve * sizeof(struct List));
  
    // Initialize each adjacency list 
  
    for (int i = 0; i < ve; ++i){
        
        graph->array[i].head = NULL;
       graph->array[i].src_vi=1;
    }
    return graph;
}
void freegraph(struct Graph* graph)  {
    for (int i = 0; i < ve; ++i){
         deleteListgraph(&graph->array[i].head);
        
        graph->array[i].head = NULL;
    }    
   free(graph->array) ;
   free(graph);
    
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
  
     struct Node* newNode = 
            new_Node(dest, weight);
    newNode->next = (graph)->array[src].head;
      (graph)->array[src].head = newNode;
             
    
   
  //free(graph1);
}

void removenode(struct Graph* graph,int key){

    for(int i=0;i<ve;i++){
       if((graph)->array[key].src_vi=0){
       
       struct Node* n=graph->array[i].head;  
       deleteNode(&n,key);
       (graph)->array[key].src_vi=1;
    }
    
    }
   
   
   
}
void deleteNode(struct Node** head_ref, int key)
{
     //printf("%d\n",key);
    // Store head node
    struct Node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->dest == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
  while (temp != NULL && temp->dest != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
   
    free(temp); // Free memory
}





// Iterative function to delete a linked list

void ifwehavenode(struct Graph* graph,int key){//if we have node delete adj of node
   
       
      struct Node* n=graph->array[key].head;
       
        deleteListgraph(&n);
        graph->array[key].head = NULL;
       // if(graph->array[key].head==NULL){
           // printf("%d \n",key);
        //}
        
       
        
     // printf("%d\n",key);
    
     
     
}
void deleteListgraph(struct Node** head_ref)
{
 
   struct Node* current = *head_ref;
   struct Node* next;
    // printf("%d \n",head_ref[0]->dest);
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
  
  
} 
// Structure to represent a min heap node
struct MinHeapNode
{
    int  v;
    int dist;
};
  
// Structure to represent a min heap


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
 void  freeMinHeap(struct MinHeap* m)
{
   free(m->array);
   free(m->pos);
   free(m) ;
   
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

void swapMinHeapNode(struct MinHeapNode** a, 
                     struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
  

// heapify at given idx

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
  

int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}
  

// minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* 
                                   minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
  
    // Store the root node
    struct MinHeapNode* root = 
                   minHeap->array[0];
    
 
    struct MinHeapNode* lastNode = 
         minHeap->array[minHeap->size - 1];
    
    minHeap->array[0] = lastNode;
     // free(root);
    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
  
    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);
  
    return root;
}
  
// Function to decreasy dist value 

void decreaseKey(struct MinHeap* minHeap, 
                         int v, int dist)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];
  
    // Get the node and update its dist value
    minHeap->array[i]->dist = dist;
  
    // Travel up while the complete 
    // tree is not hepified.
    
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

int dijkstra(struct Graph* graph, int src,int dest)
{
    
    // Get the number of vertices in graph
    int V = ve;
    //printf("%d", graph->vertex);  
    
    int dist[ve];     
   struct MinHeap* minHeap=NULL;
    // minHeap represents set E
     minHeap = createMinHeap(V);
    
  
    for (int v = 0; v <ve; ++v)
    {  
        
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, 
                                      dist[v]);
        minHeap->pos[v] = v;
    
    
    }

    // Make dist value of src vertex 
    // as 0 so that it is extracted first
    minHeap->array[src]->dist=0;
    minHeap->array[src]->v=src;   
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
   
    // Initially size of min heap is equal to V
    minHeap->size = V;
  
    // In the followin l;loop, 
    // min heap contains all nodes
   
    while (!isEmpty(minHeap))
    {
        
        
    
        // Extract the vertex with 
        // minimum distance value
        struct MinHeapNode* minHeapNode = 
                     extractMin(minHeap);
         

        // Store the extracted vertex number
        int u = minHeapNode->v; 
       // minHeap->array[u]=NULL;
        // Traverse through all adjacent 
       
        struct Node* pCrawl =
                     graph->array[u].head;
        
        while (pCrawl != NULL)
        {
           //printf("%d \n",pCrawl->dest);
            int v = pCrawl->dest;
           // printf(" %d ",dist[1]);
            
            if (isInMinHeap(minHeap, v) && 
                      dist[u] != INT_MAX && 
              pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                
                // update distance 
                // value in min heap also
                decreaseKey(minHeap, v, dist[v]);
              /// free(minHeap->array[u]);
            }
            pCrawl = pCrawl->next;
          
        }
       free(minHeapNode);
       
       //free(pCrawl);
    }
     
    free(minHeap->pos);
    
     
    
    
    free(minHeap->array);
    



    free(minHeap);
    minHeap==NULL;
    if(dist[dest]==INT_MAX){
        return -1;
    }
    
    
  
    
    
    //freeMinHeap(minHeap);
    
    //printf("%d\n",graph->vertex);
    // print the calculated shortest distances
     return dist[dest];
}