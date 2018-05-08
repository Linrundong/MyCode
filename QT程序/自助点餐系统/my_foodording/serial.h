#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>


class serial
{
public:
    serial();
    ~serial();

    int initSerial(int num,int speed);
    void Serial_io(int fd, char* str);
    void String_chg(char* buf, char* before);

    int uart_read(int fd, char *buf_read, int buf_len);
    int uart_send(int fd, char *buf_send, int buf_len);

    int serial_fd;

};









#endif // SERIAL_H
