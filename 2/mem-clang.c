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
struct list* CreateList(int i); // Creates a new list node
void append(struct list** head_ref, short R11,int R8); // Appends a new node to the list
void deletefirst (struct list **head); // Deletes the first node from the list
void getNode(struct list *head, int R9); // Retrieves a node at a specific position
void freeList(struct list *node);  // Frees the memory allocated for the list

int main(){
	int flag=1; //Vars
	int answer;
	int R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10;
	int R12,R13,R14,R15,R16,R17,R18,R19,R20;
	int R21,R22,R23,R24,R25,R26,R27,R28,R29,R30,R31;
	short int value;
	short int R11;
	int i=1,thesi;
	struct list **current;
	struct list *pointer;

	printf("Welcome to the MEMORY-CLANG program!!\n\n");	
	R0=0; //Vars
	R1=flag; //Set R1 to flag
	R2=answer; // Set R2 to answer
	R3=1; //Registers
	R4=2; /* R3-R7 menu registers*/
	R5=3;
	R6=4;
	R7=5;
	R8=i;
	R9=thesi; //Address-Position register
	R11=value; //Node value
	while_loop:
		if(R1!=R3)goto main_loop;
	
	Menu(); // Display the menu
	scanf("%d",&R2); // Get user input for menu selection
	answer=R2;
	if(R2!=R3)goto condition_1;

	pointer=CreateList(R8);
	R8=R8+1; // Increment the index
	i=R8; // Update the index variable
	
	condition_1: // Condtion_1 - List created
	if(R2!=R4)goto condition_2;
	printf("Set node value: ");
	scanf(" %d",&R11);
	value=R11;
	current=&pointer;
	append(current,R11,R8);
	R8=R8+1;
	i=R8;
	
	condition_2: // Condtion_2 - Append
	if(R2!=R5)goto condition_3; 
	assert(pointer!=NULL);
	deletefirst(current);
	condition_3:
	if(R2!=R6)goto condition_4; // Condtion_3 - Append
	assert(pointer!=NULL);
	printf("Set node value you want to display: ");
	scanf("%d",&R9);
	getNode(pointer,R9);
	thesi=R9;
	condition_4:
	if(R2!=R7)goto condition_5;
	R1=R0;
	flag=R1;
	printf("Exit program!");
	condition_5:
	goto while_loop;
	
    main_loop:
	system("PAUSE");
	return 0;

}

void Menu(){ // choice menu
	printf("\nMENU\n\n");
	printf("1)List creation\n");
	printf("2)Insert item\n");
	printf("3)Deletion of 1st item\n");
	printf("4)Print a specific item\n");
	printf("5)Exit\n\n");
	printf("Choose option: ");
}

// Function to allocate memory for the list 
struct list* CreateList(int R8){
	struct list* ptr;
	ptr=(struct list*)malloc(sizeof(struct list)); // Pointer for the new list node
	printf("Give 1st element: "); // Prompt for value
	scanf(" %d",&ptr->value);
	ptr->id=R8;
	ptr->next=NULL;
	printf("List created!!\n");
	return ptr; // Return the new node
}


// Function to allocate memory for new node
void append(struct list** head, short R11,int R8)
{
	struct list* new_node = (struct list*) malloc(sizeof(struct list));
	struct list *last = *head; // Pointer to traverse the list - head of list
	new_node->value = R11;
	new_node->id=R8;
	new_node->next=NULL;
	if (!(*head==NULL))goto end;
		*head= new_node;
	end:
	while_loop:
		if(!(last->next != NULL))goto ending;
		last = last->next;
	goto while_loop;
	ending:
	last->next = new_node;
}
// Function to delete first node
void deletefirst (struct list **head){
	struct list* temp = *head;
	if (!(*head != NULL))goto end;
	*head = (*head)->next;
	free(temp);
	end:
	printf("\nElement deleted successfully! ");
}

// Function to get node element
void getNode(struct list *head, int R9) 
{ 
	int len = 1;
	struct list* temp=head; 
	while_loop:
	if(!(len!=R9))goto ending;
	// Pointer to traverse the list
	temp=temp->next;
	len++;
	goto while_loop;
	ending:
	if(!(R9>len))goto else_step;
	printf("Shorter linked list");
	goto continue_on;
	else_step:
	printf("Position %d with value %d",temp->id,temp->value);
	continue_on:
	return;
}

//Function to Free each node in the list
void freeList(struct list *node){ 
	struct list *tmp = node; 
	while_loop:
	if(!(tmp != NULL))goto ending; // Check if the current node is not NULL
	node = node->next;
	free(tmp); // Free the current node
	tmp = node;
	goto while_loop;
	ending:
	return; // Exit the function
}
