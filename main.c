
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "miheap.h"
#include <stdbool.h>
#include <ctype.h>
#define a 100

int main()
{
char line[a];
char buf[a][a];
int count=0;
int array[a];
char s[a] ;
char choice;
char c1;
char s1[a];
      int i=0;
  while (fgets(line, sizeof(line), stdin)) {
  strcat(s,line);
 
    strcpy(&buf[i][0],line);
  //int len=strnlen(line);
  i++;
  //
      }
    strcat(s1,buf[0]);
 int j;
  
  for (j = 0; s1[j] != '\0'; j++){
       if(j==0){
        choice=s1[j];
       }
    };
          
     printf("%s",s1);    
do{
        
        
        switch (choice)
        {
        case 'A':
          
         
         
             
             //free(array1);
             
         
         //int j;
         //for(j=0;j<=count;j++){
              printf("this  is A");
          //}
          choice='S';
            break;     
        case 'S':
		printf("this  is S");
            choice='T';
            break;	 
        
        case 'T': 
            printf("this  is T");
           choice='D';
            break;
        
        default:
            break;
       
        }
    }while (choice != 'D');   
       

 
 
	struct Graph* graph = createGraph();

	addEdge(graph, 0, 1, 4);
	addEdge(graph, 0, 7, 8);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 7, 11);
	addEdge(graph, 2, 3, 7);
	addEdge(graph, 2, 8, 2);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 3, 4, 9);
	addEdge(graph, 3, 5, 14);
	addEdge(graph, 4, 5, 10);
	addEdge(graph, 5, 6, 2);
	addEdge(graph, 6, 7, 1);
	addEdge(graph, 6, 8, 6);
	addEdge(graph, 9, 5, 7);
	addEdge(graph, 0, 9, 1);
	dijkstra(graph, 0);
     
	return 0;
}