**************************ΚΩΔΙΚΑΣ ΣΕ C*************************************
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list{

	short value;
	int id;
	struct list *next;

};

void Menu();
int CreateList(int i);
void append(struct list** head_ref, short new_data,int i);
void deletefirst (struct list **head);
void printCount(struct list*head);
void getNode(struct list *head, int n);
void printNodeAddress(struct list* head, int n);
void printListAddress(struct list* head);
void printItemAddress(struct list* head,int n);
void printListsize(struct list *head);
void printItemsize(struct list*head);

void printList(struct list*);
void freeList(struct list *node);
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
	
	printf("Welcome to the program!!\n\n");
	while(flag){
	Menu();
	scanf("%d",&answer);
	if(answer==1){
	
		fptr1=&CreateList;;
		head=(struct list*)(*fptr1)(i);
		i++;
	
	}
	else if(answer==2){
	
		printf("Pliktrogiste timh: ");
		scanf("%d",&value);
		current=&head;
	
		fptr2=&append;
		(*fptr2)(current,value,i);
	
		i++;
	
	}
	else if(answer==3){
	
		assert(current!=NULL);
		fptr3=&deletefirst;
		(*fptr3)(&head);
	
	}
	else if(answer==4){
	
		assert(current!=NULL);
		printf("Pliktrologiste thesh: ");
		scanf("%d",&answer);
		fptr4=&getNode;
		(*fptr4)(head,answer);
	
	}
	else if(answer==5){
	
		assert(head!=NULL);
		fptr5=&printCount;
		(*fptr5)(head);
	
	}
	else if(answer==6){
	
		printf("Pliktrologiste ti thesi tou stoixeiou:
	");
	
		scanf("%d",&answer);
		fptr4=&printNodeAddress;
		
		(*fptr4)(head,answer);
	
	}
	else if(answer==7){
	
		fptr5=&printListAddress;
		(*fptr5)(head);
	
	}
	else if(answer==8){
	
		printf("Pliktrologiste ti thesi tou stoixeiou:
	
	");
	
		scanf("%d",&answer);
		fptr4=&printItemAddress;
		(*fptr4)(head,answer);
		
	}
	else if(answer==9){
	
		fptr5=&printListsize;
		(*fptr5)(head);
	
	}
	else if(answer==10){
	
		fptr5=&printItemsize;
		(*fptr5)(head);
	
	}
	else if(answer==11){
		flag=0;
		printf("Exodos programmatos!\n\n\n");
		printf("\n Created Linked list is: \n");
	
		fptr5=&printList;
		(*fptr5)(head);
		assert(head!=NULL);
	
		fptr5=&freeList;
		(*fptr5)(head);
	
		system("\nPause");
	
	}
	else if(answer==12){
	
		printf("Dieuthinseis synarthseon: \n");
		printf("%p\n",CreateList);
		printf("%p\n",append);
		printf("%p\n",deletefirst);
		printf("%p\n",getNode);
		printf("%p\n",printCount);
		printf("%p\n",printNodeAddress);
		printf("%p\n",printListAddress);
		printf("%p\n",printItemAddress);
		printf("%p\n",printListsize);
		printf("%p\n",printItemsize);
		printf("%p\n",printList);
		printf("%p\n",freeList);
	
	}
	else
	
		printf("Wrong answer!\n");
	
	}

}

void Menu(){ // menu choice

	printf("\n\nMENU\n\n");
	printf("1)Dhmiourgia listas\n");
	
	printf("2)Eisagwgh stoixeiou\n");
	printf("3)Diagrafh 1ou stoixeiou\n");
	printf("4)Ektypwsh sygkekrimenou stoixeiou\n");
	printf("5)Ektypwsh tou arithmou ton stoixeion tis listas\n");
	printf("6)Ektypwsh thesis sygkekrimenou stoixeiou\n");
	printf("7)Ektypwsh dieuthinsis listas\n");
	printf("8)Ektypwsh dieuthinsis sygkekrimenou pediou gia
	
	sygkekrimeno stoixeio\n");
	
	printf("9)Ektypwsh megethous listas\n");
	printf("10)Ektypwsh megethous stoixeiou\n");
	printf("11)Exodos\n");
	printf("12)Ektypwsh dieuthinsewn synarthsewn\n\n");
	printf("Dialexte apantish: ");

}

int CreateList(int i){ // creation of the list

	struct list* ptr;
	
	ptr=(struct list*)malloc(sizeof(struct list));
	printf("Dwste timh: ");
	scanf(" %d",&ptr->value);
	ptr->id=i;
	ptr->next=NULL;
	printf("H lista exei dhmiourgithei!\n");
	return (int)ptr;

}

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

void deletefirst (struct list **head){ // delete frist node

	struct list* temp = *head; // of the list
	if (*head != NULL)	
	{
		*head = (*head)->next;
		free(temp);
	}
	
	printf("\nTo stoixeio diagrafike epithxws! ");

}

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
		printf("To stoixeio exei id=%d & value=%d",temp->id,temp->value);
	else
		printf("Shorter linked list");

}

void printCount(struct list* head){
	struct list *temp;
	int length = 0;
	temp = head;
	while(temp!=NULL)
	{
		length++;
		temp=temp->next;
	}
	printf("\nTo megethos ths listas : %d",length);
}

void printNodeAddress(struct list* head, int n){
	
	struct list *temp = head;
	int len = 0,i;
	
	for (i = 1; i < n; i++)
		temp = temp->next;
	
	printf("Address of the %d node is: %d",n,temp);

}

void printListAddress(struct list* head){

	printf("Address of the list is : %d",head);

}

void printItemAddress(struct list* head,int n){

	struct list *temp = head;
	int i;
	int len = 0;
	
	for (i = 1; i <n; i++)
		temp = temp->next;
	
	printf("Epilexte pia apo tis dio dieuthinsis thelete na ektypwsete\n1-
	gia to address tou value\n2-gia to address to id\nDwste apanthsh: ");
	scanf("%d",&i);
	if(i==1)
		printf("Address of the %dth value is : %d",n,&temp->value);
	else if(i==2)
		printf("Address of the %dth id is : %d",n,&temp->id);
}

void printListsize(struct list *head){
	struct list *temp = head;
	int sum;
	
	while (temp->next!= NULL)	
	{
		temp = temp->next;
	}
	sum=(int)temp-(int)head;
	
	printf("To megethos ths listas einai : %d",sum);

}

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

void freeList(struct list *node){
	struct list *tmp = node;
	
	while(tmp != NULL){
	
		node = node->next;
		free(tmp);
		tmp = node;
	
	}
}

void printList(struct list *node)
{
	while (node != NULL)
	{
		printf(" %d\n", node->value);
		node = node->next;

	}
}