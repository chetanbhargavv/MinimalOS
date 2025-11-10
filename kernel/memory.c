/* Memory management implementation with simple allocator */

#include "memory.h"
#include "types.h"

/* Simple memory allocator */
#define HEAP_START 0x200000      /* 2MB */
#define HEAP_SIZE  0x400000      /* 4MB heap */

static uint8_t* heap_start = (uint8_t*)HEAP_START;
static uint8_t* heap_current = (uint8_t*)HEAP_START;
static uint8_t* heap_end = (uint8_t*)(HEAP_START + HEAP_SIZE);

/**
 * memory_init - Initialize memory management
 * 
 * Sets up the kernel heap for dynamic memory allocation.
 */
void memory_init(void) {
    heap_current = heap_start;
    
    /* Clear heap memory */
    memset(heap_start, 0, HEAP_SIZE);
}

/**
 * kmalloc - Allocate kernel memory
 * @size: Number of bytes to allocate
 * 
 * Returns: Pointer to allocated memory or NULL on failure
 * 
 * This is a simple bump allocator. In a real OS, you'd want
 * a more sophisticated allocator with free list management.
 */
void* kmalloc(size_t size) {
    /* Align to 16 bytes */
    size = (size + 15) & ~15;
    
    if (heap_current + size > heap_end) {
        return NULL;  /* Out of memory */
    }
    
    void* ptr = heap_current;
    heap_current += size;
    
    return ptr;
}

/**
 * kfree - Free kernel memory
 * @ptr: Pointer to memory to free
 * 
 * Note: This simple allocator doesn't actually free memory.
 * A real implementation would maintain a free list.
 */
void kfree(void* ptr) {
    /* Simple allocator doesn't support freeing */
    (void)ptr;
}

/**
 * memset - Fill memory with constant byte
 * @dest: Destination pointer
 * @val: Value to set
 * @len: Number of bytes
 * 
 * Returns: Destination pointer
 */
void* memset(void* dest, int val, size_t len) {
    uint8_t* d = (uint8_t*)dest;
    
    while (len--) {
        *d++ = (uint8_t)val;
    }
    
    return dest;
}

/**
 * memcpy - Copy memory area
 * @dest: Destination pointer
 * @src: Source pointer
 * @len: Number of bytes to copy
 * 
 * Returns: Destination pointer
 */
void* memcpy(void* dest, const void* src, size_t len) {
    uint8_t* d = (uint8_t*)dest;
    const uint8_t* s = (const uint8_t*)src;
    
    while (len--) {
        *d++ = *s++;
    }
    
    return dest;
}
