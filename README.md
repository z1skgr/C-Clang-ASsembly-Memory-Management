# Digital Computers
> Μemory management at programming levels (high-> mid -> low (Assembly)) 

 ## Table of contents
* [Labs](#labs)
   * [1](#1)
   * [2](#2)
   * [3](#3)
   * [4](#4)
   * [5](#5)
   * [6](#6) 
* [How to run](#how-to-run)

## Labs

### 1
Memory management and data structures
* Hexadeced representation. 
* Ordering elements in memory using pointers and arrays. 
* Structs declaration
   * 2 structs with different variable content
* Dynamic memory allocation 
* Μemory use map

<br><br><br><br><br><br><br><br><br><br>


### 2
Structure management in memory using linked data list operations.
#### C
Menu for the options 
* Create List
* Insert Element
    * (id, value)
* Delete First
* Print 
    * Address/Value element
    * List count
    * List address
    * Address element field
    * List size (bytes)
    * Element size (bytes)


#### CLang
* Create List
* Insert Element
    * (id, value)
* Delete First
* Print element value
<br><br><br><br><br><br><br><br><br><br>

### 3
Deepening the understanding of memory function in Clang/understanding of Assembly
#### C
New operation
 * Print function address
 * Calculate list size to bytes from addresses that occupy items


#### CLang
Conversion of all the variables used in c
Menu for the options using standards (reference registers, etc)
* Create List
* Insert Element
    * (id, value)
* Delete First
* Print 
    * Address/Value element
    * List count
    * List address
    * Address element field
    * List size (bytes)
    * Element size (bytes)

#### Assembly
Menu options (no functionality)
<br><br><br><br><br><br><br><br><br><br>
### 4 
Deepening the understanding of Clang/Assembly
#### CLang
Modification from previous implementation
* Create finite list
* Delete Last
* Print element with minimum value

#### Assembly

* 100 nodes on list (static array)
* Correctness of assembly contracts
* Menu functionality (#3)
* Jal commands for call functions
<br><br><br><br><br><br><br><br><br><br>
### 5
#### Assembly
Modification from previous implementation
* Ascending sort using ***recursive*** Merge sort [^1]
    * Stack emerged
<br><br><br><br><br><br><br><br><br><br>
* Convert values from type int -> short
### 6
#### Assembly
##### Polling
##### Interrupts
* Menu options for keyboard using interrupts
    * cflag, cdata for handler



**Menu** <br />
Choice 1 <br />
Choice 2 <br />
Exit <br />
Activated with 1.2, space. Other characters are ignored. The message "Choise X is selected" appears.




<br><br><br><br><br><br><br><br><br><br>
## How to run 
### C
### C-lang
### Assembly

#### Interrupts
Need simulator settings for Exception I/O. <br />









#  LAB 6 
# Polling <br />
Management of SPIM input/output devices, using the memory display of the units I/O, and using polling and using interrupts. <br />

Implementation of two functions write_ch,read_ch used for polling
Read a character from the keyboard and console. These functions are used and not syscall. The string from keyboard is transform to Capital Letters.

Need simulator settings for Mapped I/O. <br />

# Interrupts <br />



[^1]: https://en.wikipedia.org/wiki/Merge_sort#:~:text=In%20computer%20science%2C%20merge%20sort%20%28also%20commonly%20spelled,was%20invented%20by%20John%20von%20Neumann%20in%201945.
