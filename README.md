# Digital Computers
 C,Clang,Assembly

# LAB 1 <br />
Linking C to behavior in specific material. Familiarity with the hexadeced representation. The project is specified for ordering elements in memory using pointers and arrays. 

# LAB 2 <br />
Familiarity with data management in memory and CLang language. A program is created for implementing a linked list of elements. An element contains two values (id,value). The program has a menu for insert/delete/search print operations in list. 

**Description in C** <br />
1)Creation of a list. <br />
2)Insert an element at the end of the list. <br />
3)Delete the first element of the list. <br />
4)Print a specific element of the list. <br />
5)Print the number of items in the list. <br />
6)Print the address of a specific item. <br />
7)Print the address of the list. <br />
8)Print a specific field address for a specific item. <br />
9)Print list sizes in bytes. <br />
10)Print data sizes in bytes. <br />
11)Exit. <br />

**Description in CLang** <br />
1)Creation of a list. <br />
2)Insert an element at the end of the list. <br />
3)Delete the first element of the list. <br />
4)Print a specific element of the list. <br />
5)Exit. <br />

The program is implemented in C and Clang. <br />

# LAB 3 <br />
Deepening the understanding of memory function in Clang and early understanding of Assembly. The program is an extension of its previous version. Its functionality is extended with function pointers. The functionality of menu operations is extended with some new modifications.  <br />

**Description in C** <br />
The size of the list is calculated correctly in bytes. It arises from the addresses occupied by the data and not by calculating the size of the hub by the number of nodes.

In addition, there is a new choice.
1)Print the address of each function.  <br />

**Description in CLang** <br />
Create all menu operations in LAB 2. Functions are called using function pointers.

**Description in Assembly** <br />
The menu is written. The option is printed repeatedly until the exit is selected.

The programs is created in C,Clang and some functionalities are created in Assembly.

# LAB 4
Deepening the understanding of Assembly. <br />

**New option in Clang** <br />
Print the list item with the lowest value. The location of the id and value is printed.

**Modifications in Clang** <br />
1)Creation of a list with a specific number of elements.  <br />
2)Delete the last element of the list.  <br />

**Description in Assembly** <br />
Clang program is convert to Assembly. <br />

1)The data is static. Space is created for 100 nodes. <br />
2)Separate function call using jal,jr commands after reading the data. <br />
3)The program knows by using a meter the number of items. <br />

The programs is created in Clang,Assembly. <br />

# LAB 5 <br />
Create recursive functions by using a data in Assembly. <br />
**Íew modification** <br />
1)Sort in increasing order <br />

Sorting is done using the merge algorithm. Recursion is done using stack.


The programs is created in Assembly.



#  LAB 6 <br />
# Polling <br />
Management of SPIM input/output devices, using the memory display of the units I/O, and using polling and using interrupts. <br />

Implementation of two functions write_ch,read_ch used for polling
Read a character from the keyboard and console. These functions are used and not syscall. The string from keyboard is transform to Capital Letters.

Need simulator settings for Mapped I/O. <br />

# Interrupts <br />
Implement simple menu of options that communicates with keyboard through interrupts. Communication with interrupt handler is done with cflag,cdata. The function of cflag is to show when the handler gave another character.

**Menu** <br />
Choice 1 <br />
Choice 2 <br />
Exit <br />
Activated with 1.2, space. Other characters are ignored. The message "Choise X is selected" appears.

Need simulator settings for Exception I/O. <br />


# How to Run <br /> 
Every project is run in appropriate platform (Devc++ for c,clang, Qspim for Assembly)