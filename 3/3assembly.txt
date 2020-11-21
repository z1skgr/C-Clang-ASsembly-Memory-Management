****************** ****ΚΩΔΙΚΑΣ ASSEMBLΥ************************************
.data
.globl str1
.globl str2
.globl str3
.globl str4
.globl str5
str1: .asciiz " 1) Create list" #δηλωση μεταβλητων
str2: .asciiz " 2) insert element at the end of the list"
str3: .asciiz "3)delete the first item of the list"
str4: .asciiz "4)print spesific item of the list"
str5: .asciiz "5) Exit"
askint: .asciiz "Type an integer : "
repint: .asciiz "your choice is : "
newline: .asciiz "\n"
.text
.globl main
main:
li $t2,5 #αρχικοποιηση μεταβλητων 0 για την επιλογη του χρηστη και 5 για την εξοδο
li $t1,0
loop: #το label για την επαναληψη

beq $t1,$t2,end # συνθηκη τερματισμου

li $v0, 4 #τυωνει ενα string
la $a0, str1
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 4
la $a0, str2
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 4
la $a0, str3
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 4
la $a0, str4
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 4
la $a0, str5
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 4
la $a0, askint
syscall

li $v0, 5 #εισαγωγη του χρηστη
syscall

move $t1,$v0

li $v0, 4

la $a0, repint
syscall

li $v0, 1
move $a0, $t1
syscall

j loop #εντολη να παει ξανα στο label της επαναληψης
end:
li $v0, 10 # εξοδος πτογραμματος
syscall