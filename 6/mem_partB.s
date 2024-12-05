.data
.globl cflag
.globl cdata
.globl newline
.globl menu
.globl str1
.globl str2
.globl False
.globl Terminate
cflag: .space 4
cdata: .space 4
newline: .asciiz "\n"
menu: .asciiz "\nMENU\n1)Choice 1\n2)Choice 2\n3)Exit Program\n"
str1: .asciiz "\nPicked Choice 1\n\n"
str2: .asciiz "\nPicked Choice 2\n\n"
str3: .asciiz "Type: "
False: .asciiz "\nWrong. Try again!\n"
Terminate: .asciiz "\nProgram terminated!\n"
.text
.globl main
main:
while_label:
mfc0 $t0,$12 #read status register
ori $t0,$t0,1 #read  enable interrupts
mtc0 $t0,$12 #read  status register
lw $t0, 0xffff0000
ori $t0,$zero,2
sw $t0,0xffff0000 #Store $a0 value 0xFFFF0000  to enable keyboard interrupt ;
li $v0, 4
la $a0, menu
syscall #print menu
li $v0,4
la $a0,str3 #print str3

syscall
data_loop:
la $t1,cflag
lw $a0,0($t1) #$a0=cflag
move $s1,$a0

beq $s1,0,data_loop #cflag == 1 means interrupt and loop is over.

la $t1,cdata
lw $a0,0($t1) #$a0=cdata
move $s2,$a0
 
beq $s2,51,loop_end # space(32)= program ends.
la $t1,cflag #Since we have the input in cdata, cflag has to be zero again.
la $a0,0($zero) #$a0=0
sw $a0,0($t1)
beq $s2,49,print_str1 #1(49) print str1
beq $s2,50,print_str2 #2(50) print str2
li $v0,4
la $a0, False #Wrong anser
syscall
j while_label
print_str1:
li $v0, 4 #Choice 1
la $a0, str1
syscall
j while_label
print_str2:
li $v0,4
la $a0,str2 #Choice 2
syscall
j while_label
loop_end:
li $v0, 4
la $a0, Terminate #Terminate
syscall
li $v0, 10
syscall