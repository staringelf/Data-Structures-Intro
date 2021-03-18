#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct node* prev;
   int val;
   struct node* next;
};


struct node* first = NULL;

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
   printf("1. Append\n2. Display\n3. Exit\n4. Push\n5. Insert\n6. Remove First\n7. Remove Last\n8. Delete\n\nDON'T PRESS ANY OTHER KEY,even if you do doesn't matter much, the mess is yours\n\n");
   for(;;)
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
		printf("Enter the position: ");
		scanf("%d", &pos);
		printf("Enter the value: ");
		scanf("%d", &value);
		insert(value, pos);
		break;
 	     case 6:
		remove_first();
		break;
	     case 7:
		remove_last();
		break;
	     case 8:
                printf("Enter the position: ");
 		scanf("%d", &pos);
		delete(pos);
		break;
	     default:
	 	printf("\nInvalid input\n");
		break;
	   }
	  
}

void print_list(void)
{
   struct node* ptr;
   ptr = first;
   printf("\nList :");
   if(first == NULL)
	printf("Empty");
   else
	do{
	   printf("%d  ", ptr -> val);
	}while(ptr = ptr -> next);
   printf("\n\n"); 	
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
   
   temp -> val = num;
   temp -> next = NULL;
   temp -> prev = NULL;

   if(first == NULL)
	first = temp;
   else {
      struct node* ptr =  first;

      while(ptr -> next)
	  ptr = ptr -> next;
      ptr -> next = temp;   
      temp -> prev = ptr;     
   }
   print_list();
}


void push(int num)
{
   struct node* temp = create_node();
   temp -> val = num;
   temp -> next = first;
   temp -> prev = NULL;
   first = temp;
   print_list();
}

void insert(int num, int pos)
{
  struct node* temp = create_node();
  struct node* ptr = first;
  
  if(first == NULL || pos == 0){
	temp -> val = num;
        temp -> next = first;
        first = temp;
        temp -> prev = NULL;
        print_list();
  }
  else {
	for(int i = 0; i < pos - 1 && ptr; i++)
		ptr = ptr -> next;
        if(ptr){
	  temp -> next = ptr -> next;
	  temp -> val = num;
	  ptr -> next = temp;
          temp -> prev = ptr;
          print_list();
	}
       else
	printf("\nEnter a negotiable position: List not long enough!\n");
  }
}


void remove_first(void)
{ 
  struct node* temp;

  if (first){
     temp = first;
     first = first -> next;
     first -> prev = NULL;
     free(temp);
     print_list();
   }
  else 
    printf("\nEmpty List: Another empty galaxy, I can't give up on another life yet!\n\n");
}


void remove_last(void)
{
  struct node* ptr = first;
  struct node* second_last = NULL;
/*	
  if(first && (first -> prev == first -> next)){
	first = NULL;
	free(ptr);
  }

  else if (first -> next){
    for(ptr = first; ptr -> next; ptr = ptr -> next)
         second_last = ptr;
    second_last -> next = NULL;
    free(ptr);
    print_list();
  }
  else
    printf("\nThere is no one out here, just empty space!\n\n");

  
  /*
   struct node* ptr = first;
  int i;  
  
  if(first){
     for(i = 0; ptr -> next; i++)
        ptr = ptr -> next;
     free(ptr);
     if( i == 0)
	remove_first();
     else{
       for(ptr = first; --i > 0; ptr = ptr -> next)
         ;
       ptr -> next = NULL;
     }
     print_list();
  }
  else {
    printf("\nEmpty List: Cannot remove last element\n\n");
  }
  */
}

void delete(int position)
{
  struct node* ptr = first;
  struct node* temp;
  int i;
  if(first){
    if (position == 0){
        temp = first;
        first = first -> next;
        first -> prev = NULL;
        free(temp);
    }
    else{
      for(i = 0; i < position - 1 && ptr -> next; i++)
	  ptr = ptr -> next;
      if(ptr -> next){
   	temp = ptr;
  	ptr = ptr -> next;
  	temp -> next = ptr -> next;
  	free(ptr);
        print_list();
      }
    
    else
	printf("\nYou are trying to delete a non-existing being\n");
    }
  }
  else
	printf("\n\nNO list means no delete\n\n");
}


int menu(void)
{
   int option;
   printf("Enter the option: ");
   scanf("%d", &option);
   return option;
}
