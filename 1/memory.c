/*
            ======================================================
            + Name        : memory.c                             +
            + Author      : Christos Z, 		                 +
            + Description : Materials stock                      +
            ======================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int var1 = 42;
int var2 = -1;
	
struct D{ //  structure D
	char x;
	int c;
	char y;
};
		
struct E{ //  structure E
	char x;
	char y;
	int c;
};

int main(){ 
	int A[10], i; /* A = array of 10 ints, i = scalar int variable */
	int *p; /* p is a scalar variable that points to an int */
	char a,b,c;
	char *m,*n,*o,*q;
	struct D struct_D;
	struct E struct_E;
	for (i = 0; i < 10; i++){ 
		A[i] = i; 
	}
	for(i = 0; i < 10; i++){
 		printf("Element A[%d] = %d is stored in address : %x\n", i, A[i], &A[i]);
 	}
	i=0;
	printf("%x %d\n",A,A);
	printf("%x %d\n",A+1,A+1);
	printf("%x %d\n",(((int) A) + 1),(((int) A) + 1));
	printf("%x %d\n", &(A[1]),&(A[1]));
	printf("%d\n",sizeof(A));
	printf("%d\n",sizeof(&A));
	printf("%d\t %d\t %d\n\n",&a,&b,&c);
	printf("%d %d\n",sizeof(struct_D),sizeof(struct_E));
	m=(char*)malloc(10*sizeof(char));
	n=(char*)malloc(10*sizeof(char));
	o=(char*)malloc(16*sizeof(char));
	q=(char*)malloc(32*sizeof(char));
	printf("%d %d %d %d\n\n",m,n,o,q); // Print the addresses of allocated memory
	printf("%x %x %x %x\n\n",main,&var1,&a,&m); // Print addresses of main function, var1, a, and 
    Sleep(10000);
 }
