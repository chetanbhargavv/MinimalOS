/* Main kernel entry point and initialization */

#include "types.h"
#include "screen.h"
#include "memory.h"
#include "scheduler.h"
#include "shell.h"

/**
 * kernel_main - Main kernel entry point
 * 
 * This function is called from the assembly kernel entry.
 * It initializes all kernel subsystems and starts the shell.
 */
void kernel_main(void) {
    /* Initialize screen (VGA text mode) */
    screen_init();
    screen_clear();
    
    /* Print welcome message */
    screen_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
    screen_println("=================================");
    screen_println("   MinimalOS x86_64 Kernel");
    screen_println("=================================");
    screen_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    screen_println("");
    
    /* Initialize memory management */
    screen_print("Initializing memory management... ");
    memory_init();
    screen_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    screen_println("[OK]");
    screen_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    
    /* Initialize task scheduler */
    screen_print("Initializing scheduler... ");
    scheduler_init();
    screen_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    screen_println("[OK]");
    screen_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    
    /* Initialize shell */
    screen_print("Initializing shell... ");
    shell_init();
    screen_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    screen_println("[OK]");
    screen_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    
    screen_println("");
    screen_println("Kernel initialization complete!");
    screen_println("");
    
    /* Start shell */
    shell_run();
    
    /* Halt if shell exits */
    while(1) {
        __asm__ volatile("hlt");
    }
}
