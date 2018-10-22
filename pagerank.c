/*
 * pagerank.c
 *
 * by Carlos Hernandez Quintero
 * 
 * comp2521, 18s2 
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "graph.h"
#include "queue.h"

//#define URLSIZE 20
//#define LINELENGTH 256
#define BUFSIZE 1024

//static functions
static char *nextURL(char *s);
static char *snatchURL(char *str, Queue q);

Queue grabCollection(void);

//scans collection.txt and builds a graph 
int main(int argc, char *argv[]){
    
    //scans collection.txt and makes list of urls
    Queue urlQ = grabCollection();
    showQueue(urlQ);//testing
    
    
    
    //int maxURLs = 0;
    
    //count urls in list
    
    //then have to get nber of urls in queue
    //build graph
    //add links in graph
    
    //Graph web = mewGraph(maxURLs);
    
    return 0;
}

//returns list of all urls in collection.txt
Queue grabCollection(void){
    
    char buffer[BUFSIZE];
    Queue myQ = newQueue();
    
    FILE *fp;
    fp = fopen("Sample1/collection.txt", "r");
    if(fp == NULL){
        printf("Error. Unable to open file. Aborting.\n");
        return 0;
    }
    
    while(!feof(fp)){//until end of file (eof)
        char *curr;
        fgets(buffer, sizeof(buffer), fp);
        curr = buffer;
        while((curr = nextURL(curr)) != NULL){//grabs next url in string
            curr = snatchURL(curr, myQ);//actually adds to Queue
        }
    }
    return myQ;
}

static char *nextURL(char *s){
    char *curr;
    //grabs next instance of 'url' from s
    curr = strstr(s, "url");
    if(curr == NULL) return NULL;
    else return curr;
}

//grabs next url in file and adds it to the queue
static char *snatchURL(char *str, Queue q){
    
    int max, i;
	char *a, *b;
	a = str;
	
	i = 0;
	//counts length of word
	while(*a != ' ' && *a != '\n' && *a != '\0'){ // Breaks between words
		i++;
		a++;
	}
	a = str;
	max = i;
	
	char *cpy = (char *)malloc(max + 1); //taking into account \0
	b = cpy;
	
	for (i = 0; i < max; i++) { // copy over chars to cpy
		*cpy++ = *a++;
	}
	*cpy = '\0';
	str = a; //sets new starting point for string
	enterQueue(q, b);
	return str;
}





