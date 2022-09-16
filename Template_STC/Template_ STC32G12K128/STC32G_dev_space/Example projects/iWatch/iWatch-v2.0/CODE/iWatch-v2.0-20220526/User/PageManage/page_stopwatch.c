#include "iWatch.h"

static unsigned char CODE Icon[] = {
	48, 48,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3E,0x3E,0xFE,0xFE,0xFE,0xFE,0x3E,0x3E,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x38,0x1C,0x3E,0x7F,0x3B,0x90,0xC0,0xE0,0xF0,0xF0,0x78,
	0x78,0x3C,0x3C,0x1C,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x3C,0x3C,0x7C,
	0x78,0xF8,0xF0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF8,0xFE,0x7F,0x1F,0x07,0x03,0x81,0xE0,0xF0,
	0xF8,0xFC,0xFC,0xFE,0xFE,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x01,0x03,0x07,0x0F,0x7F,0xFE,0xFC,0xF0,0x80,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x7E,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
	0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x00,0xE7,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x7F,0xFE,0xF8,0xE0,0xC0,0x81,0x07,0x0F,
	0x1F,0x3F,0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x1F,
	0x1F,0x0F,0x83,0xC0,0xE0,0xF0,0xFC,0x7F,0x3F,0x0F,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x0F,0x1E,
	0x1E,0x3C,0x3C,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x3C,0x3C,0x3E,
	0x1E,0x1F,0x0F,0x07,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	/* (48 X 48 )*/
};
static t_psWidget text1;
static t_psWidget	text_record[3];
static t_psWidget bmp1, bmp2, bmp3;
static t_psGroup group1;

static unsigned char code RESET[] = {
	16, 16, 
	0x08,0x1C,0x2A,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x20,0xC0,0x00,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x40,0x20,0x1F,0x00
	/* (16 X 16 )*/

};
static unsigned char code START[] = {
	16, 16, 
	0x00,0x00,0x00,0x00,0xFE,0xFC,0xFC,0xF8,0xF8,0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,0x80,
	0x00,0x00,0x00,0x00,0x3F,0x1F,0x1F,0x0F,0x0F,0x07,0x07,0x03,0x03,0x01,0x01,0x00
	/* (16 X 16 )*/
};

static unsigned char code PAUSE[] = {
	16, 16, 
	0x00,0x00,0xFC,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0xFC,0xFC,0xFC,0xFC,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x7F,0x00,0x00
	/* (16 X 16 )*/
};
static unsigned char code CHECK[] = {
	16, 16, 
	0xC8,0x88,0x88,0x10,0x10,0x20,0x20,0x40,0x84,0xC4,0xEC,0x78,0x30,0x60,0xC0,0x00,
	0x00,0x00,0x01,0x01,0x03,0x06,0x0C,0x18,0x30,0xE1,0x82,0x0C,0x70,0x80,0x00,0x00
	/* (16 X 16 )*/
};


unsigned char record_cnt = 0;
static unsigned long ms_cnt;
static unsigned char ms = 0, sec = 0, min = 0;
unsigned int timer_cnt = 0;	//��ʱ��0�������
unsigned char tp[3][3];

void TM0_Isr() interrupt 1 using 1		//������0����ж�
{
	timer_cnt++;
}
/**
  * @brief  ҳ���ʼ���¼�
  * @param  ��
  * @retval ��
  */
static void Setup(unsigned char condition)
{
	unsigned char i;
	text1 = og_label_create(FONT_ASCII_8X16, 32, 0);
	for(i = 0; i < 3; i++)
		text_record[i] = og_label_create(FONT_ASCII_8X16, 16, 0);
	bmp1 = og_bmp_create((t_psBMP)RESET, 112, 48);
	bmp2 = og_bmp_create((t_psBMP)START, 112, 0);
	bmp3 = og_bmp_create((t_psBMP)CHECK, 112, 24);
	if(iWatchCheckStatus(IWATCH_TIMERON))
		og_bmp_setBmp(bmp2, (t_psBMP)PAUSE);
	if(record_cnt == 0)
	{
		og_widget_setShow(text_record[0], 0);
		og_widget_setShow(text_record[1], 0);
		og_widget_setShow(text_record[2], 0);
	}
	else
	{
		for(i = 0; i < record_cnt; i++)
		{
			lablel_printf(text_record[i], "%u.%u:%02u:%02u", i + 1, tp[i][0], tp[i][1], tp[i][2]);
			og_widget_setPos(text_record[i], 0, (i + 1) * 16);
			og_widget_setShow(text_record[i], 1);
		}
	}
	group1 = og_group_create(7);
	og_group_addWidget(group1, text1, 0);
	og_group_addWidget(group1, text_record[0], 0);
	og_group_addWidget(group1, text_record[1], 0);
	og_group_addWidget(group1, text_record[2], 0);
	og_group_addWidget(group1, bmp1, 0);
	og_group_addWidget(group1, bmp2, 0);
	og_group_addWidget(group1, bmp3, 0);
	og_group_setPosOffset(group1, 0, 64);
	og_group_addAnimOffset(group1, 0, -64, ANIM_TIME_NORM, ANIM_NULL_CB);
}
static void delet(void)
{
	og_group_delet(group1);
	pageSetStatus(page_timer, PAGE_IDLE);
}
/**
  * @brief  ҳ���˳��¼�
  * @param  ��
  * @retval ��
  */
static void Exit(unsigned char condition)
{
	og_group_addAnimOffset(group1, 0, 64, ANIM_TIME_NORM, delet);
}
/**
  * @brief  ҳ��ѭ��ִ�е�����
  * @param  ��
  * @retval ��
  */
static void Loop()
{
	if(pageExecuteRate(&Rate50Hz))
	{
		ms_cnt = (((unsigned long)timer_cnt << 16) | (TH0 << 8) | TL0) / 10.24;
		ms = ms_cnt % 100;  
		sec = (ms_cnt / 100) % 60; 
		min = (ms_cnt / 100) / 60;
		lablel_printf(text1, "%u:%02u:%02u", min, sec, ms);
	}
}
/**
  * @brief  ҳ���¼�
  * @param  btn:�����¼��İ���
  * @param  event:�¼����
  * @retval ��
  */
static void Event(unsigned char event)
{
	if(event == KEY1_PRESSED)
		pageShift(page_menu, PAGE_RETURN);
	else if(event == KEY2_PRESSED)
	{
		if(iWatchCheckStatus(IWATCH_TIMERON))
		{
			iWatchClearStatus(IWATCH_TIMERON);
			TR0 = 0;
			RX8130CESetClockOuput(CLKOUT_DISABLE);
			og_bmp_setBmp(bmp2, (t_psBMP)START);
		}
		else
		{
			RX8130CESetClockOuput(CLKOUT_1024_HZ);
			iWatchSetStatus(IWATCH_TIMERON);
			TR0 = 1;
			og_bmp_setBmp(bmp2, (t_psBMP)PAUSE);
		}
	}
	else if(event == KEY3_PRESSED)
	{
		if(iWatchCheckStatus(IWATCH_TIMERON))
		{
			if(record_cnt != 3)
			{
				lablel_printf(text_record[record_cnt], "%u.%u:%02u:%02u", record_cnt+1, min, sec, ms);
				og_widget_setShow(text_record[record_cnt], 1);
				og_anim_create(text_record[record_cnt], 0, (record_cnt + 1) * 16, ANIM_TIME_NORM, ANIM_NULL_CB);
				tp[record_cnt][0] = min;
				tp[record_cnt][1] = sec;
				tp[record_cnt][2] = ms;
			}
			if(++record_cnt >= 3)
				record_cnt = 3;
		}
	}
	else if(event == KEY4_PRESSED)
	{
		unsigned char i;
		record_cnt = 0;
		for(i = 0; i < 3; i++)
		{
			og_widget_setShow(text_record[i], 0);
			og_widget_setPos(text_record[i], 16, 0);
		}
		if(iWatchCheckStatus(IWATCH_TIMERON) == 0)
		{
			TH0 = 0;
			TL0 = 0;
			timer_cnt = 0;
		}
	}
}
void pageRegister_page_timer(unsigned char pageID)
{
	pageRegister(pageID, "STOPWATCH", Icon, Setup, Loop, Exit, Event);
}