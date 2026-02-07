#ifndef OS_H
#define OS_H

typedef unsigned int size_t;

void os_uart_init(void);
void os_write(const char *buf, size_t n);
char os_read_char(void);
size_t os_read_line(char *buf, size_t max_len);

#endif
