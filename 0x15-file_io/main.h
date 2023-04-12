#ifndef _FILE_IO_
#define _FILE_IO_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
static int *open_files(const char *file_from, const char *file_to)
static int copy_data(int fd_from, int fd_to)
static void close_files(int *fds)
int copy_file(const char *file_from, const char *file_to)
  
#endif
