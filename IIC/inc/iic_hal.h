#ifndef IIC_HAL_H
#define IIC_HAL_H

#define HIGH    1
#define LOW     0


#define IIC_PortTypedef GPIO_TypeDef
#define IIC_MutexTypedef 

typedef struct
{
	IIC_PortTypedef * IIC_SDA_PORT;
	IIC_PortTypedef * IIC_SCL_PORT;
	uint16_t IIC_SDA_PIN;
	uint16_t IIC_SCL_PIN;

#ifdef SUPPORT_OS
    IIC_MutexTypedef * mutex;
#else
    uint8_t mutex_flag;
#endif /* SUPPORT_OS */

    void (*delay_us)(uint8_t us);

}iic_bus_t;


#endif /* endif IIC_HAL_H */
