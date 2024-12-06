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

static
int get_type(char *arg)
{
    if (!my_strcmp("ACTUATOR", arg))
        return ACTUATOR;
    if (!my_strcmp("DEVICE", arg))
        return DEVICE;
    if (!my_strcmp("PROCESSOR", arg))
        return PROCESSOR;
    if (!my_strcmp("SENSOR", arg))
        return SENSOR;
    if (!my_strcmp("WIRE", arg))
        return WIRE;
    return ORG_FAILURE;
}

int add(of_t *of, char **args)
{
    if (handle_realloc(of) != ORG_SUCCESS)
        return ORG_FAILURE;
    if (!args[0] || !args[1])
        return ORG_FAILURE;
    of->om[of->act_i].id = of->act_i;
    of->om[of->act_i].name = my_strdup(args[1]);
    of->om[of->act_i].type = get_type(args[0]);
    if (of->om[of->act_i].type == ORG_FAILURE)
        return ORG_FAILURE;
    my_printf("%s n°%01d - \"%s\" added.\n", TYPES[of->om[of->act_i].type],
        of->om[of->act_i].id, of->om[of->act_i].name);
    of->act_i++;
    if (args[2])
        add(of, args - ~-1 - ~1);
    return ORG_SUCCESS;
}
