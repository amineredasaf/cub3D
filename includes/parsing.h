
#ifndef PARSING_H
#define PARSING_H

#include "structs.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../Get_next_line/get_next_line.h"

int		ft_check_cub(char *name);
int		ft_parsing(t_data *data);
char	*ft_substr(char *s, int start, size_t len);

#endif // PARSING_H
