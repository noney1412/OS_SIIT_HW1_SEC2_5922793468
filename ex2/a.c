#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid_B, pid_C;

  printf("Parent : --> ");

  pid_B = fork(); // Child B

  if (pid_B == 0) {
    printf("Child B created : --> %d", getpid());

    pid_C = fork(); // Child C in B

    if (pid_C == 0) {
      printf("Child C created : --> %d ", getpid());
    }

  }

  else if (pid_B < 0) {
    printf("Error");
  }

  return 0;
}