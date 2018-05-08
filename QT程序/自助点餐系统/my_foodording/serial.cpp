#include "serial.h"

serial::serial()
{
    char tmp_buf[100] = {0};
    this->serial_fd = initSerial(0, 115200);

    //设置单连接模式
    Serial_io(this->serial_fd, "AT+CIPMUX=0");
    //设置服务器的IP和端口
    String_chg(tmp_buf, "AT+CIPSTART=*TCP*,*192.168.191.1*,8080");
    Serial_io(this->serial_fd, tmp_buf);

}

int serial::initSerial(int num, int speed)
{
    char serial_file[4][50] = {
        "/dev/ttyUSB0",
        "/dev/ttySAC1",
        "/dev/ttySAC2",
        "/dev/ttySAC3"
    };

    /*打开串口文件*/
    printf("%s  %d\n",serial_file[num],speed);
    int serial_fd = open(serial_file[num],O_RDWR);
    if(serial_fd == -1)
    {
        perror("open serial error");
    }
    /*定义串口信息结构体并赋值*/
    struct termios myserial;
    memset(&myserial,0,sizeof(myserial));
    myserial.c_cflag |= (CLOCAL | CREAD);    //设置串口本地连接，并接受使能
    myserial.c_cflag &= ~CSIZE;				 //清空数据位
    myserial.c_cflag |= CS8;				 //数据位 8
    myserial.c_cflag &= ~PARENB;            //奇偶校验 None
    myserial.c_cflag &= ~CSTOPB;			 //停止位
    myserial.c_cflag &= ~CRTSCTS;			 //无硬件控制流

    /* config RAW data mode input and output*/
    myserial.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/

    /*根据不同的波特率来设置串口*/
    switch(speed)
    {
        case 9600:
            cfsetospeed(&myserial,B9600);
            cfsetispeed(&myserial,B9600);
            break;
        case 19200:
        cfsetospeed(&myserial,B19200);
        cfsetispeed(&myserial,B19200);
            break;
        case 115200:
            cfsetospeed(&myserial,B115200);
            cfsetispeed(&myserial,B115200);
            break;
    }
    /*清空缓冲区*/
    tcflush(serial_fd,TCIOFLUSH);
    /*设置信息的激活时间*/
    tcsetattr(serial_fd,TCSANOW,&myserial);
    /*串口通信是基于设置好的串口进行的*/

    return serial_fd;
}

void serial::Serial_io(int fd, char *str)
{
    char data_read[1024] = {0};
    char buf[100] = {0};
    int ret;

    strcpy(buf, str);
    strcat(buf, "\r\n");

    ret = uart_send(fd,buf,strlen(buf));
    if(ret == -1)
    {
        printf("send error\n");
    }
    printf("send sucessfully:%d\n",ret);

    while(1)
    {
        ret = uart_read(fd, data_read, sizeof(data_read));
        if(ret > 0)
        {
            data_read[ret]='\0';
            printf("return:%s",data_read);
        }
        else
        {
            printf("can't receive data\n");
            break;
        }
    }
}

void serial::String_chg(char *buf, char *before)
{
    unsigned int i;

    strcpy(buf, before);
    for(i=0;i<strlen(buf);i++)
    {
        if(buf[i] == '*')
            buf[i] = 34;
    }
}

int serial::uart_read(int fd, char *buf_read, int buf_len)
{
    int len,fs_sel;
    fd_set fs_read;
    struct timeval time;

    FD_ZERO(&fs_read);
    FD_SET(fd,&fs_read);

    time.tv_sec = 10;
    time.tv_usec = 0;

    fs_sel = select(fd+1,&fs_read,NULL,NULL,&time);
    if(fs_sel)
    {
       len = read(fd,buf_read,buf_len);
       return len;
    }
    else
    {
        return -1;
    }
}

int serial::uart_send(int fd, char *buf_send, int buf_len)
{
    int len;
    len = write(fd,buf_send,buf_len);
    if(len == buf_len)
    {
        return len;
    }
    else
    {
        tcflush(fd,TCOFLUSH);
        printf("send error\n");
        return -1;
    }
}
