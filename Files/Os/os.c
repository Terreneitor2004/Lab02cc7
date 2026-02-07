#include "os.h"

#define UART0_BASE 0x101f1000u
#define UARTDR     (*(volatile unsigned int *)(UART0_BASE + 0x00))
#define UARTFR     (*(volatile unsigned int *)(UART0_BASE + 0x18))

// FR bits (PL011): TXFF=bit5, RXFE=bit4
#define UARTFR_TXFF (1u << 5)
#define UARTFR_RXFE (1u << 4)

static void uart_putc(char c) {
  while (UARTFR & UARTFR_TXFF) { }
  UARTDR = (unsigned int)c;
}

static char uart_getc(void) {
  while (UARTFR & UARTFR_RXFE) { }
  return (char)(UARTDR & 0xFF);
}

void os_uart_init(void) {
}

void os_write(const char *buf, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (buf[i] == '\n') uart_putc('\r');
    uart_putc(buf[i]);
  }
}

char os_read_char(void) {
  return uart_getc();
}

size_t os_read_line(char *buf, size_t max_len) {
  if (!buf || max_len == 0) return 0;

  size_t i = 0;
  while (i + 1 < max_len) {
    char c = os_read_char();

    if (c == '\r') {
      os_write("\r\n", 2);
      break;
    }
    if (c == '\n') {
      os_write("\r\n", 2);
      break;
    }

    if (c == 0x08 || c == 0x7F) {
      if (i > 0) {
        i--;
        os_write("\b \b", 3);
      }
      continue;
    }

    buf[i++] = c;
    os_write(&c, 1);
  }
  buf[i] = '\0';
  return i;
}
