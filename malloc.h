/*
** my_malloc.h for my_malloc in /home/user/Malloc
** 
** Made by MEURIN Remy
** Login   <meurin_r@etna-alternance.net>
** 
** Started on  Sun Jan 20 16:32:25 2019 MEURIN Remy
** Last update Sun Jan 20 16:32:26 2019 MEURIN Remy
*/
#ifndef __MY_MALLOC_H__
#define __MY_MALLOC_H__

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h> /* memset */

typedef struct s_header
{
    struct s_header *next;
    struct s_header *prev;
    size_t size;
    int free;
} t_header;

void *malloc(size_t size);
struct s_header *find_free_block(size_t size);
void free(void *ptr);
void* calloc(size_t num_elements, size_t size);
// void* realloc(void *ptr, size_t size);
#endif