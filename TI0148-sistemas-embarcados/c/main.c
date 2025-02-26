volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;

void print_uart0(const char *s) {
 while(*s != '\0') {
 *UART0DR = (unsigned int)(*s);
 s++;
 }
}


void c_entry() {
 char a = 10, b = 20, s = 0;
 s = a + b;

 char buffer[20];
 buffer[0] = '\0';

 print_uart0("O valor de s é ");
 buffer[0] = (s / 10) + '0';
 buffer[1] = (s % 10) + '0';
 buffer[2] = '\n';
 buffer[3] = '\0';

 print_uart0(buffer);
}
