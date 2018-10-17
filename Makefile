#Makefile for assignment 02
#by Carlos Hernandez Quintero

CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=pagerank.o queue.o graph.o

all : $(OBJS)
  $(CC) pagerank.o queue.o graph.o -o pagerank

pagerank.o : pagerank.c queue.h graph.h
  $(CC) $(CFLAGS) pagerank.c

queue.o : queue.c queue.h
  $(CC) $(CFLAGS) queue.c

graph.o : graph.c graph.h
  $(CC) $(CFLAGS) graph.c

#clean : rm -fr $(OBJS) core
