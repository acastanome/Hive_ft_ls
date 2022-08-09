
#ifndef	FT_LS_H
# define	FT_LS_H

#include <dirent.h>//opendir

//DIR *opendir(const char *filename);		ret: pointer or NULL
//struct dirent *readdir(DIR *dirp);		ret: p to next dir entry, NULL when endofdir or error (then sets errno)
//												errno may be set to any of the values documented for the getdirentries(2) system call
//												NOTE: order of dirs is not specified, lexicogr or not
//int closedir(DIR *dirp);					ret: 0 success, failure -1 and sets errno

//stat
//lstat
//getpwuid
//getgrgid
//listxattr
//getxattr
//time
//ctime
//readlink

//write
//malloc
//free

//perror
//strerror
//exit


//bonus example maybe tcgetattr (for what)

# endif
