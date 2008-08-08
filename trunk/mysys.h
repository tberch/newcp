#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define  KEY            1983
#define  SIZE_THRESHOLD 10485760

inline void
lock_sem(int semid) {
  struct sembuf sem_lock = {0, -1, SEM_UNDO};
  pid_t pid = getpid();

  if( (semop(semid, &sem_lock, 1)) == -1) {
    fprintf(stderr, "pid = %d (%s) %d# semop error, errno = %d\n", pid, __FILE__, __LINE__, errno);
    exit(-1);
  }
}

inline void
unlock_sem(int semid) {
  struct sembuf sem_unlock = {0, 1, SEM_UNDO};
  pid_t pid = getpid();

  if((semop(semid, &sem_unlock, 1)) == -1) {
    fprintf(stderr, "pid = %d (%s) %d# semop error, errno = %d\n", pid, __FILE__, __LINE__, errno);
    exit(-1);
  }
}

inline void
init_sem(int semid) {
  int value[] = {1};
  pid_t pid = getpid();

  if((semctl(semid, 1, SETALL, value)) == -1) {
    fprintf(stderr, "pid = %d (%s) %d# semctl error, errno = %d\n", pid, __FILE__, __LINE__, errno);
    exit(-1);
  }
} 

inline void
remove_sem(int semid) {
  pid_t pid = getpid();

  if((semctl(semid, 0, IPC_RMID, 0)) == -1) {
    fprintf(stderr, "pid = %d (%s) %d# semctl error, errno = %d\n", pid, __FILE__, __LINE__, errno);
    exit(-1);
  }
}
