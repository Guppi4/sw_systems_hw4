
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
int t_dijkstra=0;
int tr_dijkstra=0;
printf("%s ",stringf);
do{
        
        
        switch (choice)
        {
        case 'A':
          
             //printf("TTT");
         
            for(int i=1;i<strlen(stringf);i+=2){
             //printf("%c ",stringf[i+1]);
            
              //printf(" %c",stringf[i]);
              if( stringf[i+1]=='T' || stringf[i+1]=='S' || stringf[i+1]=='D' || stringf[i+1]=='B' ){
                    choice=stringf[i+1];
                  break;
              }
            if(isalpha(stringf[i-1]) && isalpha(stringf[i+1])){
               addEdge(graph,stringf[i]-'0',stringf[i]-'0',0);
              // printf("%d %d %d\n",stringf[i]-'0',stringf[i]-'0',0);
            }
            if(stringf[i-1]=='n'){
                k=stringf[i]-'0';
            addEdge(graph,k,stringf[i+1]-'0',stringf[i+2]-'0');
            //printf("%d %d %d\n",k,stringf[i+1]-'0',stringf[i+2]-'0');
            }
             if(!isalpha(stringf[i-1]) && !isalpha(stringf[i+1])){
               addEdge(graph,k,stringf[i+1]-'0',stringf[i+2]-'0');
            // printf("%d %d %d\n",k,stringf[i+1]-'0',stringf[i+2]-'0');
             }
            }
               
            break;     
        
        case 'B':
           for (int i=j_b;stringf[i]!='B' && i<strlen(stringf);i++){
              j_b++;
           }
            ifwehavenode(graph,stringf[j_b+1]-'0');
           for(int i=j_b+1;i<strlen(stringf);i+=2){
             //printf("%c ",stringf[i+1]);
                    if(i==strlen(stringf)-2){
                      choice='E';
                      j_b++;
                      break;
                    }
              //printf(" %c",stringf[i]);
              
              if( stringf[i+1]=='T' || stringf[i+1]=='S' || stringf[i+1]=='D' || stringf[i+1]=='B' ){
                    choice=stringf[i+1];
                  j_b++;
                  break;
              }
            
             
               addEdge(graph,stringf[j_b+1]-'0',stringf[i+1]-'0',stringf[i+2]-'0');
             printf("%d %d %d\n",stringf[j_b+1]-'0',stringf[i+1]-'0',stringf[i+2]-'0');
             
            }
           
        break;
        case 'D':
         //printf("Hello");
         for (int i=j_d;stringf[i-1]!='D';i++){
              j_d++;
           }
           removenode(graph,(stringf[i]-'0'));
           
          if(strlen(stringf)-2==j_d){
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
             choice='E';
             break;   
              }
         ///printf("this  is S");
            
            
            break;	 
        
        case 'T': 
           for (int i=j_t;stringf[i]!='T';i++){
              j_t++;
           }
            //printf("%d %ld\n",j_t+3,strlen(stringf)-2);
            for(int k=j_t+3; k<=strlen(stringf);k++){
                    

                    if(k==strlen(stringf)-1){
                      
                      
                      t_dijkstra+=dijkstra(graph,stringf[k-1]-'0',stringf[k]-'0');
                      choice='E';
                      break;
                    }
                    if(isalpha(stringf[k])){
                       
                        choice=stringf[k];
                        break;
                    }
                    
                    if(dijkstra(graph,stringf[k-1]-'0',stringf[k]-'0')==-1){
                      t_dijkstra=-1;
                      break;
                    }
                    
                    
                    ///printf("%c %c\n",stringf[k-1],stringf[k]);
                    
                    t_dijkstra+=dijkstra(graph,stringf[k-1]-'0',stringf[k]-'0');  
            //printf("%d %d\n",k,stringf[k]-'0');
            //printf("%d %c\n",k,stringf[k]);
            }
            
             printf("TSP shortest path: %d\n",t_dijkstra);
            
           t_dijkstra=0;
           
           j_t++;
            
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