/*******************************************************************************
 * Size: 16 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef SARASA_MONO_SC_REGULAR_16
#define SARASA_MONO_SC_REGULAR_16 1
#endif

#if SARASA_MONO_SC_REGULAR_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002A "*" */
    0x0, 0x9, 0x90, 0x0, 0x0, 0x9, 0x90, 0x0,
    0x3e, 0x8a, 0xa8, 0xe3, 0x4, 0x9f, 0xf9, 0x40,
    0x0, 0x5e, 0xe5, 0x0, 0x2, 0xf4, 0x4f, 0x20,
    0x1, 0x60, 0x6, 0x10,

    /* U+002C "," */
    0x7, 0x70, 0x3f, 0xf3, 0x1d, 0xf2, 0x3, 0xe0,
    0xb, 0x80, 0x3e, 0x10, 0x1, 0x0,

    /* U+002D "-" */
    0xff, 0xff, 0xff, 0x22, 0x22, 0x22,

    /* U+002E "." */
    0x7, 0x70, 0x3f, 0xf3, 0x1d, 0xd1,

    /* U+0030 "0" */
    0x0, 0x9e, 0xe9, 0x0, 0xa, 0xd5, 0x5d, 0xa0,
    0xf, 0x40, 0x4, 0xf0, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x1c, 0xf1, 0x1f, 0x24, 0xea, 0xf1,
    0x1f, 0x9e, 0x52, 0xf1, 0x1f, 0xd2, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0xf, 0x40, 0x4, 0xf0,
    0xb, 0xd4, 0x4d, 0xa0, 0x1, 0xaf, 0xfa, 0x10,

    /* U+0031 "1" */
    0x0, 0x1b, 0xf1, 0x4, 0xec, 0xf1, 0xc, 0x72,
    0xf1, 0x0, 0x2, 0xf1, 0x0, 0x2, 0xf1, 0x0,
    0x2, 0xf1, 0x0, 0x2, 0xf1, 0x0, 0x2, 0xf1,
    0x0, 0x2, 0xf1, 0x0, 0x2, 0xf1, 0x0, 0x2,
    0xf1, 0x0, 0x2, 0xf1,

    /* U+0032 "2" */
    0x1, 0xaf, 0xfa, 0x10, 0xa, 0xd4, 0x4d, 0xa0,
    0xf, 0x50, 0x5, 0xf0, 0x0, 0x0, 0x3, 0xf0,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x4f, 0x40,
    0x0, 0x7, 0xf5, 0x0, 0x0, 0x8e, 0x30, 0x0,
    0x4, 0xf3, 0x0, 0x0, 0xa, 0xa0, 0x0, 0x0,
    0xe, 0x72, 0x22, 0x20, 0xf, 0xff, 0xff, 0xf0,

    /* U+0033 "3" */
    0x0, 0xaf, 0xfa, 0x10, 0x9, 0xd4, 0x4d, 0xa0,
    0xa, 0x50, 0x5, 0xe0, 0x0, 0x0, 0x6, 0xd0,
    0x0, 0x0, 0x3e, 0x60, 0x0, 0x2f, 0xf8, 0x0,
    0x0, 0x3, 0x7f, 0x50, 0x0, 0x0, 0x5, 0xe0,
    0x1, 0x0, 0x0, 0xf2, 0x1f, 0x30, 0x2, 0xf2,
    0xb, 0xc4, 0x4c, 0xc0, 0x1, 0xaf, 0xfa, 0x10,

    /* U+0034 "4" */
    0x0, 0x0, 0x9c, 0x0, 0x0, 0x1f, 0x40, 0x0,
    0x8, 0xd0, 0x0, 0x0, 0xf5, 0x0, 0x0, 0x7e,
    0x26, 0x0, 0xe, 0x64, 0xf0, 0x6, 0xe0, 0x4f,
    0x0, 0xd7, 0x4, 0xf0, 0x1f, 0xff, 0xff, 0xf0,
    0x22, 0x26, 0xf2, 0x0, 0x0, 0x4f, 0x0, 0x0,
    0x4, 0xf0,

    /* U+0035 "5" */
    0xdf, 0xff, 0xfa, 0xd, 0x72, 0x22, 0x10, 0xd6,
    0x0, 0x0, 0xd, 0x60, 0x0, 0x0, 0xdc, 0xee,
    0x90, 0xd, 0xe4, 0x4e, 0x80, 0xb6, 0x0, 0x6e,
    0x0, 0x0, 0x2, 0xf1, 0x0, 0x0, 0x2f, 0x1d,
    0x50, 0x6, 0xe0, 0x8e, 0x44, 0xe8, 0x0, 0x9f,
    0xe9, 0x0,

    /* U+0036 "6" */
    0x0, 0x4, 0xf1, 0x0, 0x0, 0xc, 0x70, 0x0,
    0x0, 0x4d, 0x0, 0x0, 0x0, 0xc5, 0x0, 0x0,
    0x3, 0xfe, 0xe9, 0x0, 0xa, 0xe4, 0x4e, 0x80,
    0xe, 0x60, 0x6, 0xe0, 0xf, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0xe, 0x50, 0x6, 0xe0,
    0x8, 0xe4, 0x4e, 0x80, 0x0, 0x9e, 0xe9, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0x22, 0x22, 0x8d, 0x0, 0x0,
    0xb8, 0x0, 0x0, 0xf3, 0x0, 0x5, 0xe0, 0x0,
    0xa, 0xa0, 0x0, 0xf, 0x50, 0x0, 0x4f, 0x0,
    0x0, 0x9b, 0x0, 0x0, 0xe6, 0x0, 0x3, 0xf1,
    0x0, 0x8, 0xc0, 0x0,

    /* U+0038 "8" */
    0x0, 0xaf, 0xfa, 0x0, 0x9, 0xd4, 0x4e, 0x90,
    0xd, 0x70, 0x7, 0xd0, 0xb, 0x80, 0x8, 0xb0,
    0x4, 0xe2, 0x2f, 0x30, 0x0, 0x6e, 0xe6, 0x0,
    0x0, 0xbd, 0xda, 0x0, 0x8, 0xd1, 0x1d, 0x80,
    0xf, 0x40, 0x5, 0xf0, 0x1f, 0x30, 0x3, 0xf0,
    0xc, 0xc3, 0x3c, 0xc0, 0x1, 0xbf, 0xfb, 0x10,

    /* U+0039 "9" */
    0x0, 0x9f, 0xe9, 0x0, 0x9, 0xd4, 0x4d, 0x80,
    0xf, 0x40, 0x5, 0xe0, 0x1f, 0x20, 0x2, 0xf1,
    0xf, 0x30, 0x4, 0xf0, 0xb, 0xb1, 0x1c, 0xe0,
    0x1, 0xcf, 0xff, 0x90, 0x0, 0x1, 0x4f, 0x30,
    0x0, 0x0, 0xac, 0x0, 0x0, 0x2, 0xf4, 0x0,
    0x0, 0xa, 0xc0, 0x0, 0x0, 0x1f, 0x40, 0x0,

    /* U+003A ":" */
    0x1d, 0xd1, 0x3f, 0xf3, 0x7, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0x70, 0x3f, 0xf3,
    0x1d, 0xd1,

    /* U+0040 "@" */
    0xa, 0xff, 0x90, 0x9d, 0x44, 0xd8, 0xe5, 0x0,
    0x5e, 0xf4, 0x1d, 0xff, 0xf4, 0x8c, 0x6f, 0xf4,
    0xa9, 0x4f, 0xf4, 0xa9, 0x4f, 0xf4, 0xa9, 0x4f,
    0xf4, 0xa9, 0x4f, 0xf4, 0x9b, 0x6e, 0xe5, 0x2f,
    0xf7, 0xac, 0x10, 0x10, 0x1d, 0xff, 0xf6, 0x0,
    0x12, 0x21,

    /* U+0041 "A" */
    0x0, 0xd, 0xd0, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x4e, 0xe4, 0x0, 0x0, 0x7b, 0xb7, 0x0,
    0x0, 0xa8, 0x8a, 0x0, 0x0, 0xe5, 0x5e, 0x0,
    0x1, 0xf2, 0x2f, 0x10, 0x5, 0xe0, 0xf, 0x50,
    0x8, 0xff, 0xff, 0x80, 0xc, 0x92, 0x29, 0xc0,
    0xf, 0x50, 0x5, 0xf0, 0x3f, 0x10, 0x1, 0xf3,

    /* U+0042 "B" */
    0xff, 0xfe, 0x80, 0xf, 0x62, 0x5f, 0x70, 0xf4,
    0x0, 0x8c, 0xf, 0x40, 0x7, 0xc0, 0xf4, 0x2,
    0xe7, 0xf, 0xff, 0xfb, 0x0, 0xf6, 0x24, 0xd9,
    0xf, 0x40, 0x3, 0xf1, 0xf4, 0x0, 0xf, 0x3f,
    0x40, 0x3, 0xf1, 0xf6, 0x24, 0xdb, 0xf, 0xff,
    0xe9, 0x10,

    /* U+0043 "C" */
    0x1, 0xaf, 0xfa, 0x10, 0xb, 0xd4, 0x4d, 0xa0,
    0xf, 0x40, 0x4, 0xe0, 0x1f, 0x20, 0x0, 0x0,
    0x1f, 0x20, 0x0, 0x0, 0x1f, 0x20, 0x0, 0x0,
    0x1f, 0x20, 0x0, 0x0, 0x1f, 0x20, 0x0, 0x0,
    0x1f, 0x20, 0x0, 0x0, 0xf, 0x40, 0x5, 0xe0,
    0xb, 0xd4, 0x4d, 0xa0, 0x1, 0xaf, 0xfa, 0x10,

    /* U+0044 "D" */
    0xff, 0xfd, 0x80, 0xf, 0x62, 0x5e, 0x80, 0xf4,
    0x0, 0x5f, 0xf, 0x40, 0x2, 0xf1, 0xf4, 0x0,
    0x2f, 0x1f, 0x40, 0x2, 0xf1, 0xf4, 0x0, 0x2f,
    0x1f, 0x40, 0x2, 0xf1, 0xf4, 0x0, 0x2f, 0x1f,
    0x40, 0x5, 0xf0, 0xf6, 0x25, 0xe9, 0xf, 0xff,
    0xe8, 0x0,

    /* U+0045 "E" */
    0xdf, 0xff, 0xff, 0xd8, 0x22, 0x22, 0xd6, 0x0,
    0x0, 0xd6, 0x0, 0x0, 0xd6, 0x0, 0x0, 0xdf,
    0xff, 0xf1, 0xd8, 0x22, 0x20, 0xd6, 0x0, 0x0,
    0xd6, 0x0, 0x0, 0xd6, 0x0, 0x0, 0xd8, 0x22,
    0x22, 0xdf, 0xff, 0xff,

    /* U+0046 "F" */
    0x7f, 0xff, 0xff, 0x7d, 0x22, 0x22, 0x7c, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x7f,
    0xff, 0xf1, 0x7d, 0x22, 0x20, 0x7c, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0x7c, 0x0, 0x0,

    /* U+0047 "G" */
    0x1, 0xaf, 0xfa, 0x10, 0xb, 0xd4, 0x4d, 0xa0,
    0xf, 0x40, 0x3, 0xb0, 0x1f, 0x20, 0x0, 0x0,
    0x1f, 0x20, 0x0, 0x0, 0x1f, 0x20, 0xff, 0xf0,
    0x1f, 0x20, 0x26, 0xf0, 0x1f, 0x20, 0x4, 0xf0,
    0x1f, 0x20, 0x4, 0xf0, 0xf, 0x40, 0x6, 0xf0,
    0xc, 0xd4, 0x4a, 0xf0, 0x2, 0xcf, 0xb3, 0xf0,

    /* U+0048 "H" */
    0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0,
    0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xff,
    0xff, 0xff, 0xf6, 0x22, 0x6f, 0xf4, 0x0, 0x4f,
    0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0,
    0x4f, 0xf4, 0x0, 0x4f,

    /* U+0049 "I" */
    0xcf, 0xff, 0xfc, 0x22, 0xbb, 0x22, 0x0, 0xaa,
    0x0, 0x0, 0xaa, 0x0, 0x0, 0xaa, 0x0, 0x0,
    0xaa, 0x0, 0x0, 0xaa, 0x0, 0x0, 0xaa, 0x0,
    0x0, 0xaa, 0x0, 0x0, 0xaa, 0x0, 0x22, 0xbb,
    0x22, 0xcf, 0xff, 0xfc,

    /* U+004A "J" */
    0x0, 0xd, 0xff, 0x90, 0x0, 0x22, 0xb9, 0x0,
    0x0, 0xa, 0x90, 0x0, 0x0, 0xa9, 0x0, 0x0,
    0xa, 0x90, 0x0, 0x0, 0xa9, 0x0, 0x0, 0xa,
    0x90, 0x0, 0x0, 0xa9, 0x0, 0x0, 0xa, 0x93,
    0xf1, 0x0, 0xc8, 0xe, 0xa3, 0x7f, 0x30, 0x2c,
    0xfd, 0x50,

    /* U+004B "K" */
    0xb8, 0x0, 0x9d, 0xb, 0x80, 0x2f, 0x40, 0xb8,
    0xb, 0xa0, 0xb, 0x85, 0xf1, 0x0, 0xb8, 0xd7,
    0x0, 0xb, 0xef, 0x10, 0x0, 0xbf, 0xf7, 0x0,
    0xb, 0xb6, 0xe0, 0x0, 0xb8, 0xe, 0x60, 0xb,
    0x80, 0x7e, 0x0, 0xb8, 0x0, 0xe6, 0xb, 0x80,
    0x7, 0xd0,

    /* U+004C "L" */
    0x7c, 0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x7c,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0x7, 0xc0, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x7,
    0xc0, 0x0, 0x0, 0x7d, 0x22, 0x22, 0x7, 0xff,
    0xff, 0xf1,

    /* U+004D "M" */
    0x3f, 0x60, 0x6, 0xf3, 0x3f, 0xa0, 0xa, 0xf3,
    0x3e, 0xe0, 0xe, 0xe3, 0x3e, 0xc2, 0x3c, 0xe3,
    0x3e, 0x87, 0x78, 0xf3, 0x3f, 0x3b, 0xb3, 0xf3,
    0x3f, 0xe, 0xe0, 0xf3, 0x3f, 0xb, 0xb0, 0xf3,
    0x3f, 0x3, 0x30, 0xf3, 0x3f, 0x0, 0x0, 0xf3,
    0x3f, 0x0, 0x0, 0xf3, 0x3f, 0x0, 0x0, 0xf3,

    /* U+004E "N" */
    0xfb, 0x0, 0x4f, 0xff, 0x10, 0x4f, 0xfd, 0x60,
    0x4f, 0xf9, 0xb0, 0x4f, 0xf4, 0xf1, 0x4f, 0xf3,
    0xb6, 0x4f, 0xf4, 0x6b, 0x3f, 0xf4, 0x1f, 0x4f,
    0xf4, 0xb, 0x9f, 0xf4, 0x6, 0xef, 0xf4, 0x1,
    0xff, 0xf4, 0x0, 0xbf,

    /* U+004F "O" */
    0x0, 0x9e, 0xe9, 0x0, 0xa, 0xd5, 0x5d, 0xa0,
    0xf, 0x40, 0x4, 0xf0, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0xf, 0x40, 0x4, 0xf0,
    0xb, 0xc4, 0x4d, 0xb0, 0x1, 0xaf, 0xfa, 0x10,

    /* U+0050 "P" */
    0xbf, 0xff, 0xa1, 0xb, 0x92, 0x4c, 0xb0, 0xb8,
    0x0, 0x2f, 0x1b, 0x80, 0x0, 0xf3, 0xb8, 0x0,
    0x2f, 0x2b, 0x80, 0x1a, 0xd0, 0xbf, 0xff, 0xd2,
    0xb, 0x92, 0x20, 0x0, 0xb8, 0x0, 0x0, 0xb,
    0x80, 0x0, 0x0, 0xb8, 0x0, 0x0, 0xb, 0x80,
    0x0, 0x0,

    /* U+0051 "Q" */
    0x0, 0x9e, 0xe9, 0x0, 0xa, 0xd5, 0x5d, 0xa0,
    0xf, 0x40, 0x4, 0xf0, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0x1f, 0x20, 0x2, 0xf1,
    0xe, 0x70, 0x7, 0xe0, 0x6, 0xfa, 0xaf, 0x60,
    0x0, 0x3c, 0xd3, 0x0, 0x0, 0x6, 0xe2, 0x0,
    0x0, 0x0, 0xbf, 0xb0, 0x0, 0x0, 0x1, 0x10,

    /* U+0052 "R" */
    0xff, 0xff, 0xa0, 0xf, 0x62, 0x4d, 0x90, 0xf4,
    0x0, 0x4f, 0xf, 0x40, 0x2, 0xf1, 0xf4, 0x0,
    0x4f, 0xf, 0x40, 0x1b, 0xb0, 0xff, 0xff, 0xd1,
    0xf, 0x65, 0xf2, 0x0, 0xf4, 0xb, 0x90, 0xf,
    0x40, 0x3f, 0x20, 0xf4, 0x0, 0xba, 0xf, 0x40,
    0x2, 0xf2,

    /* U+0053 "S" */
    0x0, 0xaf, 0xfa, 0x10, 0x9, 0xd4, 0x4d, 0xa0,
    0xe, 0x50, 0x5, 0xe0, 0xe, 0x50, 0x0, 0x0,
    0x9, 0xd1, 0x0, 0x0, 0x0, 0xbe, 0x70, 0x0,
    0x0, 0x6, 0xed, 0x10, 0x0, 0x0, 0xb, 0xb0,
    0x0, 0x0, 0x3, 0xf0, 0x1e, 0x20, 0x4, 0xf0,
    0xc, 0xc3, 0x4d, 0xb0, 0x1, 0xbf, 0xfa, 0x10,

    /* U+0054 "T" */
    0x2f, 0xff, 0xff, 0xf2, 0x2, 0x2b, 0xb2, 0x20,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,

    /* U+0055 "U" */
    0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0,
    0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4,
    0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f,
    0xf4, 0x0, 0x4f, 0xe6, 0x0, 0x6e, 0x9d, 0x44,
    0xd9, 0x9, 0xff, 0x90,

    /* U+0056 "V" */
    0x3f, 0x10, 0x1, 0xf3, 0xf, 0x40, 0x4, 0xf0,
    0xc, 0x70, 0x7, 0xc0, 0x8, 0xa0, 0xa, 0x80,
    0x5, 0xe0, 0xe, 0x50, 0x1, 0xf1, 0x1f, 0x10,
    0x0, 0xe4, 0x4e, 0x0, 0x0, 0xa7, 0x7a, 0x0,
    0x0, 0x7a, 0xb7, 0x0, 0x0, 0x4e, 0xe4, 0x0,
    0x0, 0xf, 0xf0, 0x0, 0x0, 0xd, 0xd0, 0x0,

    /* U+0057 "W" */
    0x6c, 0x0, 0x0, 0xc6, 0x5e, 0x0, 0x0, 0xe5,
    0x3f, 0x0, 0x0, 0xf3, 0x1f, 0xa, 0xa0, 0xf1,
    0xf, 0x1c, 0xc1, 0xf0, 0xd, 0x2e, 0xe2, 0xd0,
    0xb, 0x4d, 0xd4, 0xb0, 0xa, 0x7b, 0xb7, 0xa0,
    0x8, 0xa9, 0x9a, 0x80, 0x6, 0xd7, 0x7d, 0x60,
    0x4, 0xf4, 0x5f, 0x40, 0x2, 0xf2, 0x2f, 0x20,

    /* U+0058 "X" */
    0x1f, 0x40, 0x4, 0xf1, 0xa, 0xb0, 0xb, 0xa0,
    0x3, 0xf2, 0x2f, 0x30, 0x0, 0xb9, 0x9c, 0x0,
    0x0, 0x4f, 0xf5, 0x0, 0x0, 0xd, 0xd0, 0x0,
    0x0, 0xd, 0xd0, 0x0, 0x0, 0x5f, 0xf4, 0x0,
    0x0, 0xc9, 0x9b, 0x0, 0x3, 0xf2, 0x2f, 0x20,
    0xa, 0xb0, 0xb, 0x90, 0x1f, 0x40, 0x4, 0xf1,

    /* U+0059 "Y" */
    0x2f, 0x30, 0x3, 0xf2, 0xc, 0x80, 0x9, 0xc0,
    0x6, 0xe0, 0xe, 0x60, 0x0, 0xf4, 0x4f, 0x0,
    0x0, 0xaa, 0xaa, 0x0, 0x0, 0x4f, 0xf4, 0x0,
    0x0, 0xe, 0xe0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0xa, 0xa0, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xff, 0x22, 0x22, 0xbc, 0x0, 0x1,
    0xf5, 0x0, 0x8, 0xd0, 0x0, 0x1f, 0x60, 0x0,
    0x7e, 0x0, 0x0, 0xe7, 0x0, 0x6, 0xf1, 0x0,
    0xd, 0x80, 0x0, 0x5f, 0x10, 0x0, 0xcb, 0x22,
    0x22, 0xff, 0xff, 0xff,

    /* U+0061 "a" */
    0x1, 0xaf, 0xfa, 0x10, 0xbc, 0x44, 0xda, 0xb,
    0x30, 0x5, 0xe0, 0x0, 0x0, 0x4f, 0x2, 0xae,
    0xff, 0xf0, 0xdb, 0x42, 0x6f, 0x1f, 0x20, 0x5,
    0xf0, 0xfa, 0x35, 0xcf, 0x5, 0xef, 0xb5, 0xf0,

    /* U+0062 "b" */
    0xf4, 0x0, 0x0, 0xf, 0x40, 0x0, 0x0, 0xf4,
    0x0, 0x0, 0xf, 0x5b, 0xfc, 0x10, 0xfc, 0x44,
    0xdb, 0xf, 0x60, 0x4, 0xf0, 0xf4, 0x0, 0x2f,
    0x1f, 0x40, 0x2, 0xf1, 0xf4, 0x0, 0x2f, 0x1f,
    0x60, 0x4, 0xf0, 0xfc, 0x44, 0xdb, 0xf, 0x5c,
    0xfc, 0x10,

    /* U+0063 "c" */
    0x1, 0xaf, 0xe9, 0x0, 0xa, 0xd4, 0x4d, 0x90,
    0xf, 0x40, 0x5, 0xf0, 0x1f, 0x20, 0x0, 0x10,
    0x1f, 0x20, 0x0, 0x0, 0x1f, 0x20, 0x0, 0x0,
    0xf, 0x40, 0x5, 0xf0, 0xa, 0xd4, 0x4d, 0xa0,
    0x1, 0xaf, 0xfa, 0x0,

    /* U+0064 "d" */
    0x0, 0x0, 0x4, 0xf0, 0x0, 0x0, 0x4f, 0x0,
    0x0, 0x4, 0xf0, 0x1c, 0xfb, 0x5f, 0xb, 0xd4,
    0x4c, 0xf0, 0xf4, 0x0, 0x6f, 0x1f, 0x20, 0x4,
    0xf1, 0xf2, 0x0, 0x4f, 0x1f, 0x20, 0x4, 0xf0,
    0xf4, 0x0, 0x6f, 0xb, 0xd4, 0x4c, 0xf0, 0x1c,
    0xfc, 0x5f,

    /* U+0065 "e" */
    0x0, 0xaf, 0xfa, 0x0, 0xa, 0xd4, 0x4d, 0xa0,
    0xf, 0x40, 0x4, 0xf0, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0xff, 0xff, 0xf1, 0x1f, 0x42, 0x22, 0x20,
    0xf, 0x40, 0x1, 0x70, 0xa, 0xd4, 0x3b, 0xc0,
    0x0, 0xaf, 0xfb, 0x10,

    /* U+0066 "f" */
    0x0, 0x5e, 0xe6, 0x0, 0xf, 0x76, 0xf1, 0x3,
    0xf0, 0x7, 0x10, 0x3f, 0x0, 0x0, 0xff, 0xff,
    0xfa, 0x2, 0x5f, 0x32, 0x10, 0x3, 0xf0, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0x3, 0xf0, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0x3f,
    0x0, 0x0,

    /* U+0067 "g" */
    0x1, 0xcf, 0xb5, 0xf0, 0xbd, 0x44, 0xcf, 0xf,
    0x40, 0x6, 0xf1, 0xf2, 0x0, 0x4f, 0x1f, 0x20,
    0x4, 0xf1, 0xf2, 0x0, 0x4f, 0xf, 0x40, 0x6,
    0xf0, 0xbd, 0x44, 0xcf, 0x1, 0xcf, 0xc5, 0xf0,
    0x51, 0x0, 0x6e, 0xc, 0xb3, 0x4d, 0x80, 0x2b,
    0xfe, 0x90,

    /* U+0068 "h" */
    0xf4, 0x0, 0x0, 0xf4, 0x0, 0x0, 0xf4, 0x0,
    0x0, 0xf5, 0xbf, 0xb1, 0xfc, 0x44, 0xe9, 0xf6,
    0x0, 0x6e, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f,
    0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0,
    0x4f, 0xf4, 0x0, 0x4f,

    /* U+0069 "i" */
    0x0, 0xcc, 0x0, 0x0, 0xdd, 0x0, 0x0, 0x0,
    0x0, 0x9f, 0xfb, 0x0, 0x12, 0x9b, 0x0, 0x0,
    0x8b, 0x0, 0x0, 0x8b, 0x0, 0x0, 0x8b, 0x0,
    0x0, 0x8b, 0x0, 0x0, 0x8b, 0x0, 0x22, 0x9c,
    0x22, 0xcf, 0xff, 0xfc,

    /* U+006A "j" */
    0x0, 0x1, 0xe9, 0x0, 0x1, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0xcf, 0xfa, 0x0, 0x22, 0xaa, 0x0,
    0x0, 0x9a, 0x0, 0x0, 0x9a, 0x0, 0x0, 0x9a,
    0x0, 0x0, 0x9a, 0x0, 0x0, 0x9a, 0x0, 0x0,
    0x9a, 0x0, 0x0, 0x99, 0x77, 0x0, 0xb8, 0x6e,
    0x45, 0xf4, 0x9, 0xfe, 0x70,

    /* U+006B "k" */
    0xb8, 0x0, 0x0, 0xb, 0x80, 0x0, 0x0, 0xb8,
    0x0, 0x0, 0xb, 0x80, 0xc, 0xb0, 0xb8, 0x8,
    0xe1, 0xb, 0x84, 0xf4, 0x0, 0xb9, 0xe8, 0x0,
    0xb, 0xff, 0x50, 0x0, 0xbe, 0x9e, 0x0, 0xb,
    0x80, 0xd8, 0x0, 0xb8, 0x4, 0xf2, 0xb, 0x80,
    0xa, 0xc0,

    /* U+006C "l" */
    0x9f, 0xfb, 0x0, 0x12, 0x9b, 0x0, 0x0, 0x8b,
    0x0, 0x0, 0x8b, 0x0, 0x0, 0x8b, 0x0, 0x0,
    0x8b, 0x0, 0x0, 0x8b, 0x0, 0x0, 0x8b, 0x0,
    0x0, 0x8b, 0x0, 0x0, 0x8b, 0x0, 0x22, 0x9c,
    0x22, 0xcf, 0xff, 0xfc,

    /* U+006D "m" */
    0x3f, 0xce, 0x6e, 0xb0, 0x3f, 0x3c, 0xc3, 0xf2,
    0x3f, 0xa, 0xa0, 0xf3, 0x3f, 0xa, 0xa0, 0xf3,
    0x3f, 0xa, 0xa0, 0xf3, 0x3f, 0xa, 0xa0, 0xf3,
    0x3f, 0xa, 0xa0, 0xf3, 0x3f, 0xa, 0xa0, 0xf3,
    0x3f, 0xa, 0xa0, 0xf3,

    /* U+006E "n" */
    0xf6, 0xcf, 0xb1, 0xfc, 0x22, 0xd9, 0xf6, 0x0,
    0x6e, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4,
    0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f,
    0xf4, 0x0, 0x4f,

    /* U+006F "o" */
    0x0, 0x9e, 0xe9, 0x0, 0xa, 0xd5, 0x5d, 0xa0,
    0xf, 0x40, 0x4, 0xf0, 0x1f, 0x20, 0x2, 0xf1,
    0x1f, 0x20, 0x2, 0xf1, 0x1f, 0x20, 0x2, 0xf1,
    0xf, 0x40, 0x4, 0xf0, 0xa, 0xd4, 0x4d, 0xa0,
    0x1, 0xaf, 0xfa, 0x10,

    /* U+0070 "p" */
    0xf6, 0xcf, 0xc1, 0xf, 0xb2, 0x2c, 0xb0, 0xf5,
    0x0, 0x4f, 0xf, 0x40, 0x2, 0xf1, 0xf4, 0x0,
    0x2f, 0x1f, 0x40, 0x2, 0xf1, 0xf6, 0x0, 0x4f,
    0xf, 0xc4, 0x4d, 0xb0, 0xf5, 0xcf, 0xc1, 0xf,
    0x40, 0x0, 0x0, 0xf4, 0x0, 0x0, 0xf, 0x40,
    0x0, 0x0,

    /* U+0071 "q" */
    0x1, 0xcf, 0xb5, 0xf0, 0xbd, 0x44, 0xcf, 0xf,
    0x40, 0x6, 0xf1, 0xf2, 0x0, 0x4f, 0x1f, 0x20,
    0x4, 0xf1, 0xf2, 0x0, 0x4f, 0xf, 0x40, 0x6,
    0xf0, 0xbd, 0x44, 0xcf, 0x1, 0xcf, 0xc5, 0xf0,
    0x0, 0x0, 0x4f, 0x0, 0x0, 0x4, 0xf0, 0x0,
    0x0, 0x4f,

    /* U+0072 "r" */
    0xf, 0x4b, 0xf8, 0x0, 0xfa, 0x25, 0xf1, 0xf,
    0x70, 0x7, 0x10, 0xf4, 0x0, 0x0, 0xf, 0x30,
    0x0, 0x0, 0xf3, 0x0, 0x0, 0xf, 0x30, 0x0,
    0x0, 0xf3, 0x0, 0x0, 0xf, 0x30, 0x0, 0x0,

    /* U+0073 "s" */
    0x1, 0xaf, 0xfa, 0x10, 0xad, 0x44, 0xca, 0xd,
    0x70, 0x2, 0x50, 0x9e, 0x50, 0x0, 0x0, 0x8f,
    0xfa, 0x0, 0x0, 0x5, 0xda, 0x6, 0x20, 0x5,
    0xe0, 0xcb, 0x34, 0xcb, 0x2, 0xbf, 0xfb, 0x10,

    /* U+0074 "t" */
    0x0, 0x6d, 0x0, 0x0, 0x0, 0x6d, 0x0, 0x0,
    0x0, 0x6d, 0x0, 0x0, 0x3f, 0xff, 0xff, 0x60,
    0x2, 0x8d, 0x22, 0x10, 0x0, 0x6d, 0x0, 0x0,
    0x0, 0x6d, 0x0, 0x0, 0x0, 0x6d, 0x0, 0x0,
    0x0, 0x6d, 0x0, 0x0, 0x0, 0x5e, 0x0, 0x9a,
    0x0, 0x1f, 0x74, 0xf6, 0x0, 0x5, 0xef, 0x90,

    /* U+0075 "u" */
    0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0,
    0x4f, 0xf4, 0x0, 0x4f, 0xf4, 0x0, 0x4f, 0xf4,
    0x0, 0x4f, 0xe6, 0x0, 0x6f, 0x9e, 0x44, 0xcf,
    0x1b, 0xfc, 0x5f,

    /* U+0076 "v" */
    0x2f, 0x20, 0x2, 0xf2, 0xd, 0x60, 0x6, 0xd0,
    0x9, 0xa0, 0xa, 0x90, 0x4, 0xe0, 0xe, 0x40,
    0x0, 0xf3, 0x3f, 0x0, 0x0, 0xb7, 0x7b, 0x0,
    0x0, 0x6b, 0xb6, 0x0, 0x0, 0x2f, 0xf2, 0x0,
    0x0, 0xd, 0xd0, 0x0,

    /* U+0077 "w" */
    0x6d, 0x0, 0x0, 0xd6, 0x4e, 0x0, 0x0, 0xe4,
    0x1f, 0x5, 0x50, 0xf1, 0xf, 0x1c, 0xc1, 0xf0,
    0xc, 0x3e, 0xe3, 0xc0, 0xa, 0x6c, 0xc6, 0xa0,
    0x8, 0xb9, 0x9b, 0x80, 0x5, 0xf6, 0x6f, 0x50,
    0x3, 0xf3, 0x3f, 0x30,

    /* U+0078 "x" */
    0xe, 0x70, 0x7, 0xe0, 0x6, 0xf1, 0x1f, 0x60,
    0x0, 0xd9, 0x9d, 0x0, 0x0, 0x4f, 0xf4, 0x0,
    0x0, 0xd, 0xd0, 0x0, 0x0, 0x4f, 0xf4, 0x0,
    0x0, 0xd9, 0x9d, 0x0, 0x6, 0xf1, 0x1f, 0x60,
    0xe, 0x70, 0x7, 0xe0,

    /* U+0079 "y" */
    0xf, 0x30, 0x3, 0xf0, 0xc, 0x80, 0x8, 0xc0,
    0x7, 0xc0, 0xc, 0x70, 0x2, 0xf1, 0x1f, 0x20,
    0x0, 0xe5, 0x5e, 0x0, 0x0, 0x9a, 0xa9, 0x0,
    0x0, 0x4e, 0xe4, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0xb, 0xb0, 0x0, 0x0, 0xd, 0x70, 0x0,
    0x0, 0x2f, 0x20, 0x0, 0x0, 0x6d, 0x0, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xff, 0x22, 0x22, 0xdb, 0x0, 0x6,
    0xf2, 0x0, 0x2f, 0x60, 0x0, 0xbb, 0x0, 0x6,
    0xf1, 0x0, 0x2f, 0x60, 0x0, 0xbd, 0x22, 0x22,
    0xff, 0xff, 0xff
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 28, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 42, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 48, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 128, .box_w = 4, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 516, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 558, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 648, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 774, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 810, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 858, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 894, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 930, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 972, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1014, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1056, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1104, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1188, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1230, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1294, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1336, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1384, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1432, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1468, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1516, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1564, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1612, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1660, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1696, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1728, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1770, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1806, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1848, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1884, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1926, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1968, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2004, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2040, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2085, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2127, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2163, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2199, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2226, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2262, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2304, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2346, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2378, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2410, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2458, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2485, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2521, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2557, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2593, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2641, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 0, 1, 2, 3, 0, 4, 5,
    6, 7, 8, 9, 10, 11, 12, 13,
    14
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 42, .range_length = 17, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 17, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 64, .range_length = 27, .glyph_id_start = 16,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 43,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t Sarasa_Mono_SC_regular_16 = {
#else
lv_font_t Sarasa_Mono_SC_regular_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if SARASA_MONO_SC_REGULAR_16*/
