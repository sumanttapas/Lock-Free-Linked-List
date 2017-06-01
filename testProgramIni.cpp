#include "LockFreeListFinal.h"

struct arg
{
	List list;
	int thread_id;
	int tnum;

};

void *thread1(void *);

int threadlimit;
int main(int argc, char *argv[])
{
	List mylist = list_init(); //initialize the list object. Can be called as constructor
	

	if(argc > 3 && argc < 2){
		printf("\nError! Pass 2 arguments");
		exit(0);
	}
	threadlimit = std::stoi(argv[1]);
	int numberOfThreads = std::stoi(argv[2]);
	
	pthread_t * t = (pthread_t *)malloc(numberOfThreads*sizeof(pthread_t));
	
	struct arg * tArgs =(arg *)malloc(numberOfThreads*sizeof(struct arg));
	
	int i;
	for(i=0;i<numberOfThreads;i++)
	{
		tArgs[i].list = mylist;
		tArgs[i].thread_id = i;
		tArgs[i].tnum = numberOfThreads;
		pthread_create (&t[i], NULL, thread1, (void *)&tArgs[i]);
	}
	
	
	for(i=0;i<numberOfThreads;i++)
	{
		pthread_join (t[i], NULL);
	}
	
// #ifdef debug
	mylist->print(mylist->head);
// #endif
	mylist->destructor(mylist->head);
	free(mylist);
	free(t);
	free(tArgs);
	printf("Exiting Gracefully\n");

	return 0;
}

void * thread1(void * args)

{
	struct arg * arguments = (struct arg *)args;
	unsigned int i;
	
	for(i=arguments->thread_id; i < ((threadlimit)*arguments->tnum)+(arguments->thread_id); i=i+arguments->tnum)
	{
		arguments->list->insert(i, arguments->list->head, NULL);
	}
}

