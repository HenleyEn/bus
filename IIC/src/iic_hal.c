#include "iic_hal.h"

static void iic_SDAInputMode(iic_bus_t *bus)
{
}

static void iic_SDAOutputMode(iic_bus_t *bus)
{
}

static void iic_SDAOutputBit(iic_bus_t *bus, uint8_t val)
{
}

static uint8_t iic_SDAInputBit(iic_bus_t *bus)
{
}

static iic_SCLOutputBit(iic_bus_t *bus, uint8_t val)
{
}

void iic_Start(iic_bus_t *bus)
{
    iic_SDAOutputBit(bus, HIGH);
    bus->delay_us(2);
    iic_SCLOutputBit(bus, HIGH);
    bus->delay_us(1);

    iic_SDAOutputBit(bus, LOW);
    bus->delay_us(1);
    iic_SCLOutputBit(bus, LOW);
    bus->delay_us(1);
}

void iic_Stop(iic_bus_t *bus)
{
    iic_SCLOutputBit(bus, LOW);
    bus->delay_us(2);
    iic_SDAOutputBit(bus, LOW);
    bus->delay_us(1);

    iic_SCLOutputBit(bus, HIGH);
    bus->delay_us(1);
    iic_SDAOutputBit(bus, HIGH);
    bus->delay_us(1);
}

uint8_t iic_WaitAck(iic_bus_t *bus)
{
    unsigned short cErrTime = 5;

    iic_SDAInputMode(bus);
    iic_SCLOutputBit(bus, HIGH);

    while (iic_SDAInputBit(bus))
    {
        cErrTime--;

        bus->delay_us(1);

        if (0 == cErrTime)
        {
            iic_SDAOutputMode(bus);
            iic_Stop(bus);
            return ERROR;
        }
    }

    iic_SDAOutputMode(bus);
    iic_SCLOutputBit(bus, LOW);
    bus->delay_us(2);

    return SUCCESS;
}

void iic_SendAck(iic_bus_t *bus)
{
    iic_SDAOutputBit(bus, LOW);
    bus->delay_us(1);
    iic_SCLOutputBit(bus, HIGH);
    bus->delay_us(1);

    iic_SCLOutputBit(bus, LOW);
    bus->delay_us(1);
}

void iic_SendAck(iic_bus_t *bus)
{
    iic_SDAOutputBit(bus, HIGH);
    bus->delay_us(1);
    iic_SCLOutputBit(bus, HIGH);
    bus->delay_us(1);

    iic_SCLOutputBit(bus, LOW);
    bus->delay_us(2);
}

void iic_SendByte(iic_bus_t *bus, unsigned char cSendByte)
{
    unsigned char i = 8;

    while (i--)
    {
        iic_SCLOutputBit(bus, LOW);
        bus->delay_us(2);
        iic_SDAOutputBit(bus, cSendByte & 0x80);
        bus->delay_us(1);

        cSendByte += cSendByte;

        bus->delay_us(1);
        iic_SCLOutputBit(bus, 1);
        bus->delay_us(1);
    }
    iic_SCLOutputBit(bus, 0);
    bus->delay_us(2);
}

unsigned char IICReceiveByte(iic_bus_t *bus)
{
    unsigned char i = 8;
    unsigned char cR_Byte = 0;
    SDA_Input_Mode(bus);
    while (i--)
    {
        cR_Byte += cR_Byte;
        SCL_Output(bus, 0);
        delay_us(2);
        SCL_Output(bus, 1);
        delay_us(1);
        cR_Byte |= SDA_Input(bus);
    }
    SCL_Output(bus, 0);
    SDA_Output_Mode(bus);
    return cR_Byte;
}
void iic_init(iic_bus_t *bus)
{
}

void iic_deinit(iic_bus_t *bus)
{
}
