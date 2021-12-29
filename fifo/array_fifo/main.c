/*************************************************************************
	> File Name: main.c
	> Author: xufeng
	> Mail: xuxiaopaoyyds@github.com
	> Created Time: Tue 28 Dec 2021 12:30:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include "app_fifo.h"

unsigned char fifo[1024];
app_fifo_t g_p_fifo;

int main(int argc, char **argv)
{
    int ret = -1;

    unsigned char buff_w[20] = {0};
    unsigned char buff_r[20] = {0};
    int len = 0;

    printf("array fifo test\n");

    ret =  app_fifo_init(&g_p_fifo, fifo, sizeof(fifo));

    printf("init ret = %d\n", ret);
    buff_w[0] = 1;
    ret = app_fifo_write(&g_p_fifo, buff_w, 1);
    printf("write ret = %d\n", ret);
    buff_w[0] = 2;
    ret = app_fifo_write(&g_p_fifo, buff_w, 1);

    printf("write ret = %d\n", ret);
    
    len = app_fifo_read(&g_p_fifo, buff_r, sizeof(buff_r));
    printf("len = %d\n", len);
    printf("buff_r[0] = %d, buff_r[1] = %d\n", buff_r[0], buff_r[1]);


    return 0;
}
