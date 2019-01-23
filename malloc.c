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

struct s_header *block_list;
struct s_header *head;

void*   malloc(size_t size)
{
    size_t total_size;
    void* block;
    struct s_header *header;

    if (!size)
        return (NULL);

    header = find_free_block(size);
    if (header){
        header->free = 0;
        return ((void*)(header + 1));
    } else {
        total_size = sizeof(struct s_header) + size;
        block = sbrk(total_size * 32);
        header = (t_header *)block;
        header->size = size;
        header->free = 0;
        header->next = NULL;
        if (!head)
            head = header;
        return (((char *)header) + sizeof(*block));
    }
}

struct s_header *find_free_block(size_t size)
{
    struct s_header *curr = block_list;
    while(curr){
        if (curr->free == 1 && curr->size >= size) {
            return (curr);
        } else {
            curr = curr->next;
        }
    }
    return (NULL);
}

void free(void *ptr) {
    struct s_header *header;
    // printf("Debugg free 1\n");
    // printf("Address parametre: %p\n", (void *)ptr);
    if (!ptr)
        return;
    // printf("Debugg free 2\n");
    header = (struct s_header*)ptr - offsetof(struct s_header, next);
    // printf("Debugg free 3\n");
    // printf("Address header: %p\n", (void *)header);
    // printf("1/ Value free => %d\n", header->free);
    header->free = 1;
    // printf("2/ Value free => %d\n", header->free);
}

void *calloc(size_t num_elements, size_t size)
{
	char *block;

    if (num_elements == 0 || size == 0) {
        return NULL;
    }

    if ((block = malloc(num_elements * size))) {
        memset(block, 0, size * num_elements);
    } else {
        return NULL;
    }

    return (block);
}

// void* realloc(void *ptr, size_t size)
// {
//     void *block;
//     if (size == 0) {
//         free(ptr);
//         return NULL;
//     } else if (!ptr) {
//         block = malloc(size);
//         if (block) {
//             memcpy(block, (void *)ptr, size);
//         }
//         free(ptr);
//     }
//     return block;
// }
