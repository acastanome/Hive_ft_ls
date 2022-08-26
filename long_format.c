
#include "./ft_ls.h"

//	printf("Name: %s\n", filename);// a_crazy_file

//printf("Type: %c\n", type);
char	file_type(char *filename)
{
	struct stat	sb;
	char	type;

	lstat(filename, &sb);
	type = '\0';
	if (S_ISREG(sb.st_mode))
		type = '-';
	else if (S_ISDIR(sb.st_mode))
		type = 'd';
	else if (S_ISCHR(sb.st_mode))
		type = 'c';
	else if (S_ISBLK(sb.st_mode))
		type = 'b';
	else if (S_ISFIFO(sb.st_mode))
		type = 'p';
	else if (S_ISLNK(sb.st_mode))
		type = 'l';
	else if (S_ISSOCK(sb.st_mode))
		type = 's';
	return (type);
}

//	printf("Modes: \n");//rwxr-xr-x
//	printf("File type and modes: %s\n", bits);
char	*file_type_permissions(char *filename)
{
	struct stat	sb;
	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
								"r--", "r-x", "rw-", "rwx"};
	static char bits[11];

	lstat(filename, &sb);
	bits[0] = file_type(filename);//	bits[0] = filetypeletter(mode);
	strcpy(&bits[1], rwx[(sb.st_mode >> 6)& 7]);
	strcpy(&bits[4], rwx[(sb.st_mode >> 3)& 7]);
	strcpy(&bits[7], rwx[(sb.st_mode & 7)]);
	if (sb.st_mode & S_ISUID)//		bits[3] = (sb.st_mode & S_IXUSR) ? 's' : 'S';
	{
		if (sb.st_mode & S_IXUSR)
			bits[3] = 's';
		else
			bits[3] = 'S';
	}
	if (sb.st_mode & S_ISGID)//		bits[6] = (sb.st_mode & S_IXGRP) ? 's' : 'l';
	{
		if (sb.st_mode & S_IXGRP)
			bits[6] = 's';
		else
			bits[6] = 'l';
	}
	if (sb.st_mode & S_ISVTX)//		bits[9] = (sb.st_mode & S_IXOTH) ? 't' : 'T';
	{
		if (sb.st_mode & S_IXOTH)
			bits[9] = 't';
		else
			bits[9] = 'T';
	}
	bits[10] = '\0';
	return (bits);
}

//	printf("Modes: \n");//rwxr-xr-x
char	*file_permissions(char *filename)
{
	struct stat	sb;
	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
								"r--", "r-x", "rw-", "rwx"};
	static char bits[10];

	lstat(filename, &sb);
	strcpy(&bits[0], rwx[(sb.st_mode >> 6)& 7]);
	strcpy(&bits[3], rwx[(sb.st_mode >> 3)& 7]);
	strcpy(&bits[6], rwx[(sb.st_mode & 7)]);
	if (sb.st_mode & S_ISUID)//		bits[3] = (sb.st_mode & S_IXUSR) ? 's' : 'S';
	{
		if (sb.st_mode & S_IXUSR)
			bits[2] = 's';
		else
			bits[2] = 'S';
	}
	if (sb.st_mode & S_ISGID)//		bits[6] = (sb.st_mode & S_IXGRP) ? 's' : 'l';
	{
		if (sb.st_mode & S_IXGRP)
			bits[5] = 's';
		else
			bits[5] = 'l';
	}
	if (sb.st_mode & S_ISVTX)//		bits[9] = (sb.st_mode & S_IXOTH) ? 't' : 'T';
	{
		if (sb.st_mode & S_IXOTH)
			bits[8] = 't';
		else
			bits[8] = 'T';
	}
	bits[9] = '\0';
	return (bits);
}

//	printf("Number of links: %d\n", sb.st_nlink);//1
int	file_nb_links(char *filename)
{
	struct stat	sb;
	int	links;

	lstat(filename, &sb);
	links = 0;
	links = sb.st_nlink;
	return (links);
}

//TODO
int	file_owner(char *filename)
{
	struct stat	sb;

	lstat(filename, &sb);
	ft_putstr("MISSING OWNER AND GROUP \n");
//	printf("Owner: \n", sb.st_uid);//zaz
	return (0);
}

//TODO
int	file_group(char *filename)
{
	struct stat	sb;

	lstat(filename, &sb);
	ft_putstr("MISSING OWNER AND GROUP \n");
//	printf("Group: \n", sb.st_gid);//staff
	return (0);
}

//	printf("Size: %lld\n", sb.st_size);//2142 octets
//	printf("Last modification date: %ld\n", sb.st_mtime);//Sep 17 23:42
int	file_size(char *filename)
{
	struct stat	sb;
	int	size;

	size = 0;
	lstat(filename, &sb);
	size = sb.st_size;
	return (size);
}

//TODO
int	file_modif(char *filename)
{
	struct stat	sb;

	lstat(filename, &sb);
	printf("Last modification date: %ld\n", sb.st_mtime);//Sep 17 23:42
	return (modif);
}

/* WHOLE
int	file_info(char *filename)
{
	struct stat	sb;

	lstat(filename, &sb);

	printf("Name: %s\n", filename);// a_crazy_file

	char	type;
	type = '\0';
	if (S_ISREG(sb.st_mode))
		type = '-';
	else if (S_ISDIR(sb.st_mode))
		type = 'd';
	else if (S_ISCHR(sb.st_mode))
		type = 'c';
	else if (S_ISBLK(sb.st_mode))
		type = 'b';
	else if (S_ISFIFO(sb.st_mode))
		type = 'p';
	else if (S_ISLNK(sb.st_mode))
		type = 'l';
	else if (S_ISSOCK(sb.st_mode))
		type = 's';
//	printf("Type: %c\n", type);//File

	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
								"r--", "r-x", "rw-", "rwx"};
	static char bits[11];
//	bits[0] = filetypeletter(mode);
	bits[0] = type;
	strcpy(&bits[1], rwx[(sb.st_mode >> 6)& 7]);
	strcpy(&bits[4], rwx[(sb.st_mode >> 3)& 7]);
	strcpy(&bits[7], rwx[(sb.st_mode & 7)]);
	if (sb.st_mode & S_ISUID)
	{
//		bits[3] = (sb.st_mode & S_IXUSR) ? 's' : 'S';
		if (sb.st_mode & S_IXUSR)
			bits[3] = 's';
		else
			bits[3] = 'S';
	}
	if (sb.st_mode & S_ISGID)
	{
//		bits[6] = (sb.st_mode & S_IXGRP) ? 's' : 'l';
		if (sb.st_mode & S_IXGRP)
			bits[6] = 's';
		else
			bits[6] = 'l';
	}
	if (sb.st_mode & S_ISVTX)
	{
//		bits[9] = (sb.st_mode & S_IXOTH) ? 't' : 'T';
		if (sb.st_mode & S_IXOTH)
			bits[9] = 't';
		else
			bits[9] = 'T';
	}
	bits[10] = '\0';
	printf("File type and modes: %s\n", bits);
//	printf("Modes: \n");//rwxr-xr-x

	printf("Number of links: %d\n", sb.st_nlink);//1

	ft_putstr("MISSING OWNER AND GROUP \n");
//	printf("Owner: \n", sb.st_uid);//zaz
//	printf("Group: \n", sb.st_gid);//staff
//	printf("Size: %lld\n", sb.st_size);//2142 octets
	ft_putstr("Size: ");
	ft_putnbr(sb.st_size);//2142 octets
	printf("\n");
	printf("Last modification date: %ld\n", sb.st_mtime);//Sep 17 23:42
	return (0);
}
*/
