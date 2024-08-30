#include "bsp_spi_bus.h"

SPI_Status bsp_spi_init(spi_bus_type_t *bus)
{

}

SPI_Status bsp_spi_init_param(spi_bus_type_t *bus, uint32_t BandRatePrescaler, 
                                uint32_t CLKPhase, uint32_t CLKPolarity)
{

}

SPI_Status bsp_spi_enable(spi_bus_type_t *bus)
{

}

SPI_Status bsp_spi_disable(spi_bus_type_t *bus)
{

}

SPI_Status bsp_spi_transfer(spi_bus_type_t *bus, uint8_t * send_data, uint32_t size, uint32_t timeout)
{

}

SPI_Status bsp_spi_receive(spi_bus_type_t *bus, uint8_t * rev_data, uint32_t size, uint32_t timeout)
{

}

SPI_Status bsp_spi_transfer_by_dma(spi_bus_type_t *bus, uint8_t * send_data, uint32_t size)
{

}


