/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include "organized.h"
#include "lib.h"

static
int compare_str(org_materials_t const *s1, org_materials_t const *s2,
    void *params __attribute__((unused)))
{
    int i = 0;

    if (!s1->name || !s2->name)
        return 0;
    for (; s1->name[i] == s2->name[i] && s1->name[i] != '\0'; i++);
    return s2->name[i] - s1->name[i];
}

static
int compare_id(org_materials_t const *a, org_materials_t const *b,
    void *params __attribute__((unused)))
{
    if (b->id == -1 || a->id == -1)
        return 0;
    return b->id - a->id;
}

static
int compare_type(org_materials_t const *a, org_materials_t const *b,
    void *params __attribute__((unused)))
{
    if (b->type == INVALID || a->type == INVALID)
        return 0;
    return b->type - a->type;
}

static
int compare_global(org_materials_t const *a, org_materials_t const *b,
    void *params)
{
    char **args = (char **)params;
    int result = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "ID") == 0)
            result = compare_id(a, b, params);
        if (my_strcmp(args[i], "NAME") == 0)
            result = compare_str(a, b, params);
        if (my_strcmp(args[i], "TYPE") == 0)
            result = compare_type(a, b, params);
        if (args[i + 1] != NULL && my_strcmp(args[i + 1], "-r") == 0)
            result = -result;
        if (result != 0)
            break;
    }
    return result;
}

int sort(of_t *of, char **args)
{
    miniqsort_t mq;

    if (!args[0])
        return ORG_FAILURE;
    if (my_strcmp(args[0], "ID") && my_strcmp(args[0], "NAME") &&
            my_strcmp(args[0], "TYPE"))
        return ORG_FAILURE;
    mq.arr = (char *)of->om;
    mq.size = of->act_i;
    mq.mem_s = sizeof *of->om;
    mq.params = args;
    mq.compare = (compare_fn_t)&compare_global;
    mini_qsort(&mq);
    return ORG_SUCCESS;
}
