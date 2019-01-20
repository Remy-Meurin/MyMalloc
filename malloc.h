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

typedef struct s_block
{
    struct s_block *next;
    size_t size;
    int free;
} t_block;

void *malloc(size_t size);
// void my_free(void *ptr);

#endif