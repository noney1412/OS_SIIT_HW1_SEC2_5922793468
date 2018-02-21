#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

/** ย้ายไป linux
 **/

#define SHSIZE 100

int main(int argc, char *argv[]) 
{
  int shmid;
  key_t key;
  char *shm;
  char *s;

  key = 1150;

  shmid = shmget(key, SHSIZE, IPC_CREAT | 1234);

  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  shm = shmat(shmid, NULL, 0);

  if (shm == (char *)-1) {
    perror("smhat");
    exit(1)
  }

  memory(shm, "Chanon Panpila", 14);

  s = shm;
  s += 14;

  *s = 0;

  while (*shm != '*')
    sleep(1);

  return 0;
}