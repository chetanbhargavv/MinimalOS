/* Memory management with paging */

#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

/* Page size */
#define PAGE_SIZE 4096

/* Memory management functions */
void memory_init(void);
void* kmalloc(size_t size);
void kfree(void* ptr);
void* memset(void* dest, int val, size_t len);
void* memcpy(void* dest, const void* src, size_t len);

#endif
