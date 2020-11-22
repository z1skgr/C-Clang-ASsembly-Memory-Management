*************************ASSEMBLY***************************
data
.globl str1
.globl newline
str1: .asciiz "Diavase string: "
str2: .asciiz "To zhtoumeno string einai: "
newline: .asciiz "\n"
strArray:.space 100
.text
.globl main
main:
la $a0,str1 #Ektypwnonte minhmata
jal print_str
la $a0, strArray #fortonete sto $a0 h dieuthinsi to pinaka
jal write_str
la $a0,newline
jal print_str
li $t0,0 #vazoume timh 0 wste molis bei sto convertion na tsekarei to 1o stoixeio
li $s0,1
li $s1, 97 #h timh sto ascii gia to a
li $s2, 122 #h timh sto ascii gia to z
convertion:
beq $s0, 0, convertionEnd
lb $s0,strArray($t0) #fortonoume to memory location sto $s0 tou pinaka
blt $s0,$s1,Noconv
bgt $s0,$s2,Noconv #an to gramma einai kefalaio pigenoume ston
epomeno xarakthra
addi $s0, $s0, -32 #metatropi tou grammatos se kefalaio.An einai
kefalaio dn ginete tipota
sb $s0, strArray($t0) #store to tropopoihmeno gramma ston pinaka
addi $t0,$t0,1
j convertion #jump sto conversion
Noconv:
addi $t0,$t0,1
j convertion
convertionEnd:
la $a0,str2 #Ektypwnoume ta katallhla minimata
jal print_str
la $a0,strArray
jal print_str
li $v0,10 # Exodos programmatos
syscall
write_ch:
lw $t0,0xffff0008 #diavazei ton transmitter control
and $t0,$t0,0x00000001 #logiko and autou pou diavazei apo to transmitter
control me to 1 elegxontas to LSB xrhsimopoiontas maska me to 0x00000001
beq $t0,$zero,write_ch
sw $a0,0xffff000c #ekxwrei sto $a0 thn timh tou transmitter data
jr $ra
read_ch:
lb $t0,0xffff0000 #diavazoume ton receiver control
and $t0,$t0,0x00000001 # elegxoume to LSB pou einai to ready bit.An einai 1
to ready bit tote kanoume lb ton receiver data
beq $t0,$zero,read_ch
lb $v0,0xffff0004 #fortonoume sto $v0 ton receiver data
jr $ra
print_str:
move $s1, $a0
addi $sp, $sp, -4 # Desmeush mnhmhs sto Stack gia na gnorizoume ti thesi
mnhmhs sth main
sw $ra, 0($sp)
add $t0, $zero, $s1 #metrhths gia n synexizoume stous epomenous xarakthres
move $t6,$t0
print_ch:
lb $a0 , 0($t6) # fortonoume sto $a0 , ton xarakthra p theloume n ektypwsoume
jal write_ch
beq $a0,10,afterPrint
beq $a0,0,afterPrint # elenxos gia an to stoixeio einai kenos xaraktiras h \n
addi $t6,$t6,1 #auxanoume ton metrhth gia n proxoroume se neous xarakthres
j print_ch
afterPrint:
lw $ra, 0($sp)
addi $sp, $sp, 4 # Apodesmeush mnhmhs apo to Stack gia na girizoume sth
dieuthinsi p thn kalese
jr $ra
write_str:
addi $sp,$sp,-4 #dhmiourgoume xwro sto stack
sw $ra, 0($sp) #apothikeuoume sto stack to $ra gia na gnorizoume
ti dieuthinsi opou kalestike h write_str
li $t5, 0 #metritis gia na proxorame ton pinaka
jal read_ch #pigenoume stin read_ch .Diavazete xarakthras
write_character:
beq $v0,0, afterWrite #elegxoume an o xarakthras einai to enter h \n
.Alliws termatismos
beq $v0,10, afterWrite
sb $v0, strArray($t5) #store sto $v0 to memory location to xarakthra
addi $t5, $t5,1 # t5=t5+1 gia n pame ston epomeno xarakthra
move $a0, $v0 #pername sto $a0 to periexomeno tou $v0 gia na
kalesoume th synarthsh write_ch vlepontas etsi sti konsola ka8e fora ti grafoume
jal write_ch #vlepoume sthn konsola kathe fora ti grafoume
jal read_ch #loop mexri n vroume \n h
enter
j write_character
afterWrite:
lw $ra, 0($sp) #diavazoume apo t stack thn timh dieuthinsis klisis
addi $sp, $sp, 4 #apodesmeuoume to stack
jr $ra #epistrefoume sth dieythynsi klisis