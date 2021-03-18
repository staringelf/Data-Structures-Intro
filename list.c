#include <stdio.h>
#include <stdlib.h>

struct node
{
   int val;
   struct node* next;
};


struct node* first = NULL;
struct node* head = NULL;

void append(int val);
void push(int val);
void insert(int val, int position);
void remove_first(void);
void remove_last(void);
void delete(int pos);
struct node* create_node(void);
void print_list(void);
int menu(void);


int main(void)
{
   int value;
   int pos;
   for(;;){
	   switch(menu()){
	     case 1:
		printf("Enter the value: ");
	 	scanf("%d", &value);
		append(value);
		break;
	     case 2:
		print_list();
		break;
	     case 3:
		exit(0);
		break;
	     case 4:
		printf("Enter the value: ");
	 	scanf("%d", &value);
		push(value);
		break; 
	     case 5: 
		printf("Enter the value: ");
		scanf("%d", &value);
		printf("Enter the position: ");
		scanf("%d", &pos);
		insert(value, pos);
		break;
 	     case 6:
		remove_first();
		break;
	     case 7:
		remove_last();
		break;
	     default:
	 	printf("Invalid input");
		break;
	   }
	   print_list();
	}
}

void print_list(void)
{
   struct node* ptr;
   ptr = first;
   printf("List :");
   if(first == NULL)
	printf("Empty\n");
   else
	do{
	   printf("%d\t", ptr -> val);
	}while(ptr = ptr -> next);
   printf("\n"); 	
}

struct node* create_node(void)
{
   struct node* temp;
   temp = (struct node*)malloc(sizeof(struct node));
   return temp;
}

void append(int num)
{   
   struct node* temp = create_node();
   
   if(first == NULL) {
	first = temp;
	first -> next = NULL;
	first -> val = num;
    	head = first;
   }
   
   else {
	head -> next = temp;
	head = temp;
	head -> val = num;
	head -> next = NULL;
   }
}


void push(int num)
{
   struct node* temp = create_node();
   
   if (first == NULL)
	append(num);
   else{
   	temp -> val = num;
   	temp -> next = first;
   	first =  temp;
   }
}

void insert(int num, int pos)
{
  struct node* temp = create_node();
  struct node* ptr = first;
  
  if(first == NULL && pos == 0)
	append(num);
  else {
	for(int i = 0; i < pos - 1 && ptr; i++)
		ptr = ptr -> next;
	temp -> next = ptr -> next;
	temp -> val = num;
	ptr -> next = temp;
  }	
}


void remove_first(void)
{
  if (first)
     first = first -> next;
  else 
    printf("Invalid Input\n");
}

void remove_last(void)
{
  struct node* ptr;
  struct node* second_last;
  ptr = first;
  while(ptr != head){
     second_last = ptr;
     ptr = ptr -> next;
  } 
  head = second_last;
  second_last -> next = NULL;
}


int menu(void)
{
   int option;
   printf("Enter the option: ");
   scanf("%d", &option);
   return option;
}
