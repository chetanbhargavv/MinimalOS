/* Simple round-robin task scheduler implementation */

#include "scheduler.h"
#include "memory.h"
#include "types.h"

/* Task table */
static task_t tasks[MAX_TASKS];
static uint32_t num_tasks = 0;
static uint32_t current_task = 0;

/* Task stack size */
#define TASK_STACK_SIZE 8192

/**
 * scheduler_init - Initialize the task scheduler
 * 
 * Sets up the scheduler data structures.
 */
void scheduler_init(void) {
    num_tasks = 0;
    current_task = 0;
    
    /* Clear task table */
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = 0;
        tasks[i].esp = 0;
        tasks[i].state = TASK_READY;
        tasks[i].entry_point = NULL;
    }
}

/**
 * create_task - Create a new task
 * @entry_point: Function to execute in the task
 * 
 * Returns: Task ID or 0 on failure
 * 
 * Allocates a stack for the task and adds it to the scheduler.
 */
uint32_t create_task(void (*entry_point)(void)) {
    if (num_tasks >= MAX_TASKS) {
        return 0;  /* No more task slots */
    }
    
    /* Allocate task stack */
    void* stack = kmalloc(TASK_STACK_SIZE);
    if (!stack) {
        return 0;  /* Out of memory */
    }
    
    /* Initialize task */
    uint32_t task_id = num_tasks;
    tasks[task_id].id = task_id;
    tasks[task_id].esp = (uint32_t)stack + TASK_STACK_SIZE;
    tasks[task_id].state = TASK_READY;
    tasks[task_id].entry_point = entry_point;
    
    num_tasks++;
    
    return task_id;
}

/**
 * schedule - Select next task to run
 * 
 * Simple round-robin scheduler that picks the next ready task.
 * In a real OS, this would save/restore CPU context.
 */
void schedule(void) {
    if (num_tasks == 0) {
        return;
    }
    
    /* Find next ready task */
    uint32_t start_task = current_task;
    
    do {
        current_task = (current_task + 1) % num_tasks;
        
        if (tasks[current_task].state == TASK_READY) {
            tasks[current_task].state = TASK_RUNNING;
            return;
        }
    } while (current_task != start_task);
}

/**
 * yield - Voluntarily give up CPU
 * 
 * Allows a task to yield the CPU to other tasks.
 * In a real OS, this would trigger a context switch.
 */
void yield(void) {
    if (num_tasks <= 1) {
        return;
    }
    
    /* Mark current task as ready */
    if (current_task < num_tasks) {
        tasks[current_task].state = TASK_READY;
    }
    
    /* Schedule next task */
    schedule();
}

/**
 * get_current_task_id - Get ID of currently running task
 * 
 * Returns: Current task ID
 */
uint32_t get_current_task_id(void) {
    return current_task;
}
