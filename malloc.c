/*
** my_malloc.c for my_malloc in /home/user/Malloc
** 
** Made by MEURIN Remy
** Login   <meurin_r@etna-alternance.net>
** 
** Started on  Sun Jan 20 16:31:14 2019 MEURIN Remy
** Last update Sun Jan 20 16:31:16 2019 MEURIN Remy
*/
#include "malloc.h"

struct s_header *head;
struct s_header *tail;

void*   malloc(size_t size)
{
    size_t total_size;
    void* block;
    struct s_header *header;

    if (!size)
        return NULL;

    header = findFreeBlock(size);
    if (header){
        header->free = 0;
        return ((void*)(header + 1));
    } else {
        total_size = sizeof(struct s_header) + size;
        block = sbrk(total_size);
        header = block;
        header->size = size;
        header->free = 0;
        header->next = NULL;
        if (!head)
            head = header;
        if (tail)
            tail->next = header;
        tail = header;
        return (((char *)header) + sizeof(*block));
    }
}

struct s_header *findFreeBlock(size_t size)
{
    struct s_header *curr = head;
    while(curr){
        if (curr->free == 1 && curr->size >= size) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// void my_free(void *ptr) {
//     t_block *block;

//     block = (((t_block *) ptr) - 1);
// }