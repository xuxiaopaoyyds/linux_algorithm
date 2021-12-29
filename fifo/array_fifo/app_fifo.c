#include <string.h>
#include "app_fifo.h"

int32_t app_fifo_init(app_fifo_t * p_fifo, uint8_t * p_buf, uint16_t buf_size)
{
    // Check buffer for null pointer.
    if ((p_fifo == NULL)||(p_buf == NULL))
    {
        return FIFO_ERROR_NULL;
    }

    p_fifo->p_buf         = p_buf;
    p_fifo->buf_size      = buf_size;
    p_fifo->read_pos      = 0;
    p_fifo->write_pos     = 0;
    p_fifo->data_len      = 0;
    
    return FIFO_SUCCESS;
}


int32_t app_fifo_write(app_fifo_t * p_fifo, uint8_t * p_data, uint16_t data_size)
{
    if ((p_fifo == NULL)||(p_data == NULL))
    {
        return FIFO_ERROR_NULL;
    }
    if((p_fifo->data_len+data_size) > p_fifo->buf_size )
    {
        return FIFO_ERROR_NO_MEM;
    }
    
    if((p_fifo->write_pos + data_size) < p_fifo->buf_size)
    {
        memcpy(&p_fifo->p_buf[p_fifo->write_pos],p_data,data_size);
        p_fifo->write_pos += data_size;
    }
    else
    {
        uint16_t len = p_fifo->buf_size - p_fifo->write_pos;
        memcpy(&p_fifo->p_buf[p_fifo->write_pos],p_data,len);
        p_fifo->write_pos = data_size - len;
        memcpy(&p_fifo->p_buf[0],&p_data[len],p_fifo->write_pos);
    }
    p_fifo->data_len += data_size;

    return FIFO_SUCCESS;
}


int32_t app_fifo_read(app_fifo_t * p_fifo, uint8_t * p_data, uint16_t data_size)
{
    if ((p_fifo == NULL)||(p_data == NULL))
    {
        return FIFO_ERROR_NULL;
    }
    if( p_fifo->data_len == 0)
    {
        return FIFO_SUCCESS;
    }
    if(p_fifo->data_len < data_size)
    {
        data_size = p_fifo->data_len;
    }
    //printf("%d,%d,%d,%d,%d,",p_fifo->buf_size,p_fifo->data_len,data_size,p_fifo->read_pos,p_fifo->write_pos);
    //if(p_fifo->read_pos <= p_fifo->write_pos)
    if((p_fifo->read_pos+data_size) <= p_fifo->buf_size)
    {
        memcpy(p_data,&p_fifo->p_buf[p_fifo->read_pos],data_size);
        p_fifo->read_pos += data_size;
        //printf("  1");
    }
    else
    {    
        uint16_t len = p_fifo->buf_size - p_fifo->read_pos;
        memcpy(p_data,&p_fifo->p_buf[p_fifo->read_pos],len);
        memcpy(&p_data[len],&p_fifo->p_buf[0],data_size - len);
        p_fifo->read_pos = data_size - len;
        
    }
    //printf("\r\n");
    p_fifo->data_len -= data_size;
    return data_size;
}

int32_t app_fifo_del(app_fifo_t * p_fifo,uint16_t data_size)
{
    if ((p_fifo == NULL))
    {
        return FIFO_ERROR_NULL;
    }
    if( p_fifo->data_len == 0)
    {
        return FIFO_SUCCESS;
    }
    if(p_fifo->data_len < data_size)
    {
        data_size = p_fifo->data_len;
    }
    //printf("%d,%d,%d,%d,%d,",p_fifo->buf_size,p_fifo->data_len,data_size,p_fifo->read_pos,p_fifo->write_pos);
    //if(p_fifo->read_pos <= p_fifo->write_pos)
    if((p_fifo->read_pos+data_size) <= p_fifo->buf_size)
    {
        //memcpy(p_data,&p_fifo->p_buf[p_fifo->read_pos],data_size);
        p_fifo->read_pos += data_size;
        //printf("  1");
    }
    else
    {    
        uint16_t len = p_fifo->buf_size - p_fifo->read_pos;
        //memcpy(p_data,&p_fifo->p_buf[p_fifo->read_pos],len);
        //memcpy(&p_data[len],&p_fifo->p_buf[0],data_size - len);
        p_fifo->read_pos = data_size - len;
        
    }
    //printf("\r\n");
    p_fifo->data_len -= data_size;
    return data_size;
}



int32_t app_fifo_read_no_del(app_fifo_t * p_fifo, uint8_t * p_data, uint16_t data_size)
{
    if ((p_fifo == NULL)||(p_data == NULL))
    {
        return FIFO_ERROR_NULL;
    }
    if( p_fifo->data_len == 0)
    {
        return FIFO_SUCCESS;
    }
    if(p_fifo->data_len < data_size)
    {
        data_size = p_fifo->data_len;
    }
    if((p_fifo->read_pos+data_size) <= p_fifo->buf_size)
    {
        memcpy(p_data,&p_fifo->p_buf[p_fifo->read_pos],data_size);
        //p_fifo->read_pos += data_size;
    }
    else
    {    
        uint16_t len = p_fifo->buf_size - p_fifo->read_pos;
        memcpy(p_data,&p_fifo->p_buf[p_fifo->read_pos],len);
        memcpy(&p_data[len],&p_fifo->p_buf[0],data_size - len);
        //p_fifo->read_pos = data_size - len;
        
    }
    //p_fifo->data_len -= data_size;
    return data_size;
}

uint32_t app_fifo_usable(app_fifo_t * p_fifo)
{
    return (p_fifo->buf_size - p_fifo->data_len);
}

uint32_t app_fifo_data_len(app_fifo_t * p_fifo)
{
    return p_fifo->data_len;
}
int32_t app_fifo_clear(app_fifo_t * p_fifo)
{
    if (p_fifo == NULL)
    {
        return FIFO_ERROR_NULL;
    }
    
    p_fifo->read_pos      = 0;
    p_fifo->write_pos     = 0;
    p_fifo->data_len      = 0;
    return FIFO_SUCCESS;
}    



