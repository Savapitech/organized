/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "lib.h"
#include "organized.h"

int del(of_t *of, char **args)
{
    int i = 0;
    int id;

    if (!args[0])
        return ORG_FAILURE;
    id = my_getnbr(args[0]);
    if (!my_str_isnum(args[0]) || id < 0 || id > (int)of->act_sz)
        return ORG_FAILURE;
    for (; of->om[i].name != NULL && of->om[i].id != id; i++);
    if (of->om[i].id == -1 || of->om[i].name == NULL)
        return ORG_FAILURE;
    my_printf("%s n°%01d - \"%s\" deleted.\n", TYPES[of->om[i].type],
        of->om[i].id, of->om[i].name);
    of->om[i].id = -1;
    if (args[1])
        del(of, args + 1);
    return ORG_SUCCESS;
}
