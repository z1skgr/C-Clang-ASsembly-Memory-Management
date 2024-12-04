.data
.globl str1
.globl str2
.globl str3
.globl str4
.globl str5
.globl str6
.globl str7
.globl str8
.globl str9
.globl str10
.globl str11
.globl str12
.globl exitLabel
.globl notFoundLabel
.globl array
.globl array2
.globl array3
.globl menu
menu: .asciiz "MENU"
str1: .asciiz "\n\n1)Create list\n2)Insert element at the end of the list\n3)Delete the first item
of the list\n4)Print spesific item of the list\n5)Print the number of elements\n6)Print address
of specific element\n7)Print table's address\n8)Print lowest element\n9)Sort
List\n10)Exit\n"
str2: .asciiz "Exit program"
str3: .asciiz "Give node number: "
str4: .asciiz "Give value: "
str5: .asciiz "Give id: "
str6: .asciiz "Give node to print its value & id: "
str7: .asciiz "Give node to print its address: "
str8: .asciiz "Element successfully deleted!\n"
str9: .asciiz "Value: "
str10: .asciiz "Id: "
str11: .asciiz "Address: "
str12: .asciiz "Node Count: "
str13: .asciiz "Sort List by Value:"
notFoundLabel: .asciiz "Node was not found"
exitLabel: .asciiz "Wrong .Try again!\n"
askint: .asciiz "Type an integer : "
repint: .asciiz "Your choice is : "
newline: .asciiz "\n"
array: .align 2
 .space 8*100

array2: .align 2
.space 4*100
array3: .align 2
.space 8*100

.text
.globl main
main:
li $s7,10
li $s6,0
li $v0, 4
la $a0, menu
syscall
loop:
beq $s6,$s7,end #choose an option
li $v0, 4
la $a0, str1 #menu
syscall
li $v0, 4
la $a0, askint #ask choice
syscall
li $v0, 5
syscall
jal Menu
li $v0, 10
syscall
#!!Functions!!
Menu:
move $s6,$v0 #s6=choice
li $v0, 4
la $a0, newline
syscall
bne $s6, 1 ,condition_1
la $s1, array
li $s2, 0
li $v0, 4 #Read message for nodes
la $a0, str3
syscall
li $v0, 5
syscall
move $s5, $v0 #choice for nodes in the list
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal CreateList #CreateList
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_1:
bne $s6, 2 , condition_2
la $s1, array
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal append
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_2:
bne $s6, 3 , condition_3
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal deleteLast
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_3:
bne $s6, 4 , condition_4
la $s1, array
li $v0, 4 #Read message for nodes to print value and id
la $a0, str6
syscall
li $v0, 5
syscall
move $s0,$v0 #s0 user's answer for nodes
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal getNode
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_4:
bne $s6, 5 , condition_5
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal count #printCount
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_5:
bne $s6, 6 , condition_6
li $v0, 4 #Print message to select the node to print its address
la $a0, str7
syscall
li $v0, 5 #Read input
syscall
move $s0,$v0 #s0 is wanted node
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal nodeAdd
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_6:
bne $s6, 7 , condition_7
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal tableAdd #print table's Address
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_7:
bne $s6, 8 , condition_8
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal Minimum #print node with the minimum value as its id & spot
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_8:
bne $s6, 9 , condition_9
addi $sp,$sp,-8
sw $s0,0($sp)
sw $ra,4($sp)
jal SortList
lw $s0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,4
j loop
condition_9:
bne $s6,10,condition_10;
li $v0, 4 #Exit
la $a0, str2
syscall
j loop
condition_10:
li $v0, 4 #Wrong answer s6>10 && s6<1
la $a0, exitLabel
syscall
j loop
end:
jr $ra
CreateList:
move $t2, $s2 #counter
move $t1, $s1 #array
move $a1 ,$s5 #node answer
f1_loop:
beq $t2,$a1, f1
li $v0, 4 #Print message to get value
la $a0, str4
syscall
li $v0, 5 #Read input
syscall
move $t5, $v0 #value t5
srl $t8, $t5, 4 #t8 holds the top byte
andi $t5, $t5, 0x000F #t5 hold the bottom byte
sb $t8,0($t1) #Store the bytes in the memory in the correct order
sb $t5,1($t1)
lb $t0,0($t1) #t0 holds the top byte
lb $t3,1($t1) #t3 holds the bottom byte
sll $t0, $t0, 4
or $t3, $t0, $t3
li $v0, 4
la $a0, str5 #Print message to get id
syscall
li $v0, 5 #Read id
syscall
move $t6, $v0 #id t6
li $t4,8 #t4=8 to jump to the next node
sw $t3,0($t1) #t5 = save value
sw $t6,4($t1) #t6 = save id
add $t1,$t1,$t4 #t1[i+8] to get to the next nodes
addi $t2,$t2,1 #counter+1
j f1_loop
f1:
move $s2,$t2 #update counter
jr $ra
append:
move $t2, $s2 #counter t2
move $t1, $s1 #array t1
li $t7,0
li $t4,8
f2_loop:
beq $t7,$t2,f2_end #t7 temp register to reach at the end of the list
add $t1,$t1,$t4 #t1=t1+8 to reach the node
addi $t7,$t7,1 #t7=t2 then we reach the end of the list
j f2_loop
f2_end:
li $v0, 4 #Print message to add value
la $a0, str4
syscall
li $v0, 5 #Read input
syscall
move $t5, $v0 #value t5
srl $t8, $t5, 4 #t8 holds the top byte
andi $t5, $t5, 0x000F #t5 hold the bottom byte
sb $t8,0($t1) #Store the bytes in the memory in the correct order
sb $t5,1($t1)
lb $t0,0($t1) #t0 holds the top byte
lb $t3,1($t1) #t3 holds the bottom byte
sll $t0, $t0, 4
or $t3, $t0, $t3
li $v0, 4
la $a0, str5 #Print msg for id
syscall
li $v0, 5 #Read id
syscall
move $t6, $v0 #id t6
sw $t5,0($t1) #store t1 with the value
sw $t6,4($t1) #store t1+4 with the id
addi $t2,$t2,1 #counter +1
add $t1,$t1,$t4 #update list
move $s2,$t2 #update counter
jr $ra
getNode:
move $t2, $s2 #counter
move $t1, $s1 #array
move $t7, $s0 #nth node number user's choice
addi $t7,$t7,-1
li $t4,0
li $t0,8
bge $t7,$t2,notFound_
f4_loop:
beq $t4,$t7,f4_end #try to find the nth node
add $t1,$t1,$t0
addi $t4,$t4,1 #end loop = we found nth node address
j f4_loop
f4_end:
li $t5,0 #t5 holds the value
li $t6,0 #t6 holds the id
lw $t5,0($t1) #t5 load value address
lw $t6,4($t1) #t6 load id address
li $v0, 4
la $a0, str9
syscall
li $v0, 1 #print value
move $a0, $t5
syscall
li $v0, 4 #/n
la $a0, newline
syscall
li $v0, 4
la $a0, str10
syscall
li $v0, 1
move $a0,$t6 #print id
syscall
jal $ra
notFound_:
li $v0, 4
la $a0, notFoundLabel
syscall
jr $ra
count:
move $t2,$s2 #t2 counter
li $v0, 4
la $a0, str12
syscall
li $v0, 1 #Print value count
move $a0, $t2
syscall
jr $ra
tableAdd:
move $t1,$s1 #t1 array
li $v0, 4
la $a0, str11
syscall
li $v0, 1
move $a0, $t1 #Show tables's address
syscall
jr $ra
nodeAdd:
move $t2, $s2 #counter
move $t1, $s1 #array
move $t7, $s0
addi $t7,$t7,-1
li $t4,0
li $t0,8
bge $t7,$t2, notFound
f6_loop: #loop to get the selected node
beq $t4,$t7,f6_end
add $t1,$t1,$t0
addi $t4,$t4,1 #end loop we reach node's address
j f6_loop
f6_end:
li $t5,0
move $t5,$t1 #t5=0($t1)
li $v0, 4
la $a0, str11
syscall
li $v0, 1 #print address
move $a0, $t5
syscall
li $v0, 4 #/n
la $a0, newline
syscall
jr $ra
notFound:
li $v0, 4
la $a0, notFoundLabel
syscall
jr $ra
deleteLast:
move $t2, $s2 #counter
move $t1, $s1 #array
li $t7,0
li $t4,8 #t4 is used to get to the next node
f3_loop:
beq $t7,$t2,f3_end #loop to reach the end of the node
add $t1,$t1,$t4
addi $t7,$t7,1 #end loop = empty space
j f3_loop
f3_end:
addi $t2,$t2,-1 #counter-1
addi $t1,$t1,-8 #we go the last node and clear its values
li $t5,0
sw $t5,0($t1) #store last node with null
sw $t5,4($t1)
move $s2,$t2 #update counter
li $v0, 4 #print succeessful msg
la $a0, str8
syscall
jr $ra
Minimum:
move $t1,$s1 #array
move $t2,$s2 #counter
move $t7,$t1
li $t5,0
lw $t3, 0($t1) #value
lw $t4, 4($t1) #id
f8_loop:
addi $t5,$t5,1 #t5==counter we reach the end of the list
lw $t7,0($t1) #t7=initiate min
blt $t3,$t7,f8_end
lw $t3,0($t1) #load min value on t3
lw $t4,4($t1) #load min id on t4
move $t6, $t1 #load min address on t6
f8_end:
addi $t1,$t1,8
bne $t5,$t2,f8_loop
li $v0, 4
la $a0, str9
syscall
li $v0, 1 #Print value of minimum element value
move $a0, $t3
syscall
li $v0, 4
la $a0, newline
syscall
li $v0, 4
la $a0, str10
syscall
li $v0, 1 #Print value of minimum element id
move $a0, $t4
syscall
li $v0, 4
la $a0, newline
syscall
li $v0, 4
la $a0, str11
syscall
li $v0, 1 #Print value of minimum element address
move $a0, $t6
syscall
jr $ra
SortList:
move $t2, $s2 #counter t2
move $t1, $s1 #array
la $t3,array2
li $a0,0
f9_loop:
beq $a0,$t2, f9_end
lw $t4,0($t1)
add $t1,$t1,8
sw $t4,0($t3)
addi $t3,$t3,4
addi $a0,$a0,1
j f9_loop
f9_end:
la $a0, array2 # Load the start address of the array
move $t0, $t2 # Load the array length
sll $t0, $t0, 2 # Multiple the array length by 4 (the size of the elements)
add $a1, $a0, $t0 # Calculate the array end address
jal mergeSorting # Call the merge sort function
li $v0, 4
la $a0, str13
syscall
li $t0, 0 # Initialize temp index
la $a0,newline
li $v0,4
syscall
print:
move $t1,$s2 # Load the array length
bge $t0,$t1,printEnd # End of the array means that our list is
sorted and printed
mul $t2,$t0,4
addi $t0,$t0,1 # Increase the temp counter
la $t3,array2($t2)
lw $a0,0($t3) # Get the value pointed to and store it for printing
li $v0,1
syscall # Print the value
la $a0,newline
li $v0,4
syscall
j print # Go to print again to print the next value
printEnd:
move $t1,$s1 #Load the address of array
la $t2,array2 #Load the address of array2 with values sorted
la $t3,array3 #Load the address of the array3 to store values and ids sorted
li $t9,0
lw $t5,0($t1)
move $t6,$s2
li $t7,0
while_loop: #Search values on the array to find id of the sorted
values on array2
beq $t7,$t6,endEq
lw $t4,0($t2) #Load on t4 sequence value to get if for search
bne $t4,$t5,endIf
lw $t8,4($t1) #lw id on t8
sw $t8,4($t3) #sw id on t3 #Store id on array3
sw $t4,0($t3) #sw value one t3 #Store value on array3 with the proper
sequence
addi $t4,$t4,'0'
sw $t4,0($t1)
addi $t3,$t3,8 #Increase address of array3
addi $t7,$t7,1 #Increase address of the temp counter
addi $t2,$t2,4 #Increase address of the array2
mul $t0,$t9,8 #Mul to adjust array to search the array from the beginning
sub $t1,$t1,$t0 #Sub to adjust
lw $t5,0($t1) #Load the start value
li $t9,0 #Adjust counter
j while_loop
endIf: #Value not found this moment
add $t9,$t9,1 #Increase counter
add $t1,$t1,8 #Increase the address of the array
lw $t5,0($t1) #Load word the next value
j while_loop
endEq:
move $t1,$s1 #Store the sorted values from array3 to array
la $t3,array3
li $t7,0
move $t2,$s2
while_label:
beq $t7,$t2,f9End #Loop
lw $t4,0($t3) #Load value from array3
lw $t5,4($t3) #Load id from array3
sw $t4,0($t1) #Store value & id on array
sw $t5,4($t1)
addi $t1,$t1,8 #Load addresses for the array &array3
addi $t3,$t3,8
addi $t7,$t7,1
j while_label
f9End:
j loop #Return to menu
mergeSorting:
li $t5,16
sub $sp, $sp, $t5
addi $sp,$sp,8
sw $a1, 0($sp) # Store addresses (end,start & return)
sw $a0, -4($sp)
sw $ra, -8($sp)
addi $sp,$sp,-8
sub $t0, $a1, $a0 # Calculate the difference between the start and end
address (i.e. number of elements * 4)
ble $t0, 4, FinishMerge # Only one element means that our array is divided into
pieces
div $t0, $t0, 8
mul $t0, $t0, 4
add $a1, $a0, $t0
addi $sp,$sp,8
sw $a1, 4($sp)
addi $sp,$sp,-8
jal mergeSorting # Call function (first half of the array-recursive call)
addi $sp,$sp,8
lw $a0, 4($sp) #Load end-mid addreesses(Emid is used to help us with the
merge)
lw $a1, 0($sp)
addi $sp,$sp,-8
jal mergeSorting # Call function (second half of the array -recursive call)
addi $sp,$sp,8
lw $a0, -4($sp) # Load array addresses(start-end-middle(middle is not
necessery address but helpful)
lw $a2, 0($sp)
lw $a1, 4($sp)
addi $sp,$sp,-8
jal merge # Merging
FinishMerge:
li $t5,16
lw $ra, 0($sp) # Load the return address
add $sp, $sp, $t5 # Reload the stack pointer
jr $ra # Return 
merge:
sub $sp, $sp, $t5 # Reload stack pointer
addi $sp,$sp,8
sw $a0,-4($sp)
sw $ra, -8($sp) # Store the return address
sw $a2, 4($sp) # Store addresses(end-middle-return)
sw $a1, 0($sp) # Store the midpoint address
addi $sp,$sp,-8
move $s6, $a1 # Temporary copy for the second half
move $s5, $a0 # Temporary copy for the first half
merging:
lw $t0, 0($s5) # Load the first half
lw $t1, 0($s6) # Load the second half
bgt $t1, $t0, noChange # If the lower value is already first means the value is in the
right spot for the sort
move $a0, $s6 # Load the argument for the element
move $a1, $s5 # Load the argument for the address
jal Change # Shift the element to the new position
addi $s6, $s6, 4 # Increase the second half counter
noChange:
addi $s5, $s5, 4 # Increase the first half counter
addi $sp,$sp,8
lw $a2, 4($sp) # Reload the end address
addi $sp,$sp,-8
bge $s5, $a2, FinishMerge # End the loop when both halves are empty
bge $s6, $a2, FinishMerge
j merging
Change:
li $t0, 4
ble $a0, $a1,changeEnd # If we are at the location, stop shifting
sub $t6, $a0, $t0 # Find the previous address in the array
lw $t7, 0($a0) # Get successive pointers and save one to another
lw $t8, 0($t6)
sw $t7, 0($t6)
sw $t8, 0($a0) # Save the previous pointer to the current address
move $a0, $t6
b Change # Loop
changeEnd:
jr $ra