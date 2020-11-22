*************************CLANG********************************************
*
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

static jmp_buf buf;
int R0=0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11;
int R12,R13,R14,R15,R16,R17,R18,R19,R20;
int R21,R22,R23,R24,R25,R26,R27,R28,R29,R30,R31;
void Menu();
int CreateList();
int append();
int deletelast();
int getNode();
int printCount();
int printAddress();
int printListAddress();
int printLowNode();

int main(){
	R1=1;
	while_loop:
		if(R1!=1)goto epanalipsi;
	Menu();
	scanf("%d",&R3);
	if(R3!=1)goto sinthiki_1;
	printf("Enter the number of nodes you
	
	want in your list: ");
	
	scanf("%d",&R10);
	R4=(int)CreateList;
	jal(R4);
	sinthiki_1:
	if(R3!=2)goto sinthiki_2;
	R4=(int)append;
	jal(R4);
	sinthiki_2:
	if(R3!=3)goto sinthiki_3;
	R4=(int)deletelast;
	jal(R4);
	sinthiki_3:
	if(R3!=4)goto sinthiki_4;
	R4=(int)getNode;
	jal(R4);
	sinthiki_4:
	if(R3!=5)goto sinthiki_5;
	R4=(int)printCount;
	jal(R4);
	sinthiki_5:
	if(R3!=6)goto sinthiki_6;
	R4=(int)printAddress;
	jal(R4);
	sinthiki_6:
	if(R3!=7)goto sinthiki_7;
	R4=(int)printListAddress;
	jal(R4);
	sinthiki_7:
	if(R3!=8)goto sinthiki_8;
	R4=(int)printLowNode;
	jal(R4);
	sinthiki_8:
	if(R3!=9)goto sinthiki_9;
	R1=0;
	
	printf("Exodos!\n");
	sinthiki_9:
	goto while_loop;
	epanalipsi:
	system("PAUSE");
	return (EXIT_SUCCESS);
	
}

void Menu(){
	printf("\n\nMENU\n\n");
	printf("1)Dhmiourgia listas\n");
	printf("2)Eisagwgh stoixeiou sto telos ths listas\n");
	printf("3)Diagrafh teleutaiou stoixeiou\n");
	printf("4)Ektypwsh sygkekrimenou stoixeiou\n");
	printf("5)Ektypwsh arithmou komvon\n");
	printf("6)Ektypwsh dieuthinshs sygkekrimenou
	stoixeiou\n");
	printf("7)Ektypwsh dieuthinshs listas\n");
	printf("8)Ektypwsh elaxistou komvou\n");
	printf("9)Exodos\n");
	printf("Dialexte apantish: ");
}

int CreateList(){
	R2=0;
	R9=1;
	struct list *ptr,*new_node;
	while_loop:
	if(R9>R10)goto f1;
	if(R2!=(int)NULL)goto f1_1;
	R8=(int)malloc(sizeof(struct list));
	ptr=(struct list*)R8;
	printf("Dwste timh: ");
	scanf("%hd",&R7);
	ptr->value=R7;
	R6=(int)NULL;
	printf("Dwse id: ");
	scanf("%d",&R5);
	ptr->id=R5;
	ptr->next=(struct list*)R6;
	R2=(int)ptr;
	R9++;
	f1_1:
	new_node=(struct list*)R2;
	R8=(int)malloc(sizeof(struct list));
	ptr=(struct list*)R8;
	printf("Dwste timh: ");
	scanf("%hd",&R7);
	
	ptr->value=R7;
	R6=(int)NULL;
	printf("Dwse id: ");
	scanf("%d",&R5);
	ptr->id=R5;
	ptr->next=NULL;
	while_label:
	if (!(new_node->next!=NULL))goto
	
	whileEnd;
	
	R8=(int)malloc(sizeof(struct
	
	list));
	
	R8=(int)new_node->next;
	new_node=(struct list *)R8;
	goto while_label;
	
	whileEnd:
	R8=(int)malloc(sizeof(struct list));
	R8=(int)ptr;
	new_node->next=(struct list *)R8;
	R4++;
	R9++;
	goto while_loop;
	f1:
	printf("H lista exei dhmiourgithei!\n");
	JR31;
}

int append()
{
	struct list *ptr;
	struct list *ptr2=(struct list*)R2;
	R8=(int)malloc(sizeof(struct list));
	ptr=(struct list*)R8;
	printf("Dwste timh:");
	scanf("\n%d",&R6);
	ptr->value=(short)R6;
	printf("Dwste id: ");
	scanf("%d",&R7);
	ptr->id=R7;
	ptr->next=NULL;
	while_loop:
	if (!(ptr2->next!=NULL))goto ifend;
	R8=(int)malloc(sizeof(struct list));
	R8=(int)ptr2->next;
	
	ptr2=(struct list *)R8;
	goto while_loop;
	ifend:
	R8=(int)malloc(sizeof(struct list));
	R8=(int)ptr;
	ptr2->next=(struct list *)R8;
	printf("The Element has been inserted to the list\n");
	R4++;
	JR31;
}

int deletelast(){
	struct list *ptr=(struct list *)R2;
	R6=R2;
	struct list *temp;
	if(R6!=(int)NULL) goto d2;
	printf("No elements\n");
	JR31;
	
	goto label_else;
	d2:
	while_loop:
	if(ptr->next==NULL)goto f2;
	temp=ptr;
	ptr=ptr->next;
	goto while_loop;
	
	f2:
	free(temp->next);
	temp->next=NULL;
	printf("The Element deleted Successfully\n");
	label_else:
	JR31;
}

int getNode(){
	struct list *ptr=(struct list *)R2;
	R6=R2;
	R8=1;
	printf("Enter node you want to see:\n");
	scanf("%d",&R7);
	while_label:
	if (R6==(int)NULL) goto telos;
	if(R8!=R7) goto if_else_label;
	
	printf("Number of id is:%d: ",ptr->id);
	printf("Price of value is:%d: \n",ptr-
	>value);
	JR31;
	if_else_label:
	R6=(int)ptr->next;
	ptr= (struct list *)R6;
	R8++;
	goto while_label;
	telos: printf("\nNode was not found\n");
	JR31;
}

int printCount(){
	struct list *ptr=(struct list*)R2;
	R31=0;
	while_label:
	if(ptr==NULL)goto f5;
	R31++;
	ptr=ptr->next;
	goto while_label;
	f5:
	printf("Length of List:%d",R31);
	JR31;
}

int printAddress(){
	struct list *ptr=(struct list*)R2;
	R30=1;
	R6=R2;
	printf("Enter the node you want to see its address: ");
	scanf("%d",&R31);
	while_loop:
	if(R6==(int)NULL)goto f6;
	if(R31!=R30)goto f6_1;
	printf("Address of the node is %x",R6);
	JR31;
	f6_1:
	R6=(int)ptr->next;
	ptr=(struct list*)R6;
	R30++;
	goto while_loop;
	f6:
	printf("\nNode was not found\n");
	JR31;

}

int printListAddress(){
	struct list *ptr=(struct list*)R2;
	R6=R2;
	if(R6==(int)NULL)goto f7;
	printf("Address of the list is %x",R2);
	JR31;
	f7:
	printf("\nList does not exist\n");
	JR31;
}

int printLowNode(){
	int minV,minI;
	struct list *ptr=(struct list*)R2;
	minV=ptr->value;
	minI=ptr->id;
	R31=0;
	while_label:
	if(ptr==NULL)goto f8;
	R31++;
	ptr=ptr->next;
	goto while_label;
	f8:
	ptr=(struct list*)R2;
	R28=0;
	while_label2:
	if(R28>=R31)goto else_;
	R28=R28+1;
	if(minV<ptr->value)goto else2;
	minV=ptr->value;
	minI=ptr->id;
	R27=(int)ptr;
	else2:
	ptr=ptr->next;
	goto while_label2;
	else_:
	printf("H mikroterh timh einai %d me id %d kai thesi
	%x",minV,minI,R27);
	JR31;
}