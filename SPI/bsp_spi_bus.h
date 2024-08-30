#ifndef BSP_SPI_BUS_H
#define BSP_SPI_BUS_H

#ifdef STM32F103
#include "stm32f10x.h"
#endif

#ifdef STM32F405
#include "stm32f4xx_hal.h"
#endif

typedef enum{BUS_SPI_ERROR = 0, BUS_SPI_OK = !BUS_SPI_ERROR}SPI_Status;

typedef struct 
{
    void* hspi;

    uint8_t spi_busy_flag;

    SPI_Status (*init)(spi_bus_type_t *bus);
    SPI_Status (*init_param)(spi_bus_type_t *bus, uint32_t BandRatePrescaler, 
                                uint32_t CLKPhase, uint32_t CLKPolarity);

    SPI_Status (*enable)(spi_bus_type_t *bus);
    SPI_Status (*disable)(spi_bus_type_t *bus);
    SPI_Status (*transfer)(spi_bus_type_t *bus, uint8_t * send_data, uint32_t size, uint32_t timeout);
    SPI_Status (*receive)(spi_bus_type_t *bus, uint8_t * rev_data, uint32_t size, uint32_t timeout);

    SPI_Status (*transfer_by_dma)(spi_bus_type_t *bus, uint8_t * send_data, uint32_t size);

}spi_bus_type_t;

SPI_Status bsp_spi_init(spi_bus_type_t *bus);
SPI_Status bsp_spi_init_param(spi_bus_type_t *bus, uint32_t BandRatePrescaler, 
                                uint32_t CLKPhase, uint32_t CLKPolarity);

SPI_Status bsp_spi_enable(spi_bus_type_t *bus);
SPI_Status bsp_spi_disable(spi_bus_type_t *bus);
SPI_Status bsp_spi_transfer(spi_bus_type_t *bus, uint8_t * send_data, uint32_t size, uint32_t timeout);
SPI_Status bsp_spi_receive(spi_bus_type_t *bus, uint8_t * rev_data, uint32_t size, uint32_t timeout);
SPI_Status bsp_spi_transfer_by_dma(spi_bus_type_t *bus, uint8_t * send_data, uint32_t size);

#endif  /* endif BSP_SPI_BUS_H */
