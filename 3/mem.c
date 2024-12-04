/*
            ======================================================
            + Name        : mem.c                                +
            + Author      : Christos Z, 		                 +
            + Description : Memory management                    +
            ======================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list{ // Define a structure for a linked list node

	short value;
	int id;
	struct list *next;

};
// Function prototypes
void Menu(); // Displays the menu options
int CreateList(int i); // Creates a new list node
void append(struct list** head_ref, short new_data,int i); // Appends a new node to the list
void deletefirst (struct list **head); // Deletes the first node from the list
void printCount(struct list*head); // Prints the count of nodes in the list
void getNode(struct list *head, int n); // Retrieves a node at a specific position
void printNodeAddress(struct list* head, int n); // Prints the address of a specific node
void printListAddress(struct list* head);// Prints the address of the list
void printItemAddress(struct list* head,int n); // Prints the address of a specific item in a node
void printListsize(struct list *head); // Prints the size of the list
void printItemsize(struct list*head); // Prints the size of an item in the list

void printList(struct list*); // Prints all items in the list
void freeList(struct list *node); // Frees the memory allocated for the list

//Function pointers
int (*fptr1)(int);
void (*fptr2)(struct list**,short,int);
void (*fptr3)(struct list**);
void (*fptr4)(struct list*,int);
void (*fptr5)(struct list*);

int main(){
	
	int flag=1;
	int answer;
	short int value;
	int i=1;
	struct list *head,*n1,**current;
	
	printf("Welcome to the MEMORY program!!\n\n");
	while(flag){
	Menu();
	scanf("%d",&answer);
	// Create a new list if the user chooses option 1
	if(answer==1){
		fptr1=&CreateList;
		head=(struct list*)(*fptr1)(i);
		i++; //increment list ndoe counter
	
	}
	// Append a new value to the list if the user chooses option 2
	else if(answer==2){
	
		printf("Set node value: "); // Prompt for value
		scanf("%d",&value);
		current=&head; // Set current to point to head
	
		fptr2=&append;
		(*fptr2)(current,value,i);
	
		i++; //Increment list counter
	
	}
	// Delete the first node if the user chooses option 3
	else if(answer==3){ 
		assert(current!=NULL); // Ensure current is not NULL
		fptr3=&deletefirst;
		(*fptr3)(&head);
	
	}
	// Get a specific node if the user chooses option 4
	else if(answer==4){
		assert(current!=NULL);
		printf("Type node's position: "); // Prompt for position
		scanf("%d",&answer);
		fptr4=&getNode;
		(*fptr4)(head,answer); // Retrieve the node at the specified position
	
	}
    // Print the count of nodes if the user chooses option 5
	else if(answer==5){ 
	
		assert(head!=NULL);
		fptr5=&printCount; // Print the count of nodes
		(*fptr5)(head);
	
	}
	// Print the address of a specific node if the user chooses option 6
	else if(answer==6){
		printf("Type node's position: ");
		scanf("%d",&answer);
		fptr4=&printNodeAddress;
		
		(*fptr4)(head,answer); // Print the address of the specified node
	
	}
	// Print the address of the list if the user chooses option 7
	else if(answer==7){
	
		fptr5=&printListAddress;
		(*fptr5)(head);
	
	}
	// Print the address of a specific item if the user chooses option 8
	else if(answer==8){
        printf("Give position of the element you want to show its address: ");
		scanf("%d",&answer);
		fptr4=&printItemAddress;
		(*fptr4)(head,answer);
		
	}
	// Print the size of the list if the user chooses option 9
	else if(answer==9){
	
		fptr5=&printListsize;
		(*fptr5)(head);
	
	}
	// Print the size of a specific item if the user chooses option 10
	else if(answer==10){
	
		fptr5=&printItemsize;
		(*fptr5)(head);
	
	}
	// Exit the program if the user chooses option 11
	else if(answer==11){
		flag=0;
		printf("Exit program!\n\n\n");
		printf("\n Created Linked list is: \n");
	
		fptr5=&printList;
		(*fptr5)(head);
		assert(head!=NULL);
	
		fptr5=&freeList;
		(*fptr5)(head);
	
		system("\nPause");
	
	}
	// Print function addresses if the user chooses option 12
	else if(answer==12){
	
		printf("Dieuthinseis synarthseon: \n");
		printf("Create List:%p\n",CreateList);
		printf("Append:%p\n",append);
		printf("DeleteFirst:%p\n",deletefirst);
		printf("GetNode:%p\n",getNode);
		printf("PrintCount:%p\n",printCount);
		printf("PrintNodeAddress:%p\n",printNodeAddress);
		printf("PrintListAddress:%p\n",printListAddress);
		printf("PrintItemAddress:%p\n",printItemAddress);
		printf("PrintListSize:%p\n",printListsize);
		printf("PrintItemSize:%p\n",printItemsize);
		printf("PrintList%p\n",printList);
		printf("FreeList:%p\n",freeList);
	
	}
	else
		printf("Wrong answer!\n");
	}

}
// Function to Display the menu options to the user
void Menu(){ // menu choice

	printf("\n\nMENU\n\n");
	printf("1)List creation\n");  // Create a list
	printf("2)Insert item\n");  // Insert an item
	printf("3)Deletion of 1st item\n"); // Delete the first item
	printf("4)Print a specific item\n"); // Print a specific item
	printf("5)Print list item number\n"); // Print the count of items
	printf("6)Print address of a specific item\n"); // Print the address of a specific item
	printf("7)Print list address\n"); // Print the address of the list
	printf("8)Print a specific field address for a specific item\n"); // Print the address of a specific field
	printf("9)Print list size\n"); // Print the size of the list
	printf("10)Print node size\n"); // Print the size of a node
	printf("11)Exit\n");
	printf("12)Print function addresses\n\n");// Print address of functions
	printf("Choose: ");
	


}
// Function to allocate memory for the list 
int CreateList(int i){ // creation of the list

	struct list* ptr;// Pointer to traverse the list - head of list
	
	ptr=(struct list*)malloc(sizeof(struct list));
	printf("Give value: ");
	scanf(" %d",&ptr->value);// Exit the function
	ptr->id=i;
	ptr->next=NULL;
	printf("List created!!\n");
	return (int)ptr;

}
// Function to append node
void append(struct list** head, short new_data,int i)
{ // insert new element in the list
	struct list* new_node = (struct list*) malloc(sizeof(struct list));
	
	struct list *last = *head;
	
	new_node->value = new_data;
	new_node->id = i;
	
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		*head=new_node;
	}
	
	while (last->next != NULL)
		last = last->next;
	
	last->next = new_node;
}

// Function to delete first node
void deletefirst (struct list **head){ // delete frist node

	struct list* temp = *head; // of the list
	if (*head != NULL)	
	{
		*head = (*head)->next; // Move head to the next node
		free(temp);  // Free the memory of the deleted node
	}
	
	printf("\nElement deleted successfully! ");

}
// Function to get node element
void getNode(struct list *head, int n)
{
	int len = 1,i;
	
	struct list* temp=head;
	
	while (len!=n)
	{
		temp=temp->next;
		len++;
	}
	if(n<=len)
		printf("Element with id=%d & value=%d",temp->id,temp->value);
	else
		printf("Shorter linked list");

}
// Function to print number of elements
void printCount(struct list* head){
	struct list *temp;
	int length = 0;
	temp = head;
	 // Traverse the list to count nodes
	while(temp!=NULL)
	{
		length++;// Move to the next node
		temp=temp->next;
	}
	printf("\nLength of Linked List : %d",length);
}
// Function to print address of node 
void printNodeAddress(struct list* head, int n){
	
	struct list *temp = head;// Pointer to traverse the list
	int len = 0,i;
	// Traverse to the nth node
	for (i = 1; i < n; i++) 
		temp = temp->next;
	
	printf("Address of the %d node is: %d",n,temp); // Print the address of the specified node

}
// Function to print address of whole list
void printListAddress(struct list* head){
	printf("Address of the list is : %d",head);
}
// Function to print item address (whole node)
void printItemAddress(struct list* head,int n){
// Pointer to traverse the list
	struct list *temp = head;
	int i;
	int len = 0; 
	
	for (i = 1; i <n; i++) // Traverse to the nth node
		temp = temp->next;
	// Prompt user for which address to print
	printf("Select element you to see its content\n1-Address value\n2-Address id\nYour answer: ");
	scanf("%d",&i);
	if(i==1)
		printf("Address of the %dth value is : %d",n,&temp->value);
	else if(i==2)
		printf("Address of the %dth id is : %d",n,&temp->id);
}
// Function to print list size (not count elements)
void printListsize(struct list *head){
	struct list *temp = head; // Pointer to traverse the list
	int sum;
	 // Traverse the list to count nodes
	while (temp->next!= NULL)	
	{
		temp = temp->next;
	}
	sum=(int)temp-(int)head;
	
	printf("List size : %d",sum);

}
//Function to print size of the item
void printItemsize(struct list*head){
	struct list *temp=head;
	int sum;
	int i=1;
	while(i<2){
	
		temp=temp->next;
		i++;

	}
	sum=(int)temp-(int)head;
	printf("Size of the item is: %d\n", sum);

}
//Function to Free each node in the list
void freeList(struct list *node){
	struct list *tmp = node; // Pointer to traverse the list
	
	while(tmp != NULL){
		node = node->next;
		free(tmp); // Free the current node
		tmp = node;
	
	}
}
//Function to print each value in the list
void printList(struct list *node)
{
	while (node != NULL)
	{
		printf(" %d\n", node->value); // Print the value of the current node
		node = node->next;

	}
}
