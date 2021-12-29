#ifndef APP_FIFO_H__
#define APP_FIFO_H__

#include <stdint.h>
#include <stdlib.h>



typedef struct
{
    uint8_t *          p_buf;           /*Pointer to FIFO buffer memory.                      */
    uint32_t           buf_size;        /*Read/write index mask. Also used for size checking. */
    volatile uint32_t  data_len;        /*Data length in fifo                                 */
    volatile uint32_t  read_pos;        /*Next read position in the FIFO buffer.              */
    volatile uint32_t  write_pos;       /*Next write position in the FIFO buffer.             */
} app_fifo_t;


#define FIFO_SUCCESS            (0)
#define FIFO_ERROR_NULL         (-1)
#define FIFO_ERROR_NO_MEM       (-2)






extern int32_t app_fifo_init(app_fifo_t * p_fifo, uint8_t * p_buf, uint16_t buf_size);
extern int32_t app_fifo_write(app_fifo_t * p_fifo, uint8_t * p_data, uint16_t data_size);
extern int32_t app_fifo_read(app_fifo_t * p_fifo, uint8_t * p_data, uint16_t data_size);
extern uint32_t app_fifo_data_len(app_fifo_t * p_fifo);
extern int32_t app_fifo_clear(app_fifo_t * p_fifo);
extern uint32_t app_fifo_usable(app_fifo_t * p_fifo);
extern int32_t app_fifo_del(app_fifo_t * p_fifo,uint16_t data_size);

#endif 
