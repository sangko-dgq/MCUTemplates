/*
 * MIT License
 * Copyright (c) 2021 _VIFEXTech
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __HAL_H
#define __HAL_H

#include <stdint.h>
#include "HAL_Def.h"

#include <Arduino.h>
#include "HAL/Config/Config.h"
#include "CommonMacro.h"
#include "freeRTOS/FreeRTOS.h"  //@fix FreeRTOS => freeRTOS/FreeRTOS.h
#include "TFT_eSPI.h"
#include "M5Touch.h"
#include "TinyGPSPlus.h"
#include "MillisTaskManager.h"



extern TFT_eSPI tft;
extern TinyGPSPlus gps;

namespace HAL {
    
typedef bool (*CommitFunc_t)(void* info, void* userData);
    
void HAL_Init();
void HAL_Update();

/* Power */
void Power_Init();
void Power_HandleTimeUpdate();
void Power_SetAutoLowPowerTimeout(uint16_t sec);
uint16_t Power_GetAutoLowPowerTimeout();
void Power_SetAutoLowPowerEnable(bool en);
void Power_Shutdown();
void Power_Update();
void Power_EventMonitor();
void Power_GetInfo(Power_Info_t* info);
typedef void(*Power_CallbackFunction_t)(void);
void Power_SetEventCallback(Power_CallbackFunction_t callback);

/* LCD Backlight */
void Backlight_Init();
uint32_t Backlight_GetValue();
void Backlight_SetValue(int32_t val);
void Backlight_SetGradual(uint32_t target, uint16_t time = 500);
void Backlight_ForceLit(bool en);

/* Display */
void Display_Init();

/* Touch screen */
void Touch_Init();
bool Touch_Ispressed();
void Touch_GetPressPoint(TouchPoint_t* coordinate);

/* I2C */
int I2C_Scan();

/* IMU */
bool IMU_Init();
void IMU_SetCommitCallback(CommitFunc_t func, void* userData);
void IMU_Update();
    
/* SD */
bool SD_Init();
void SD_Update();
bool SD_GetReady();
float SD_GetCardSizeMB();
const char* SD_GetTypeName();
typedef void(*SD_CallbackFunction_t)(bool insert);
void SD_SetEventCallback(SD_CallbackFunction_t callback);

/* Clock */
void Clock_Init();
void Clock_GetInfo(Clock_Info_t* info);
void Clock_SetInfo(const Clock_Info_t* info);
const char* Clock_GetWeekString(uint8_t week);

/* GPS */
void GPS_Init();
void GPS_Update();
bool GPS_GetInfo(GPS_Info_t* info);
bool GPS_LocationIsValid();
double GPS_GetDistanceOffset(GPS_Info_t* info, double preLong, double preLat);

/* Buzzer */
void Buzz_init();
void Buzz_SetEnable(bool en);
void Buzz_Tone(uint32_t freq, int32_t duration = 0);

/* Encoder */
void Encoder_Init();
void Encoder_Update();
int32_t Encoder_GetDiff();
bool Encoder_GetIsPush();
void Encoder_SetEnable(bool en);

/* Audio */
void Audio_Init();
void Audio_Update();
bool Audio_PlayMusic(const char* name);

}

#endif