#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct node* prev;
   int val;
   struct node* next;
};


struct node* first = NULL;
struct node* last = NULL;

void push(int val);
void pop(void);
int menu(void);


int main(void)
{
   int value;
   printf("1. Push\n2. Pop\n3. Exit\n   DON'T PRESS ANY OTHER KEY,even if you do doesn't matter much, the mess is yours\n\n");
   for(;;)
	   switch(menu()){
	     case 1:
		printf("Enter the value: ");
	 	scanf("%d", &value);
		push(value);
		break;
	     case 3:
		exit(0);
		break;
	     case 2:
		pop();
		break;
	     default:
	 	printf("\nInvalid input\n");
		break;
	   }
	  
}

struct node* create_node(void)
{
   struct node* temp;
   temp = (struct node*)malloc(sizeof(struct node));
   return temp;
}

void push(int num)
{   
   struct node* temp = create_node();
   
   if(first == NULL) {
	first = temp;
	first -> next = NULL;
	first -> val = num;
	first -> prev = NULL;
    	last = first;
   }
   
   else {
	temp -> prev = last;
	last -> next = temp;
	last = temp;
	last -> val = num;
	last -> next = NULL;
   }
}



void pop(void)
{
  if(first == NULL)
	printf("\nStack Empty!\n");
  
  else if(last != first){  
     printf("\n\t\tPopped: %d\n\n", last -> val);    
     last = last -> prev;
     last -> next = NULL;
  }
  else{
	printf("\n\t\tPopped: %d\n\n", last -> val);
	first = last = NULL;
  }
}

int menu(void)
{
   int option;
   printf("Enter the option: ");
   scanf("%d", &option);
   return option;
}
