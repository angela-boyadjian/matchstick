/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** header file for get next line
*/
#ifndef READ_SIZE
#define READ_SIZE (4)
#endif

#ifndef GNL_H_
#define GNL_H_

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);

#endif