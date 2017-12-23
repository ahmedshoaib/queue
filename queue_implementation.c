#include<stdio.h>
#include<stdlib.h>


struct Queue
{
	int start;          //points to oldest entry
	int end;                   //points to next of latest entry
	int length;              //capacity of queue
	int * array;                //array to store the queue
};


 struct Queue* Create_Queue(int n)     // function to create queue   ;; returns pointer to created queue
 {
	 struct Queue * queue = (struct Queue*) malloc(sizeof(struct Queue));
	 queue->start = 0;
	 queue->end = 0;
	 queue->length = n;
	 queue->array = (int *) malloc(queue->length*sizeof(int));
	 return queue;
 }
 
 void Enqueue(struct Queue* queue,int n)   //queue and element as input ;; circular queue  ;; 
 {
	if((queue->end + 1)%queue->length != queue->start)
	{
		queue->array[queue->end] = n;
		queue->end = (queue->end + 1) % queue->length ;
		
	}
	else
	{
		printf("\nqueue full");
		
	}
 }
 
 int Dequeue(struct Queue* queue)   //head and tail  ;; circular queue  ;; 
 {
	 int n;
	if(queue->end != queue->start)
	{
		n = queue->array[queue->start];
		queue->start = (queue->start + 1) % queue->length ;
		return n;
	}
	else
	{
		printf("queue empty");
		exit(1);
	}
 }
 
 
 void View(struct Queue* queue)
 {
	 int i,j,count,head,tail;
	 if(queue->start == queue->end)
	 {
		 printf("\nqueue empty");
	 }	 
	 
	 else
	 {
		 head = queue->start;
		 tail = queue->end;
		 i=head;
		 while(i != tail)
		 {
			 printf(" %d ",queue->array[i]);
			 i = (i+1)%queue->length;
		 }
	 }
 }
 
 int main()
 {
	  int i,n,opt;
	 struct Queue* queue ;
	 printf("Enter max. length of queue : ");
	 scanf("%d",&n);
	 queue = Create_Queue(n+1);       //since max length of queue is length of array - 1
	 printf("\nEnter a number : \n1.) Enqueue\n2.) Dequeue\n3.) View Queue\n4.) Exit. "); //operations on stack
	 while(1)
	 {
		printf("\ninput option : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :
				printf("input number to Enqueue : ");
				scanf("%d",&n);
				Enqueue(queue,n);
				break;
			case 2 : 
				printf("Dequeued  element : %d",Dequeue(queue));
				break;
			case 3 :
				printf("contents of queue : ");
				View(queue);
				break;
			case 4 : 
				return 0;
			default : 
				printf("\nInvalid option. Input correct option");
		}
	 }
 }