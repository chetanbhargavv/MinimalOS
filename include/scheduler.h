/* Simple round-robin task scheduler */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "types.h"

/* Task states */
#define TASK_READY 0
#define TASK_RUNNING 1
#define TASK_BLOCKED 2

/* Maximum number of tasks */
#define MAX_TASKS 8

/* Task structure */
typedef struct {
    uint32_t id;
    uint32_t esp;              /* Stack pointer */
    uint32_t state;
    void (*entry_point)(void);
} task_t;

/* Scheduler functions */
void scheduler_init(void);
uint32_t create_task(void (*entry_point)(void));
void schedule(void);
void yield(void);
uint32_t get_current_task_id(void);

#endif
