/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "organized.h"
#include "lib.h"

static
const char *TYPES[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE"
};

int disp(of_t *of, char **args)
{
    for (size_t i = 0; i < of->act_sz; i++)
        if (of->om[i].name) {
            my_printf("%s n°%01d - \"%s\"\n", TYPES[of->om[i].type],
                of->om[i].id, of->om[i].name);
        }
    return ORG_SUCCESS;
}
