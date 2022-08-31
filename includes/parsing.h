
#ifndef PARSING_H
#define PARSING_H

// #include "structs.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include "../Get_next_line/get_next_line.h"

int		ft_check_cub(char *name);
int		ft_parsing(t_data *data);
int		ft_parse_textures(t_data *data);
int     ft_parse_map(t_data *data);
void	ft_get_colors(t_data *data);

//         parsing utils       */
int     ft_issides(char *line, char a, char b, int flag);
int     ft_is_map(char *line);
int     ft_check_after_id(t_data *data);
void	ft_update_txt(t_data *data);

#endif // PARSING_H
