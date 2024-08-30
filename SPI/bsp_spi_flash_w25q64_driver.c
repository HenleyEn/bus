#include "bsp_spi_flash_w25q64_driver.h"
#include "bsp_spi_bus.h"

spi_bus_type_t spi_flash_w25q64;

// TODO
void bsp_w25q64_init(void)
{
	/* SPI config and CS congfig */
	spi_flash_w25q64.init(&spi_flash_w25q64);
}

void bsp_w25q64_set_cs(uint8_t level)
{
	if(level == 0)
	{
		spi_flash_w25q64.spi_busy_flag = 1;

		//TODO: fix param
		spi_flash_w25q64.init_param(&spi_flash_w25q64, 1,2,4);
		W25Qx_CS_HIGH();
	}
	else
	{	
		spi_flash_w25q64.spi_busy_flag = 0;
		W25Qx_CS_LOW();
	}

}

void bsp_w25q64_reset(void)
{
	uint8_t cmd[2] = {RESET_ENABLE_CMD, RESET_DEVICE_CMD};

	bsp_w25q64_set_cs(0); //set flash, cs = 0

	/* Send the reset command */
	spi_flash_w25q64.transfer(spi_flash_w25q64, &cmd, 2, W25Qx_TIMEOUT_VALUE);

	bsp_w25q64_set_cs(1); //cs = 1
}

uint32_t bsp_w25q64_read_id(void)
{
	uint8_t cmd = READ_JEDEC_ID_CMD;
	uint32_t uID;
	uint8_t id[4];

	bsp_w25q64_set_cs(0);

	/* Send the read ID command */
	spi_flash_w25q64.transfer(spi_flash_w25q64, &cmd, 1, W25Qx_TIMEOUT_VALUE);

	/* Reception of the data */
	spi_flash_w25q64.receive(spi_flash_w25q64, &id, 3,W25Qx_TIMEOUT_VALUE);
	
	bsp_w25q64_set_cs(1);
}

void bsp_w25q64_erase_chip(void)
{
}
void bsp_w25q64_erase_sector(uint32_t sector_addr)
{
}

void bsp_w25q64_write_page(uint8_t *pbuf, uint32_t write_add, uint16_t write_size)
{
}

uint8_t bsp_w25q64_write_buffer(uint8_t *pbuf, uint32_t write_addr, uint32_t write_size)
{
}

void bsp_w25q64_read_buffer(uint8_t *pbuf, uint32_t read_addr, uint32_t read_size)
{
}

spi_bus_type_t spi_flash_w25q64 = {
	// .hardware_config = &hspi,
	.spi_busy_flag = 0,
	.init = bsp_spi_init,
	.init_param = bsp_spi_init_param,
	.enable = bsp_spi_enable,
	.disable = bsp_spi_disable,
	.transfer = bsp_spi_transfer,
	.transfer_by_dma = bsp_spi_transfer,
	.receive = bsp_spi_receive,
};
