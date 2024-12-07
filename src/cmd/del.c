/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "lib.h"
#include "organized.h"

static
const char *TYPES[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE"
};

int del(of_t *of, char **args)
{
    int i;

    if (!args[0])
        return ORG_FAILURE;
    i = my_getnbr(args[0]);
    if (!my_str_isnum(args[0]) || i < 0 || i > (int)of->act_sz ||
        of->om[i].id < 0)
        return ORG_FAILURE;
    my_printf("%s n°%01d - \"%s\" deleted.\n", TYPES[of->om[i].type],
        of->om[i].id, of->om[i].name);
    of->om[i].id = -1;
    if (args[1])
        del(of, args + 1);
    return ORG_SUCCESS;
}
