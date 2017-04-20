#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl("using: fdf file.fdf");
	else
		fdf(argv[1]);
}
