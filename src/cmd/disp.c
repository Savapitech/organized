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
    for (int i = of->act_i; i >= 0; i--)
        if (of->om[i].name && of->om[i].type != ORG_FAILURE &&
            of->om[i].id != -1) {
            my_printf("%s n°%01d - \"%s\"\n", TYPES[of->om[i].type],
                of->om[i].id, of->om[i].name);
        }
    return ORG_SUCCESS;
}
