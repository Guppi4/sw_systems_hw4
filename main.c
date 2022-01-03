
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
#define a 150

int main()
{

char stringf[a];

char line[a];
char buf[a][a];


char s[a] ;
char choice;

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
  int js=0;
  for (j = 0; s1[j] != '\0'; j++){
       if(j==0){
        //printf("%c ",s1[j]);
        choice=s1[j];
       }
       if(s1[j]!=' '){
       //printf("%c ",s1[j]);
       js++;
       char cToStr[2];
         cToStr[1] = '\0';
        cToStr[0] = s1[j];
      
        strcat(stringf,cToStr);
         
       }
    };
          
     //printf("%s",stringf);    
struct Graph* graph = createGraph();
int j_t=0;
int j_s;
int j_d=0;
int j_b=0;


//printf("%s",stringf);
do{
        
        
        switch (choice)
        {
        case 'A':
          
             //printf("TTT");
         freegraph(graph);
           graph=createGraph();
            for(int i=1;i<strlen(stringf);i+=2){
             //printf("%c ",stringf[i+1]);
            
              //printf(" %c",stringf[i]);
              if( stringf[i+1]=='T' || stringf[i+1]=='S' || stringf[i+1]=='D' || stringf[i+1]=='B' ){
                    choice=stringf[i+1];
                  break;
              }
            if(isalpha(stringf[i-1]) && isalpha(stringf[i+1])){
               addEdge(graph,stringf[i]-'0',stringf[i]-'0',0);
              //printf("%d %d %d\n",stringf[i]-'0',stringf[i]-'0',0);
            }
            if(stringf[i-1]=='n'){
                k=stringf[i]-'0';
            addEdge(graph,k,stringf[i+1]-'0',stringf[i+2]-'0');
            //printf("%d %d %d\n",k,stringf[i+1]-'0',stringf[i+2]-'0');
            }
             if(!isalpha(stringf[i-1]) && !isalpha(stringf[i+1])){
               addEdge(graph,k,stringf[i+1]-'0',stringf[i+2]-'0');
            //printf("%d %d %d\n",k,stringf[i+1]-'0',stringf[i+2]-'0');
             }
            }
               
            break;     
        
        case 'B':
           for (int i=j_b;stringf[i]!='B' && i<strlen(stringf);i++){
              j_b++;
           }
            
            ifwehavenode(graph,stringf[j_b+1]-'0');
          
           for(int i=j_b+1;i<strlen(stringf);i+=2){
             ///printf("%c ",stringf[i+1]);
                    if(i==strlen(stringf)-2){
                      freegraph(graph);
                      choice='E';
                      j_b++;
                      break;
                    }
              //printf(" %c",stringf[i]);
              
              if( stringf[i+1]=='T' || stringf[i+1]=='S' || stringf[i+1]=='D' || stringf[i+1]=='B' ){
                    choice=stringf[i+1];
                //printf(" %c \n",stringf[i+1]);
                  j_b++;
                  break;
              }
            
              
               addEdge(graph,stringf[j_b+1]-'0',stringf[i+1]-'0',stringf[i+2]-'0');
            //printf("%d %d %d\n",stringf[j_b+1]-'0',stringf[i+1]-'0',stringf[i+2]-'0');
             
            }
           //printf(" %c \n",stringf[j_b+1]);
        break;
        case 'D':
         //printf("Hello");
         for (int i=j_d;stringf[i-1]!='D';i++){
              j_d++;
           }
           removenode(graph,(stringf[i]-'0'));
           
          if(strlen(stringf)-2==j_d){
             freegraph(graph);
             choice='E';
             break;   
              }
              else{
               choice=stringf[j_d+1];
               break;
              }
        
        break;
        case 'S':
		      for (j_s=0;stringf[j_s]!='S' && j_s<strlen(stringf);j_s++){
              
           }
           // printf("%c",stringf[j_s]);
         printf("Dijsktra shortest path: %d\n",dijkstra(graph, stringf[j_s+1]-'0',stringf[j_s+2]-'0'));
         //printf("%d %d",j_s+2,strlen(stringf)-2);
         if(strlen(stringf)-2==j_s+2){
             freegraph(graph);
             choice='E';
             break;   
              }
         ///printf("this  is S");
            
            
            break;	 
        
       case 'T': 
           //find index of TSP chars in the string
          for (int i=j_t;stringf[i]!='T';i++){
              j_t++;
          }

          int first_node = j_t+2;
          int s = stringf[j_t+1]-'0'; //size of array(number of nodes)

         // printf("\nj_t = %d\n",j_t );
         // printf("s = %d\n",s );
         // printf("first_node = %d\n",first_node);
         // printf("HIIIIIII\n");
        //  printf("stringf[first_node+s] = %c\n", stringf[first_node+s]);
         // printf("End of prints\n");
          
          int *arr = (int*)malloc(s *sizeof(int));
          if (arr == NULL){
            printf("Can't allocate the memory\n");
            exit(0);
          }

          int temp,i,j;
          //copy all nodes into array of integers
          for(i=0;i<s;i++){
            *(arr+i) = (*(stringf+(first_node+i))-'0'); // '0' - changes char  to int
           // printf("arr[%d] = %d\n",i , arr[i]);
            //printf(*(arr+i));
            // printf((*(stringf+(first_node))-'0'));
          }
          //printf("BLOCK 1\n");
          
          //calculates all permutations of a given nodes and
          //on each permutation calculates all shortest paths between nodes
          int best_path, current_path;
          best_path = 999999;
          for(j=1; j <= s; j++){
            for(i=0; i < s-1; i++){

              temp=arr[i];
              arr[i]=arr[i+1];
              arr[i+1]=temp;
              
              //one more loop that goes over all given nodes and finds shortest path between each node
              current_path = 0;
              for(int node = 0; node<s-1;  node++){
                int dijk = dijkstra(graph, *(arr+node), *(arr+(node+1)));
                if (dijk == -1)
                  current_path += 100015;
                // printf("*(arr+%d) = %d\n",node ,*(arr+node));
                //printf("dijkstra from %d to %d = %d\n",arr[node] , arr[node+1], dijk);
                current_path += dijk;
              }
              // printf("current_path = %d\n", current_path);
              //finds best solution
              if (current_path < best_path){
                best_path = current_path;
              }
             // printf("best_path = %d\n", best_path);
            }
          }
            if(best_path >= 100000){
            best_path = -1;
          }
          
          //free the memory
          free(arr);


          int last = 0;
          //select next choice
          if(first_node + s == strlen(stringf)-1){
            freegraph(graph);
            choice = 'E';
            last = 1;
          }

           if (last){
            printf("TSP shortest path: %d ",best_path);

           }
            else{
              printf("TSP shortest path: %d \n",best_path);
            }
         

         
            
          
          if(isalpha(stringf[first_node+s])){
            choice = stringf[first_node+s];
           // printf("Next choice =%c\n", choice);
          }
          j_t++;
          //printf("END OF T\n");
          break;
        
        default:
            break;
       
        }
    }while (choice != 'E');   
       

 
 


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