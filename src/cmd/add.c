/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "lib.h"
#include "organized.h"

int add(of_t *of, char **args)
{
    if (handle_realloc(of) != ORG_SUCCESS)
        return ORG_FAILURE;
    if (!args[0] || !args[1])
        return ORG_FAILURE;
    of->om[of->act_i].id = of->act_i;
    of->om[of->act_i].name = my_strdup(args[1]);
    of->act_i++;
    my_printf("ADDED %s\n", args[1]);
    return ORG_SUCCESS;
}
