/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:40:12 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/24 10:04:18 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_ptrs
{
	/* data */
	void	*img_ptr;
	int		bpp;
	int		llength;
	int		ein;
}	t_ptrs;


typedef struct s_mlx
{
	/* data */
	void	*mlx_ptr;
	void	*win_ptr;
	void	*frame_ptr;
	int		x;
	int		y;
	int		mbpp;
	int		mllength;
	int		mein;
	char 	*buff;
	int		img_wid;
	int		img_hie;
	char	*img_buff;
	char	*img_buff2;
}	t_mlx;

typedef struct s_textures
{
	int		f_found;
	int		n_no;
	int 	n_so;
	int 	n_we;
	int 	n_ea;
	int		n_f;
	int		n_c;
	char	*no_txt;
	char	*so_txt;
	char	*we_txt;
	char	*ea_txt;
	char	*f_txt;
	char	*c_txt;
}	t_textures;

typedef struct s_map
{
	/* data */
	char	**map;
	int		closed;
	int		start_point; 
	int		end_point;
	int		map_size;
	int		longest_line;
	int		n_lines;
	int		l_lentgh;	
}	t_map;

typedef struct s_color
{
	char	**splited;
	int		r;
	int		g;
	int		b;
	int		final_color;
}	t_color;

typedef struct s_player
{
	float	fov;
	float		x;
	float		y;
	float	angle;
}	t_player;

typedef struct s_plane
{
	int	width;
	int	height;
}	t_plane;

typedef struct s_coordinate
{
	float x;
	float y;
}	t_coordinate;

typedef struct s_ray
{
	float	dist;
	char	dir;
	float	inter_x;
	float	inter_y;
	float	xstep;
	float	ystep;
}	t_ray;

typedef struct s_keys
{
	int	move_right;
	int	move_left;
	int	move_backward;
	int	move_forward;
	int	rotate_left;
	int	rotate_right;
}	t_keys;


typedef struct s_data
{
	char		**av;
	int			ac;
	int			fd_map[2]; // file-descriptor of the map
	char		**file_content; // file content *line by line*
	t_color		floor;
	t_color		ceiling;
	t_textures	sides;
	t_map		map_s;
	t_player	player;
	t_plane		plane;
	int			wall_hit_hor;
	int			wall_hit_ver;
	t_coordinate	coordinate;
	t_mlx		mlx_s;
	t_keys		key_flags;
	t_ptrs		side;
}   t_data;

#endif // STRUCTS_H
