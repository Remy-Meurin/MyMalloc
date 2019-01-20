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
#include<stdio.h>

void*   malloc(size_t size)
{
    size_t test = size;
    printf("Hola que tal malloc!");
    printf("%zu\n", test);
    
    return 0;
}

// void my_free(void *ptr) {
//     t_block *block;

//     block = (((t_block *) ptr) - 1);
// }