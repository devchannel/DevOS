#ifndef _PAGING_H_
#define _PAGING_H_

#include <stdint.h>
// This virtuall maps the kernel to 0xC0000000 and enables the paging bit
void init_paging();


typedef struct page_entry
{
  uint32_t present  : 1; // Is the page table is present
  uint32_t rw       : 1; // Is it readable or writeable
  uint32_t auth     : 1; // Who can access it
  uint32_t accessed : 1; // Has this been read or written
  uint32_t dirty    : 1; // Has the page been written to, more specfic than above
  uint32_t _        : 7; // Unused
  uint32_t frame    : 20; // The actual frame
} page_entry_t;

typedef struct page_table
{
  page_entry_t pages[1024];
} page_table_t;

typedef struct page_directory
{
  page_table_t* tables[1024];  // A pointer to the array of tables.
  uintptr_t tables_phys[1024]; // The physical addresses of these tables
  uintptr_t phys;              // The physical address of ^^. The address of the addresses.
} page_directory_t;

// This our page directory and table.
// They're an array, but we don't have any allocation right now
// So instead, we use a GCC hack to make them static.
// This isn't good, but it works for now. As soon as we get a kmalloc function
// TODO: Replace this!

page_directory_t first_directory __attribute__((alligned(4096)));
page_table_t first_table __attribute__((alligned(4096)));


#endif // _PAGING_H_
