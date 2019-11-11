#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include "randfileh.h"

int random_num(){
  int fd = open("/dev/random", O_RDONLY);
  if (fd < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  int buff;
  int num = read(fd, &buff, 4);
  if (num < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  close(fd);
  return buff;
}
