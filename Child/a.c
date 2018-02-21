#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Negative Value: creation of a child process was unsuccessful.
// Zero: Returned to the newly created child process.
// Positive value: Returned to parent or caller. The value contains process ID
// of newly created child process.

int main() {

  pid_t pid_A;

  pid_A = fork();

  printf("Hello world! process_ID %d \n", getpid());

  if (getpid() < 0) {
    printf("error")
  }

  return 0;
}