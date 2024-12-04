/*
            ======================================================
            + Name        : mem.c                                +
            + Author      : Christos Z, 		                 +
            + Description : Memory management                    +
            ======================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#ifndef JAL

#define jal(X) if(!setjmp(buf)) goto *X;

#endif

#ifndef JR31
#define JR31 (longjmp(buf,1))
#endif

struct list{

	short value;
	int id;
	struct list *next;

};

int R0=0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11;
int R12,R13,R14,R15,R16,R17,R18,R19,R20;
int R21,R22,R23,R24,R25,R26,R27,R28,R29,R30,R31;
struct list *p21;
void Menu();
int CreateList();

int append();
int deletefirst();
int getNode();
static jmp_buf buf;

int main(){

	struct list *head=NULL;
	R1=1;
	while_loop:
	
	if(R1!=1)goto epanalipsi;
	
	Menu();
	scanf("%d",&R3);
	if(R3!=1)goto condition_1;
	R4=(int)CreateList;
	jal(R4);
	condition_1:
	if(R3!=2)goto condition_2;
	R4=(int)append;
	jal(R4);
	condition_2:
	if(R3!=3)goto condition_3;
	R4=(int)deletefirst;
	jal(R4);
	condition_3:
	if(R3!=4)goto condition_4;
	R4=(int)getNode;
	jal(R4);
	condition_4:

	if(R3!=5)goto condition_5;
	
	R1=0;
	printf("\nExit program!\n\n");
		
	condition_5:
	goto while_loop;
	epanalipsi:
	system("PAUSE");
	return (EXIT_SUCCESS);

}

void Menu(){

	printf("\n\nMENU\n\n");
	printf("1)List creation\n");
	printf("2)Insert item\n");
	printf("3)Deletion of 1st item\n");
	printf("4)Print a specific item\n");
	printf("5)Exit\n");
	printf("Choose: ");

}
// Function to allocate memory for list
int CreateList(){

struct list *ptr;
	
	R8=(int)malloc(sizeof(struct list));
	ptr=(struct list*)R8;
	printf("Give 1st element: "); // Prompt for value
	scanf("%d",&R7);
	R6=(int)NULL;
	
	ptr->value=R7;
	printf("Give id: ");
	scanf("%hd",&R5);
	ptr->id=R5;
	ptr->next=(struct list*)R6;
	printf("List created!!\n");
	R2=(int)ptr;
	JR31;

}
// Function to allocate memory for new node
int append() //Function that inserts new nodes at the end of the list
{

	struct list *ptr;
	struct list *ptr2=(struct list*)R2;
	
	R8=(int)malloc(sizeof(struct list)); //Allocating memory for the new node
	ptr=(struct list*)R8;
	
	printf("\nGive me the id of the node: ");
	scanf("%d",&R7);
	ptr->id=R7;
	printf("Give me the value of the node:"); //Taking the rest of the numbers of the list
	scanf("\n%d",&R6);
	
	ptr->value=(short)R6; //Giving to him the requested value
	ptr->next=NULL; //Initialising the next pointer
	
	while_loop:
	if (!(ptr2->next!=NULL)){ goto whileEnd; //Finding the last node 
	}

	R8=(int)malloc(sizeof(struct list));
	R8=(int)ptr2->next;
	ptr2=(struct list *)R8;

	goto while_loop;
	
	whileEnd:
	
	R8=(int)malloc(sizeof(struct list));
	R8=(int)ptr;
	ptr2->next=(struct list *)R8;
	printf("The Element has been inserted to the list\n");
	R4++;
	
	JR31;

}
// Function to delete first node
int deletefirst(){

	struct list *ptr=(struct list *)R2;
	
	if(R2!=(int)NULL) goto f3;
	printf("No linked list created\n");
	
	JR31;
	f3:
	free(ptr);
	ptr=ptr->next;
	R2=(int)ptr;
	
	printf("The Element deleted Successfully\n");
	JR31;
}


// Function to get node element
int getNode(){

	struct list *ptr=(struct list *)R2;
	
	R6=R2;
	R8=1;
	// Pointer to traverse the list
	printf("Enter which node you seek:\n");
	scanf("%d",&R7);
	while_label:
	
	if (R6==(int)NULL) goto telos;
	
	if(R8!=R7) goto if_else_label;
	
	printf("Number of id is:%d: ",ptr->id);
	printf("Price of value is:%d: \n",ptr->value);
	R4=R2;
	JR31;
	if_else_label:
	R6=(int)ptr->next;
	ptr= (struct list *)R6;
	R8++;
	
	goto while_label;
	
	telos: printf("\nNode was not found\n");
	JR31;
}
