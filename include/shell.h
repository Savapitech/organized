/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H
    #include "organized.h"

int add(of_t *, char **);
int del(of_t *, char **);
int sort(of_t *, char **);
int disp(of_t *, char **);

int workshop_shell(void *);
#endif /* SHELL_H */
