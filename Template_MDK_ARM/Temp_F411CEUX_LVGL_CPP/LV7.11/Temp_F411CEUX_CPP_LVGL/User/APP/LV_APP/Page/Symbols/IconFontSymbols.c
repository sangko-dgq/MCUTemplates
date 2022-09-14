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

#ifndef ICONFONTSYMBOLS
#define ICONFONTSYMBOLS 1
#endif

#if ICONFONTSYMBOLS

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] =
{
    /* U+E60C "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3c, 0xff,
    0xc3, 0x0, 0x3, 0xff, 0xff, 0xff, 0x30, 0xc,
    0xff, 0xff, 0xff, 0xc0, 0xf, 0xff, 0xff, 0xff,
    0xf0, 0xf, 0xff, 0xff, 0xff, 0xf0, 0xc, 0xff,
    0xff, 0xff, 0xc0, 0x3, 0xff, 0xff, 0xff, 0x30,
    0x0, 0x3c, 0xff, 0xc3, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+E641 "" */
    0xcf, 0xfc, 0x0, 0xcf, 0xfc, 0x0, 0xcf, 0xfc,
    0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
    0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
    0xcf, 0xfc, 0x0, 0xcf, 0xfc, 0x0, 0xcf, 0xfc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] =
{
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 10, .box_h = 10, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 50, .adv_w = 256, .box_w = 16, .box_h = 4, .ofs_x = 0, .ofs_y = 4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] =
{
    0x0, 0x35
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 58892, .range_length = 54, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc =
{
#else
static lv_font_fmt_txt_dsc_t font_dsc =
{
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
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
const lv_font_t IconFontSymbols =
{
#else
lv_font_t IconFontSymbols =
{
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = -1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if ICONFONTSYMBOLS*/

