
#include "./ft_ls.h"
#include <stdio.h>//printf

//test what opendir returns for file as arg: returns NULL
/*int	main(int argc, char **argv)
{
	const char	*filename;
	DIR	*dp = NULL;

	if (argc < 2)
		return (0);
	filename = argv[1];
	dp = opendir(filename);
	if (dp == NULL)
	{
		printf("dp returned NULL\n");
		return (0);
	}
	else
		printf("dp returned a pointer\n");
	closedir(dp);
	return (0);
}
*/

int	list_dir_contents(void)
{
	const char	*filename;
	DIR	*dirp = NULL;
	struct dirent	*dp = NULL;
//	int	i = 0;

	filename = "./";
	dirp = opendir(filename);
	if (dirp == NULL)
	{
		printf("DEBUG: dirp returned NULL\n");
		return (0);
	}
	else
	{

		printf("DEBUG: dirp returned a pointer\n");
//		dp = readdir(dirp);
//		if (dp == NULL)
//			printf("DEBUG: dp returned NULL\n");
		while ((dp = readdir(dirp)) != NULL)
		{
			printf("%s\n", dp->d_name);
		}
	}
	closedir(dirp);
	return (0);
}

int	main(int argc, char **argv)
{
/*	const char	*filename;
	DIR	*dp = NULL;
*/
//	if (argc < 2)
//		return (0);

	if ((argc == 1) && argv)
		list_dir_contents();
//		check_args(argc, argv);
/*	filename = argv[1];
	dp = opendir(filename);
	if (dp == NULL)
	{
		printf("DEBUG: dp returned NULL\n");
		return (0);
	}
	else
		printf("DEBUG: dp returned a pointer\n");
	closedir(dp);
*/
	return (0);
}
