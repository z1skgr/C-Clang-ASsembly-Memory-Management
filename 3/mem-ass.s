.data
.globl str1
.globl str2
.globl str3
.globl str4
.globl str5
str1: .asciiz "\n1)Create list" #Declare functions
str2: .asciiz "2)Insert element at the end of the list"
str3: .asciiz "3)Delete the first item of the list"
str4: .asciiz "4)Print spesific item of the list"
str5: .asciiz "5)Exit\n"
askint: .asciiz "Type an integer : "
repint: .asciiz "your choice is : "
newline: .asciiz "\n"
.text
.globl main
main:
li $t2,5 #initialize variable 0-5 for menu
li $t1,0
loop: #label for repeat

beq $t1,$t2,end # Terminate program

li $v0, 4 #print string
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

li $v0, 5 #user input
syscall

move $t1,$v0

li $v0, 4

la $a0, repint
syscall

li $v0, 1
move $a0, $t1
syscall

j loop #go to label
end:
li $v0, 10 # exit program
syscall