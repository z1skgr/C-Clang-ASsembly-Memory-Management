.data
.globl str1
.globl newline
str1: .asciiz "Read string: "
str2: .asciiz "Give string: "
newline: .asciiz "\n"
strArray:.space 100
.text
.globl main
main:
la $a0,str1 #Print messages
jal print_str
la $a0, strArray #Load $a0 table address
jal write_str
la $a0,newline
jal print_str
li $t0,0 #value 0 so as soon as the gets to the convertion to check 1st element
li $s0,1
li $s1, 97 #ascii a
li $s2, 122 #ascii z
convertion:
beq $s0, 0, convertionEnd
lb $s0,strArray($t0) #Load memory location to $s0 table
blt $s0,$s1,Noconv
bgt $s0,$s2,Noconv #CAPS go to next character
addi $s0, $s0, -32 #Convert letter to CAPS
sb $s0, strArray($t0) #Store modified char to table 
addi $t0,$t0,1
j convertion #jump to conversion
Noconv:
addi $t0,$t0,1
j convertion
convertionEnd:
la $a0,str2 #Print messages
jal print_str
la $a0,strArray
jal print_str
li $v0,10 # Exit program
syscall
write_ch:
lw $t0,0xffff0008 #Read transmitter control
and $t0,$t0,0x00000001 #LOGIGAL AND with transmitter control and 1 checking LSB using MASK with 0x00000001
beq $t0,$zero,write_ch
sw $a0,0xffff000c #Set $a0 value of transmitter data
jr $ra
read_ch:
lb $t0,0xffff0000 #Read receiver control
and $t0,$t0,0x00000001 # Check LSB - ready bit. 1-> ready bit then make lb receiver data
beq $t0,$zero,read_ch
lb $v0,0xffff0004 #Load $v0 receiver data
jr $ra
print_str:
move $s1, $a0
addi $sp, $sp, -4 # Allocate memory on stack to identify the state of the memory in main
sw $ra, 0($sp)
add $t0, $zero, $s1 #Counter to continue to next characters
move $t6,$t0
print_ch:
lb $a0 , 0($t6) # Load $a0 , character we want to print
jal write_ch
beq $a0,10,afterPrint
beq $a0,0,afterPrint # Check element to be space or \n
addi $t6,$t6,1 #Update counter to go to next characters
j print_ch
afterPrint:
lw $ra, 0($sp)
addi $sp, $sp, 4 # Deallocate memory from stack to go back to the called address
jr $ra
write_str:
addi $sp,$sp,-4 #Space in stack
sw $ra, 0($sp) #Store to stack to $ra to know the address who called the write_str ti dieuthinsi opou kalestike h write_str
li $t5, 0 #Counter to go on to the table
jal read_ch #Go to read_ch . Read character
write_character:
beq $v0,0, afterWrite #Check if character is enter or \n. Else terminate
beq $v0,10, afterWrite
sb $v0, strArray($t5) #store  $v0  memory location of character
addi $t5, $t5,1 # t5=t5+1 go to next character
move $a0, $v0 #go to  $a0 the content of $v0 to call function write_ch. Console every time displays what we write
jal write_ch 
jal read_ch #loop until find \n or enter
j write_character
afterWrite:
lw $ra, 0($sp) #Read from stack the address called
addi $sp, $sp, 4 #Deallocate stack
jr $ra #Return at called address