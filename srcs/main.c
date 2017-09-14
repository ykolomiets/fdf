#include "fdf.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	//test();

	if (argc != 2)
		ft_putendl("using: fdf file.fdf");
	else
		fdf(argv[1]);
}
