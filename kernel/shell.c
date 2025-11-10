/* Basic shell implementation with command support */

#include "shell.h"
#include "screen.h"
#include "string.h"
#include "types.h"

#define MAX_INPUT 256
#define MAX_ARGS 16

/* Shell state */
static char input_buffer[MAX_INPUT];
static uint32_t input_pos = 0;

/* Forward declarations */
static void shell_prompt(void);
static void shell_process_command(const char* cmd);
static void cmd_help(void);
static void cmd_echo(int argc, char** argv);
static void cmd_clear(void);

/**
 * shell_init - Initialize shell
 */
void shell_init(void) {
    input_pos = 0;
    input_buffer[0] = '\0';
}

/**
 * shell_prompt - Display shell prompt
 */
static void shell_prompt(void) {
    screen_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    screen_print("kernel> ");
    screen_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}

/**
 * shell_run - Main shell loop
 * 
 * Displays welcome message and processes commands.
 * Note: This is a simplified shell without keyboard input.
 */
void shell_run(void) {
    screen_set_color(COLOR_YELLOW, COLOR_BLACK);
    screen_println("Hello, Kernel!");
    screen_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    screen_println("");
    screen_println("Welcome to MinimalOS Shell!");
    screen_println("Type 'help' for available commands.");
    screen_println("");
    
    /* Demonstrate shell commands */
    shell_prompt();
    screen_println("help");
    cmd_help();
    screen_println("");
    
    shell_prompt();
    screen_println("echo Hello from MinimalOS!");
    char* test_args[] = {"echo", "Hello", "from", "MinimalOS!"};
    cmd_echo(4, test_args);
    screen_println("");
    
    shell_prompt();
    screen_println("clear");
    screen_println("(clear command ready - would clear screen)");
    screen_println("");
    
    /* Final prompt */
    shell_prompt();
    screen_println("");
    screen_println("Shell demo complete. Kernel running...");
}

/**
 * cmd_help - Display help information
 */
static void cmd_help(void) {
    screen_println("Available commands:");
    screen_println("  help  - Display this help message");
    screen_println("  echo  - Echo arguments to screen");
    screen_println("  clear - Clear the screen");
}

/**
 * cmd_echo - Echo command implementation
 * @argc: Argument count
 * @argv: Argument vector
 */
static void cmd_echo(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        screen_print(argv[i]);
        if (i < argc - 1) {
            screen_putchar(' ');
        }
    }
    screen_println("");
}

/**
 * cmd_clear - Clear screen command
 */
static void cmd_clear(void) {
    screen_clear();
}
