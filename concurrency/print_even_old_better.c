#include<stdio.h>
#include<pthread.h>

pthread_t tid[2];
unsigned int shared_data = 0;
pthread_mutex_t mutex;
pthread_cond_t cv;
int turn = 1;;
unsigned int rc;

void* PrintEvenNos(void*);
void* PrintOddNos(void*);

void main(void)
{
	pthread_create(&tid[0],0,&PrintEvenNos,0);
	pthread_create(&tid[1],0,&PrintOddNos,0);
	sleep(3);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
}

void WaitTurn(int odd_turn){
	rc = pthread_mutex_lock(&mutex);
	while ( turn != odd_turn ){
		pthread_cond_wait(&cv, &mutex);	
	}

}

void ToggleTurn( void ){
	rc = pthread_mutex_lock(&mutex);
	turn = !turn;

	pthread_cond_signal(&cv);	
}

void* PrintEvenNos(void *ptr)
{
	WaitTurn(1);
	do
	{
		if(shared_data%2 == 0)
		{
			printf("Even:%d\n",shared_data);
			shared_data++;
		}
		else
		{
			ToggleTurn();
		}
	} while (shared_data <= 100);
}

void* PrintOddNos(void* ptr1)
{
	WaitTurn(0);
	do
	{
		if(shared_data%2 != 0)
		{
			printf("odd:%d\n",shared_data);
			shared_data++;
		}
		else
		{
			ToggleTurn();
		}
	} while (shared_data <= 100);
}
