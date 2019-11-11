#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include "randfileh.h"

int main(){
  int numbers[10];
  printf("Generating random numbers:\n");
  int c;
  for (c = 0; c < 10; c++){
    numbers[c] = random_num();
    printf("random %d: %d\n", c, numbers[c]);
  }
  printf("Writing numbers to file...\n");
  int fd = open("numbers.txt", O_CREAT | O_WRONLY, 666);
  if (fd < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  int w = write(fd, &numbers, sizeof(numbers));
  if (w < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  close(fd);
  printf("Reading numbers from file...\n");
  int file = open("numbers.txt", O_RDONLY);
  if (file < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  int newnums[10];
  int r = read(file, &newnums, sizeof(newnums));
  if (r < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  printf("Verification that written values were the same:\n");
  for (c = 0; c < 10; c++){
    printf("random %d: %d\n", c, newnums[c]);
  }
  close(file);
  return 0;
}
