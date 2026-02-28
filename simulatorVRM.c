void changeaddress() {
    FILE *fd = fopen("addresses.txt", "r");
    if (fd == NULL) {
        perror("fopen");
        return;
    }
    int num;
    while (fscanf(fd, "%d", &num) == 1) {
        unsigned int address16bit = num & 0xFFFF;
        unsigned char page = (address16bit >> 8) & 0xFF;   // 8 bit page
        unsigned char offset = address16bit & 0xFF;        // 8 bit offset
        int frame = TLB_lookup(pagina);

        if (frame == -1) {
            if (page_table[pagina] == -1) { 
                frame = handlePageFault(pagina);
            } else { 
                frame = page_table[pagina];
            }

            insertTLB(page, frame);
        }
        unsigned int physical_address = frame * PAGE_SIZE + offset;
        printf("Logic: %d -> Physical: %u\n", num, physical_address);
    }

    fclose(fd);
}
int handlePageFault(int pagina) {
    FILE *fd = fopen("BACKING_STORE.bin", "rb");
    if (fd == NULL) {
        perror("fopen");
        exit(1);
    }
    int frame = next_free_frame;
    next_free_frame++;
    fseek(fd, page * PAGE_SIZE, SEEK_SET);
    fread(physical_memory[frame], sizeof(unsigned char), PAGE_SIZE, fd);
    page_table[page] = frame;
    fclose(fd);
    return frame;
}
int TLB_lookup(int pagina) {
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb_pagina[i] == pagina) {
            hit_ratio++;
            return tlb_frame[i];
        }
    }
    return -1; // TLB miss
}
void insertTLB(int page, int frame) {
    tlb_pagina[tlb_index] = page;
    tlb_frame[tlb_index] = frame;
    tlb_index = (tlb_index + 1) % TLB_SIZE;
    if (tlb_count < TLB_SIZE)
        tlb_count++;
}
