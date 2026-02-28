# Simulator-of-Virtual-Memory
This mini project is a simulator of virtual memory written in ANSII C language. There is a file, addresses.txt, contains number of virtual page and, with support of TLB , links frame in memory eventually computes  physics address in memory.

There are some assumptions I have done for the project let me explain. 

1)The size of virtual memory is 2^16=65536 byte

2)16 elements in TLB

3)256 frame

4)2^8 elements in page table

5)The size of page and frame is 2^8 byte

6)Physics Memory is 65356 byte(256 page x 256 frame)

7)The program support only the reading of translation of virtual address in physics address

8)The size of physics memory and virtual memory are the same therefore it's not necessary the substitution of page when occurs a page fault.

There are fuor functions:

-void changeaddress(): it changes the virtual address in physics address since the number in file addresses.txt are in 32 bit it takes only the least significant bits and they are divided into two parts: the first 8 bits are the number of page the remaining the offset.

-int handlePageFault(int pages): it handles the page fault when occurs with a random access to a file named BACKING_STORE.bin searching the page assigning to the correct frame.

-int TLB_support(int page): it is a support memory for return immediatly the frame if there is not return -1

 -void insertTLB(int frame, int page): it inserts the frame and page in the TLB and when it is full replaces with a FIFO parameter.

I'm the owner of the project and the only one that have worked for if you want to support me and gives me some advices you're welcome and I appreciate.
I'll post some others projects in the future stay soon!
