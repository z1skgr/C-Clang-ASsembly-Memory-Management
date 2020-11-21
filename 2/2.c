******************ΚΩΔΙΚΑΣ ΣΕ C*****************************************
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
			head=CreateList(i);
			i++;
		}
		else if(answer==2){
			printf("Pliktrogiste timh: ");
			scanf("%d",&value);
			current=&head;
			append(current,value,i);
			i++;
		}
		else if(answer==3){
			assert(current!=NULL);
			deletefirst(&head);
		}
		else if(answer==4){
			assert(current!=NULL);
			printf("Pliktrologiste thesh: ");
			scanf("%d",&answer);
			getNode(head, answer);
		}
		else if(answer==5){
			assert(head!=NULL);
			printCount(head);
		}
		else if(answer==6){
			printf("Pliktrologiste ti thesi tou stoixeiou: ");
			scanf("%d",&answer);
			printNodeAddress(head,answer);
		}
		else if(answer==7){
			printListAddress(head);
		}
		else if(answer==8){
			printf("Pliktrologiste ti thesi tou stoixeiou: ");
			scanf("%d",&answer);
			printItemAddress(head,answer);
		}
		else if(answer==9){
			printListsize(head);
		}
		else if(answer==10){
			printItemsize(head);
		}
		else if(answer==11){
			flag=0;
			printf("Exodos programmatos!\n\n\n");
			printf("\n Created Linked list is: ");
			printList(head);
			assert(head!=NULL);
			freeList(head);
			system("\nPause");
		}
	else
		printf("Wrong answer!\n");
	}
}

void Menu(){ // ΤΟ ΜΕΝΟΥ ΕΠΙΛΟΓΩΝ
	printf("\n\nMENU\n\n");
	printf("1)Dhmiourgia listas\n");
	printf("2)Eisagwgh stoixeiou\n");
	printf("3)Diagrafh 1ou stoixeiou\n");
	printf("4)Ektypwsh sygkekrimenou stoixeiou\n");
	
	printf("5)Ektypwsh tou arithmou ton stoixeion tis listas\n");
	printf("6)Ektypwsh thesis sygkekrimenou stoixeiou\n");
	printf("7)Ektypwsh dieuthinsis listas\n");
	printf("8)Ektypwsh dieuthinsis sygkekrimenou pediou gia sygkekrimeno stoixeio\n");
	printf("9)Ektypwsh megethous listas\n");
	printf("10)Ektypwsh megethous stoixeiou\n");
	printf("11)Exodos\n\n");
	printf("Dialexte apantish: ");
}

struct list* CreateList(int i){
	struct list* ptr;
	ptr=(struct list*)malloc(sizeof(struct list));
	printf("Dwste timh: ");
	scanf(" %d",&ptr->value);
	ptr->id=i;
	ptr->next=NULL;
	printf("H lista exei dhmiourgithei!\n");
	return ptr;
}

void append(struct list** head, short new_data,int i)
{
	struct list* new_node = (struct list*) malloc(sizeof(struct list));
	struct list *last = *head;
	new_node->value = new_data; // προσθηκη κομβου στην λιστα
	new_node->id = i;
	new_node->next = NULL;
	if (*head == NULL) //ελεγχος αμα ειναι κενη η λιστα
	{
		*head=new_node;
	}
	while (last->next != NULL)
	last = last->next;
	last->next = new_node; //δομη επαναλψης ωστε να φτασουμε στον
} // τελευταιο κομβο


void deletefirst (struct list **head){ // ΔΙΑΓΡΑΦΕΙ ΠΡΩΤΟ ΣΤΟΙΧΕΙΟ
	struct list* temp = *head;
	if (*head != NULL)
	{
		*head = (*head)->next;
		free(temp);
	}
	printf("\nTo stoixeio diagrafike epithxws! ");
}

void getNode(struct list *head, int n) // ΕΠΙΛΕΓΕΙ ΕΝΑ ΣΥΓΚΕΚΡΙΜΕΝΟ
{ // ΣΤΟΙΧΕΙΟ ΑΠΟ ΤΗ ΛΙΣΤΑ
	int len = 1,i;
	struct list* temp=head;
	
	while (len!=n)
	{
		temp=temp->next;
		len++;
	}
	if(n<=len)
		printf("%d %d",temp->id,temp->value);
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
	printf("\nnLength of Linked List : %d",length);
}


void printNodeAddress(struct list* head, int n){
	struct list *temp = head;
	int len = 0,i;
	for (i = 1; i < n; i++)
		temp = temp->next;
	printf("Address of the %d node is: %d",n,temp);
}


void printListAddress(struct list* head){// ΤΥΠΩΝΕΙ ΤΗΝ ΔΙΕΥΘΗΝΣΗ ΤΗΣ ΛΙΣΤΑΣ
	printf("Address of the list is : %d",head);
}

void printItemAddress(struct list* head,int n){ //ΤΥΠΩΝΕΙ ΤΗΝ ΔΙΕΥΘΗΝΣΗ
	struct list *temp = head; / ΤΟΥ ΣΤΟΙΧΕΙΟΥ
	int i;
	int len = 0;
	for (i = 1; i <n; i++)
		temp = temp->next;
	
	printf("Epilexte pia apo tis dio dieuthinsis thelete na ektypwsete\n1-gia to address tou value\n2-gia to
	address to id\nDwste apanthsh: ");
	scanf("%d",&i);
	if(i==1)
		printf("Address of the %dth value is : %d",n,&temp->value);
	else if(i==2)
		printf("Address of the %dth id is : %d",n,&temp->id);

}


void printListsize(struct list *head){ //ΤΥΠΩΝΕΙ ΤΟ ΜΕΓΕΘΟΣ ΤΗΣ ΛΙΣΤΑΣ
	struct list *temp = head;
	int len = 1,s;
	while (temp->next!= NULL)	{
		temp = temp->next;
		len++;
	}
	printf("To megethos ths listas einai : %d",len*sizeof(struct list));
}

void printItemsize(struct list*head){
	printf("Size of the item is: %d\n", sizeof(head));
}

void freeList(struct list *node){
	struct list *tmp = node; //ΕΛΕΥΘΕΡΩΝΕΙ ΤΗΝ ΜΝΗΜΗ ΠΟΥ ΔΕΣΜΕΥΤΗΚΕ
	while(tmp != NULL){
		node = node->next;
		free(tmp);
		tmp = node;
	
	}
}

void printList(struct list *node) //ΤΥΠΩΝΕΙ ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΛΙΣΤΑΣ
{
	while (node != NULL)
	{
		printf(" %d\n", node->value);
		node = node->next;
	}
}