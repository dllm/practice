#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode {
	struct Qnode *prev, *next;
	int key;
} Qnode;

typedef struct Queue {
	int size;
	Qnode *head, *tail;
} Queue;

typedef struct hash {
	int size;
	Qnode* *array;
} hash;

Qnode* newNode (int key ){

	Qnode *tmp = malloc (sizeof(Qnode));
	tmp->key = key;
	tmp->prev = tmp->next = tmp;

	return tmp;
}

Queue* newQueue ( ){
	
	Qnode *tmp = malloc (sizeof (Queue));
	tmp->size = 0;
	tmp->head = tmp->tail = tmp;

	return tmp;
}

#define HASHSIZE 10

Hash* newHash (int hashsize ) {
	Hash* tmp = malloc (sizeof (HASH));
	tmp->size = hashsize;

	hash->array = malloc (sizeof(Qnode*) * hashsize );

	for (int i = 0; i < hashsize; i++){
		hash->array[i] = NULL;
	}	


}

