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
Management of input/output devices, using the memory display of the units I/O
##### Polling
Checking peripheral devices if they are ready to accept/export data without syscall (*write_ch,read_ch*).


* write_ch - 
* read_ch - Save character
* print_str - Pass characters for printing

| Functions | |
| :---: | :---: | 
| write_ch | Reads register / Check preparation of device (checkcross instruction and register value LSB) |
| read_ch | |
| print_str | Check string character per character




##### Interrupts
| Menu | 
| :---: | 
| Choice #1 |
| Choice #2 |
| Exit |

Menu options for keyboard using interrupts
    * cflag, cdata for handler

<br><br>
> Choice 1 for 1 
> Choise 2 for 2
> Exit for space.
>  Message appears 

Exception file
```
lui $k1 0xFFFF
lw  $k0 4($k1)

la $t1, cdata
sw $k0,0($t1)
la $t1, cflag
addi $k0, $zero,1
sw $k0,0($t1)
```



<br><br><br><br><br><br><br><br><br><br>
## How to run 
### C
### C-lang
### Assembly


#### Polling 
Need simulator settings for Mapped I/O. <br />
#### Interrupts
Need simulator settings for Exception I/O. 
* On SPIM go to Simulator->Settings
* Select Mapped I/O













[^1]: https://en.wikipedia.org/wiki/Merge_sort#:~:text=In%20computer%20science%2C%20merge%20sort%20%28also%20commonly%20spelled,was%20invented%20by%20John%20von%20Neumann%20in%201945.
