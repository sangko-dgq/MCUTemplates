

#ifndef _HEADERS_H
#define _HEADERS_H

#include "../../lib/ArduinoJson/src/ArduinoJson.h"
#include "../../lib/Time-Library/TimeLib.h"
#include "../../lib/TFT_eSPI/TFT_eSPI.h"
#include "../../lib/TJpg_Decoder/src/TJpg_Decoder.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <EEPROM.h>

/*Extra*/
#include "../Extra/qr.h"
#include "../Extra/number.h"
#include "../Extra/weathernum.h"

/*Asset*/
#include "Asset/Asset.h"
#endif // !_HEADERS_H