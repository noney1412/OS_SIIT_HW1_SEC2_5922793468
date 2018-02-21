#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Negative Value: creation of a child process was unsuccessful.
// Zero: Returned to the newly created child process.
// Positive value: Returned to parent or caller. The value contains process ID
// of newly created child process.

int main() {

  pid_t pid_B, pid_C;

  printf("Hello world! Parent process_ID %d \n", getpid());

  pid_B = fork();
  pid_C = fork();

  if (pid_B == 0) {
    printf("Hello world! from B process_ID %d \n", getpid());
  }

  else if (getpid() < 0) {
    printf("error");
  }

  if (pid_C == 0)
    printf("Hello world from C ! process_ID %d \n", getpid());

  else if (getpid() < 0) {
    printf("error");
  }

  return 0;
}