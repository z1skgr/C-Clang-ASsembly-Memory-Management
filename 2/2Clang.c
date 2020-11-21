***********************ΚΩΔΙΚΑΣ ΣΕ CLANG**********************************
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list{
	short value;
	int id;
	struct list *next;
};

void Menu();
struct list* CreateList(int i);
void append(struct list** head_ref, short R11,int R8);
void deletefirst (struct list **head);
void getNode(struct list *head, int R9);
void freeList(struct list *node);

int main(){
	int flag=1;
	int answer;
	int R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10;
	int R12,R13,R14,R15,R16,R17,R18,R19,R20;
	int R21,R22,R23,R24,R25,R26,R27,R28,R29,R30,R31;
	short int value;
	short int R11;
	int i=1,thesi;
	struct list **current;
	struct list *pointer;

	printf("Welcome to the program!!\n\n");	
	R0=0;
	R1=flag;
	R2=answer;
	R3=1;
	R4=2;
	R5=3;
	R6=4;
	R7=5;
	R8=i;
	R9=thesi;
	R11=value;
	while_loop:
		if(R1!=R3)goto epanalipsi;
	
	Menu();
	scanf("%d",&R2);
	answer=R2;
	if(R2!=R3)goto sinthiki_1;

	pointer=CreateList(R8);
	R8=R8+1;
	i=R8;
	
	sinthiki_1:
	if(R2!=R4)goto sinthiki_2;
	printf("Pliktrologiste timh: ");
	scanf(" %d",&R11);
	value=R11;
	current=&pointer;
	append(current,R11,R8);
	R8=R8+1;
	i=R8;
	sinthiki_2:
	if(R2!=R5)goto sinthiki_3;
	assert(pointer!=NULL);
	deletefirst(current);
	sinthiki_3:
	if(R2!=R6)goto sinthiki_4;
	assert(pointer!=NULL);
	printf("Pliktrologiste timh: ");
	scanf("%d",&R9);
	getNode(pointer,R9);
	thesi=R9;
	sinthiki_4:
	if(R2!=R7)goto sinthiki_5;
	R1=R0;
	flag=R1;
	printf("Exodos!");
	sinthiki_5:
	goto while_loop;
	epanalipsi:
	system("PAUSE");
	return 0;

}

void Menu(){ // choice menu
	printf("\nMENU\n\n");
	printf("1)Dhmiourgia listas\n");
	printf("2)Eisagwgh stoixeiou\n");
	printf("3)Diagrafh 1ou stoixeiou\n");
	
	printf("4)Ektypwsh sygkekrimenou stoixeiou\n");
	printf("5)Exodos\n\n");
	printf("Dialexte apantish: ");
}

struct list* CreateList(int R8){
	struct list* ptr;
	ptr=(struct list*)malloc(sizeof(struct list));
	printf("Dwste timh: ");
	scanf(" %d",&ptr->value);
	ptr->id=R8;
	ptr->next=NULL;
	printf("H lista exei dhmiourgithei!\n");
	return ptr;
}

//H συναρτηση ακριβως ιδιας λειτουργικοτητας με την αντιστοιχη στην c
//με την διαφορα στην χρηση των καταχωρητων R11 R8 στην θεση του I και //του new_value καθως
και η χρηση του goto!

void append(struct list** head, short R11,int R8)
{
	struct list* new_node = (struct list*) malloc(sizeof(struct list));
	struct list *last = *head;
	new_node->value = R11;
	new_node->id=R8;
	new_node->next=NULL;
	if (!(*head==NULL))goto end;
		*head= new_node;
	end:
	while_loopa:
		if(!(last->next != NULL))goto telos;
		last = last->next;
	goto while_loopa;
	telos:
	last->next = new_node;
}

void deletefirst (struct list **head){//διαγραφη πρωτου στοιχειου λιστας
	struct list* temp = *head;
	if (!(*head != NULL))goto end;
	*head = (*head)->next;
	free(temp);
	end:
	printf("To stoixeio diagraftike epithxws ");
}

void getNode(struct list *head, int R9) // επιλογη συγκεκριμενου κομβου
{ // της λιστας και εμφανιση του
	int len = 1; // με χρηση καταχωρητων
	struct list* temp=head; // και goto
	while_epanalipsi:
	if(!(len!=R9))goto telos;
	
	temp=temp->next;
	len++;
	goto while_epanalipsi;
	telos:
	if(!(R9>len))goto vhma_else;
	printf("Shorter linked list");
	goto synexeia;
	vhma_else:
	printf("id:%d value:%d",temp->id,temp->value);
	synexeia:
	return;
}
void freeList(struct list *node){ //απελευθερωση μνημης που χρειαστκε
	struct list *tmp = node; // η λιστα
	while_loop:
	if(!(tmp != NULL))goto telos;
	node = node->next;
	free(tmp);
	tmp = node;
	goto while_loop;
	telos:
	return;
}