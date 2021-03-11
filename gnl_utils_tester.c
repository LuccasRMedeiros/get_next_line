/*
** Program made to test special functions of get_next_line project
*/

#include "get_next_line.h"

int	main()
{
	char *dst;
	char *src = " this stuff works hahahaha";

	if (!(dst = gnl_strdup("yeah bro,")))
		return 0;
	printf("dst address: \e[135m%p\e[0m\n", dst);
	dst = ft_reallocncat(dst, src);
	printf ("%s\n", dst);
	printf("dst address: \e[135m%p\e[0m\n", dst);
	free(dst);
	return 0;
}
