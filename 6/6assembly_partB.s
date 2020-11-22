*************************ASSEMBLY***************************
# Code for interrupt in EXCEPTION
lui $k1, 0xFFFF # 0xFFFF0000=k1
lw $k0 4($k1) # pernoume to xarakthra p eisaxthike apo to  Receiver Data

la $t1,cdata #cdata =xarakthras
sw $k0,0($t1)

la $t1,cflag #cflag = 1
addi $k0,$zero,1 #$k0=1
sw $k0,0($t1) 


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
menu: .asciiz "\nMENU\n1)Epilogi 1\n2)Epilogi 2\n3)Exit Program\n"
str1: .asciiz "\nDialexate thn Epilogi 1\n\n"
str2: .asciiz "\nDialexate thn Epilogi 2\n\n"
str3: .asciiz "Type: "
False: .asciiz "\nLathos epilogh.Xanadokimaste!\n"
Terminate: .asciiz "\nTermatismos programmatos!\n"
.text
.globl main
main:
while_label:
mfc0 $t0,$12 #diavazoume apo ton status register
ori $t0,$t0,1 #energopoioume ta enable interrupts
mtc0 $t0,$12 #diavazoume ston status register
lw $t0, 0xffff0000
ori $t0,$zero,2
sw $t0,0xffff0000 #kanoume store sto $a0 to 0xFFFF0000 gia na ennergopoihsoume to
enable keyboard interrupt ;
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

beq $s1,0,data_loop #cflag == 1 shmenei oti exoume interrupt kai teleiwnei to loop.

la $t1,cdata
lw $a0,0($t1) #$a0=cdata
move $s2,$a0
 
beq $s2,32,loop_end # space(32)= teleiwnei to programma.
la $t1,cflag #Since we have the input in cdata, cflag has to be zero again.
la $a0,0($zero) #$a0=0
sw $a0,0($t1)
beq $s2,49,print_str1 # 1(49) ektypwnoume to str1
beq $s2,50,print_str2 #2(50) ektypwnoume to str2
li $v0,4
la $a0, False #alliws exei dwthei lathos apantisei
syscall
j while_label
print_str1:
li $v0, 4 #Epilogh 1
la $a0, str1
syscall
j while_label
print_str2:
li $v0,4
la $a0,str2 #Epilogh 2
syscall
j while_label
loop_end:
li $v0, 4
la $a0, Terminate #Exodos programmatos
syscall
li $v0, 10
syscall