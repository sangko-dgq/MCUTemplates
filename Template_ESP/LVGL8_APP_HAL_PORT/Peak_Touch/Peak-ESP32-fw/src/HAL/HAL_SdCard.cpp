#include "HAL/HAL.h"
#include "SPI.h"
#include "SD.h"

bool HAL::SD_Init()
{
    /*初始化*/
    pinMode(CONFIG_SD_DET_PIN, INPUT);

    SPIClass *sd_spi = new SPIClass(CONFIG_SD_SPI);     // another SPI
    if (!SD.begin(CONFIG_SD_CS_PIN, *sd_spi, 80000000)) // SD-Card SS pin is 15
    {
        Serial.println("Card Mount Failed");
        return false;
    }

    /*检测SD卡是否插入*/
    uint8_t cardType = SD.cardType();

    /*没有检测到SD卡*/
    if (cardType == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return false;
    }

    /*成功检测到SD卡*/
    Serial.print("SD Card Type: ");
    if (cardType == CARD_MMC)
    {
        Serial.println("MMC");
    }
    else if (cardType == CARD_SD)
    {
        Serial.println("SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
        Serial.println("SDHC");
    }
    else
    {
        Serial.println("UNKNOWN");
    }

    /*打印SD卡容量*/
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);
    return true;
}

bool HAL::SD_GetReady()
{
    return !digitalRead(CONFIG_SD_DET_PIN);
}

float HAL::SD_GetCardSizeMB()
{
    return 32 * 1024;
}

static void SD_Check(bool isInsert)
{
}

void HAL::SD_SetEventCallback(SD_CallbackFunction_t callback)
{
}

void HAL::SD_Update()
{
}
