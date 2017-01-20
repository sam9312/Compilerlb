#include<stdio.h>
#include<stdlib.h>


const int size=20;

int heap[20];

void insert(int data);
void delete(void);



void display(int i)
{
	if(heap[i]==-999)
		return;
	
	else
	{	
		display((2*i)+1);
		printf("%d\t",heap[i]);
		display((2*i)+2);
	}
}		


int isfull()
{
	return(heap[size-1]);
}


void main()
{
	int i;

	for(i=0;i<size;i++)
		heap[i]=-999;

	int num;
	int data;
		
	printf("\nHow many elements? ");
	scanf("%d",&num);
	printf("\nEnter the elements: ");
	for(i=0;i<num;i++)
	{
		if(isfull()==-999)
		{scanf("%d",&data);
		insert(data);}
	}
	printf("\n\n");
	display(0);

	int option;
do{
	printf("\n\n\nmenu:\n1. insert\n2. delete\n3. display\n4. exit\noption: ");
	scanf("%d",&option);

	switch(option)
	{
		case 1: if(isfull()!=-999)
			{
				printf("\nHeap is full!\n");
				break;
			}

			printf("\nEnter data: ");
			scanf("%d",&data);
			
			insert(data);
			printf("\n\n");
			display(0);
			break;

		case 2: if(heap[0]!=-999)
			delete();
						
			else
				printf("\nEmpty heap!\n");

			break;

		case 4: exit(0);
		case 3:	printf("\n\n");
			 display(0);	break;	
		default: printf("\nWrong option entered!\n");
	}
}while(option!=4);
}





void insert(int data)
{
	int i=0;
	while(heap[i]!=-999)
		i++;

	heap[i]=data;

	int parent;
	if(i%2==0)
		parent=(i-2)/2;
	else
		parent=(i-1)/2;

	int temp;
	

	while(parent>=0)
	{
		if(heap[parent]<heap[i])
		{
			temp=heap[parent];
			heap[parent]=heap[i];
			heap[i]=temp;
	
			i=parent;

			if(i%2==0)
				parent=(i-2)/2;
			else
				parent=(i-1)/2;
			
		}
		
		else 
			break;
	}

		
}




void delete()
{
	int i=0;
	
	while(heap[i]!=-999)
		i++;

	i--;
	
	printf("\nDeleting root %d\n",heap[0]);	

	heap[0]=heap[i];
	heap[i]=-999;

	int parent=0;
	int left, right;
	int temp;
	while(heap[parent]!=-999)
	{
		left=(2*parent)+1;
		right=(2*parent)+2;

		int large, pos;
	
		if(heap[left]>heap[right])
		{
			large=heap[left];
			pos=left;
		}
		else
		{
			large=heap[right];
			pos=right;
		}

		if(large>heap[parent])
		{	
			temp=heap[parent];
			heap[parent]=heap[pos];
			heap[pos]=temp;
		
			parent=pos;
		}
		else
		break;
	}
	printf("\n\n");
	display(0);
}


			
