/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "organized.h"
#include "lib.h"

int disp(of_t *of, char **args)
{
    for (size_t i = 0; i < of->act_sz; i++)
        if (of->om[i].name)
            my_printf("DISP ID %01d NAME %s\n", of->om[i].id, of->om[i].name);
    return ORG_SUCCESS;
}
