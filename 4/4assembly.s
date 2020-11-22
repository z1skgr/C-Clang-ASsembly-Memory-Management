*************************ASSEMBLY***************************
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
.globl menu
menu: .asciiz "MENU"
str1: .asciiz "\n\n1)Create list\n2)Insert element at
the end of the list\n3)Delete the first item of the
list\n4)Print spesific item of the list\n5)Print the
number of elements\n6)Print address of specific
element\n7)Print table's address\n8)Print lowest
element\n9)Exit\n"
str2: .asciiz "Exodos programmatos"
str3: .asciiz "Dwse arithmo komvon: "
str4: .asciiz "Dwse value: "
str5: .asciiz "Dwse id: "
str6: .asciiz "Dwse komvo pou thes na extypwseis value &
id: "
str7: .asciiz "Dwse komvo pou thes na ektypwseis
dieuthinsi: "
str8: .asciiz "To stoixeio diagrafthike epithxws!\n"
str9: .asciiz "Value: "
str10: .asciiz "Id: "
str11: .asciiz "Address: "
str12: .asciiz "Node Count: "
notFoundLabel: .asciiz "Node was not found"
exitLabel: .asciiz "Lathos epilogh.Xanaprospathiste!\n"
askint: .asciiz "Type an integer : "
repint: .asciiz "Your choice is : "
newline: .asciiz "\n"
array: .align 2
.space 8*100
.text
.globl main
main:
li $s7,9
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
move $s6,$v0 #s6=choice
li $v0, 4
la $a0, newline
syscall
bne $s6, 1 ,sinthiki_1
la $s1, array
li $s2, 0
li $v0, 4 #Read message for nodes
la $a0, str3
syscall
li $v0, 5
syscall
move $s5, $v0 #choice for nodes in the list
jal CreateList #CreateList
j loop
sinthiki_1:

bne $s6, 2 , sinthiki_2
la $s1, array
jal append
j loop
sinthiki_2:

bne $s6, 3 , sinthiki_3
jal deleteLast
j loop

sinthiki_3:
bne $s6, 4 , sinthiki_4
la $s1, array
li $v0, 4 #Read message for nodes to print value
and id
la $a0, str6
syscall
li $v0, 5
syscall
move $s0,$v0 #s0 h apantish p exei dwsei gia tous
komvous
jal getNode
j loop
sinthiki_4:
bne $s6, 5 , sinthiki_5
jal count #printCount
j loop
sinthiki_5:
bne $s6, 6 , sinthiki_6
li $v0, 4 #Print message to select the node to
print its address
la $a0, str6
syscall
li $v0, 5 #Read input
syscall
move $s0,$v0 #s0 is wanted node
jal nodeAdd
j loop
sinthiki_6:
bne $s6, 7 , sinthiki_7
jal tableAdd #print table's Address
j loop
sinthiki_7:
bne $s6, 8 , sinthiki_8
jal Minimum #print node with the minimum
value as its id & spot
j loop
sinthiki_8:

bne $s6, 9 , sinthiki_9
li $v0, 4 #Exit
la $a0, str2
syscall
j loop
sinthiki_9:
li $v0, 4 #Minima gia lathos apantish s6>9 && s6<1
la $a0, exitLabel
syscall
j loop
end:
li $v0, 10
syscall

#!!Functions!!
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
li $v0, 4
la $a0, str5 #Print message to get id
syscall
li $v0, 5 #Read id
syscall
move $t6, $v0 #id t6

li $t4,8 #t4=8 to jump to the next node
sw $t5,0($t1) #t5 = save value
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
beq $t7,$t2,f2_end #t7 temp register to reach at the
end of the list
add $t1,$t1,$t4 #t1=t1+8 to reach the node
addi $t7,$t7,1 #t7=t2 then we reach the end of the
list
j f2_loop
f2_end:
li $v0, 4 #Print message to add value
la $a0, str4
syscall
li $v0, 5 #Read input
syscall
move $t5, $v0 #value t5
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

addi $t1,$t1,-8 #we go the last node and clear its
values
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
addi $t5,$t5,1 #t5==counter we reach the end of the
list
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