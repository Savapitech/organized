/*
** EPITECH PROJECT, 2024
** organized
** File description:
** _
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"

static
const char PROMPT[] = "\033[33mWorkshop >> \033[0m";

static
int parse_cmd(void *data, char *buffer)
{
    char **args = my_str_to_word_array(buffer);
    int result = -1;

    if (strcmp(args[0], "exit") == 0)
        return 0;
    if (strcmp(args[0], "segfault") == 0)
        return (printf("[1]    318954 segmentation fault (core dumped)"
            "  ./organized\n"), 84);
    if (strcmp(args[0], "add") == 0)
        result = add(data, args + 1);
    if (strcmp(args[0], "del") == 0)
        result = del(data, args + 1);
    if (strcmp(args[0], "sort") == 0)
        result = sort(data, args + 1);
    if (strcmp(args[0], "disp") == 0)
        result = disp(data, args + 1);
    if (result == -1)
        return (printf("%s: Command not found.\n", args[0]), 0);
    free(args);
    return result;
}

static
int launch_shell(void *data)
{
    int getresult;
    char *buffer = NULL;
    size_t buf_size;
    int result;

    while (1) {
        write(STDOUT_FILENO, PROMPT, sizeof PROMPT);
        getresult = getline(&buffer, &buf_size, stdin);
        if (getresult == -1)
            break;
        if (strlen(buffer) > 1)
            result = parse_cmd(data, buffer);
        if (result == 84)
            return 84;
    }
    free(buffer);
    return 0;
}

int workshop_shell(void *data)
{
    return launch_shell(data);
}
