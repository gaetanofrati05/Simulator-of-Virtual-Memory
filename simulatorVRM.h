#include <stdio.h>
#include <stdlib.h>
#define PAGE_SIZE 256
#define MAX_PAGE 256
#define NUM_FRAMES 256
#define TLB_SIZE 16
//===Global variables===//
int page_table[MAX_PAGE];// page table
unsigned char memoria_fisica[NUM_FRAMES][PAGE_SIZE]; // phsysical memory simulate
int tlb_pagina[TLB_SIZE];   // TLB: virtual page
int tlb_frame[TLB_SIZE];    // TLB: physical frame
int tlb_index = 0;          // for political FIFO
int tlb_count = 0;
int hit_ratio = 0;          //level of success
int next_free_frame = 0;    // next free frame
int handlePageFault(int pages);
int TLB_lookup(int pagina);
void insertTLB(int frame, int pagina);
void changeaddress();
