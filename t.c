#include <stdlib.h>

int		main()
{
//もしmallocがうまくできたら以下の挙動になる  
	int	*test = (int *)malloc(999999999);
	free(test);

	free(NULL);

	system("leaks a.out");

	return 0;
}
