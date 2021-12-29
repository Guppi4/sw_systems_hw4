
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

char stringf[a];

char line[a];
char buf[a][a];
int count=0;
int array[a];
char s[a] ;
char choice;
char c1;
char s1[a];
  int k;    
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
       if(s1[j]!=' '){
       char cToStr[2];
         cToStr[1] = '\0';
        cToStr[0] = s1[j];
      
        strcat(stringf,cToStr);
         
       }
    };
          
     printf("%s",stringf);    
struct Graph* graph = createGraph();
do{
        
        
        switch (choice)
        {
        case 'A':
          
            
         
            for(int i=1;i<j;i+=2){
             
              //printf(" %c",stringf[i]);
              if( stringf[i+1]=='T' || stringf[i+1]=='S' || stringf[i+1]=='D' ){
                    choice=stringf[i+1];
                  break;
              }
            if(isalpha(stringf[i-1]) && isalpha(stringf[i+1])){
               addEdge(graph,stringf[i]-'0',stringf[i]-'0',0);
               //printf("%c %c %c\n",stringf[i],stringf[i],0);
            }
            if(stringf[i-1]=='n'){
                k=stringf[i]-'0';
            addEdge(graph,k,stringf[i+1]-'0',stringf[i+2]-'0');
            //printf("%c %c %c\n",k,stringf[i+1],stringf[i+2]);
            }
             if(!isalpha(stringf[i-1]) && !isalpha(stringf[i+1])){
               addEdge(graph,k,stringf[i+1]-'0',stringf[i+2]-'0');
             //printf("%d %d %d\n",k,stringf[i+1],stringf[i+2]);
             }
            }
             
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
       

 
 


	//addEdge(graph, 0, 1, 4);
	//addEdge(graph, 0, 7, 8);
	//addEdge(graph, 1, 2, 8);
	//addEdge(graph, 1, 7, 11);
	//addEdge(graph, 2, 3, 7);
	//addEdge(graph, 2, 8, 2);
	//addEdge(graph, 2, 5, 4);
	//addEdge(graph, 3, 4, 9);
	//addEdge(graph, 3, 5, 14);
	//addEdge(graph, 4, 5, 10);
	//addEdge(graph, 5, 6, 2);
	//addEdge(graph, 6, 7, 1);
	//addEdge(graph, 6, 8, 6);
	//addEdge(graph, 9, 5, 7);
	//addEdge(graph, 0, 9, 1);
	//dijkstra(graph, 0);
     
	return 0;
}