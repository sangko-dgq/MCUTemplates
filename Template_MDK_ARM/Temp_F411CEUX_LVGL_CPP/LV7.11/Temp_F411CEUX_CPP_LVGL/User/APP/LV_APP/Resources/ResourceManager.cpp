/*********************
 
 *      ��Դ����

 *********************/
#include "ResourceManager.h"

/*ʵ����*/
ResourceManager resourceManager;

/*��Դ����*/
static void Resource_Declare()
{
	/*Images*/
	//LV_IMG_DECLARE(img_clock);
	
	/*Font*/
	//LV_FONT_DECLARE(font_Mono_16);
}
/*��ʼ��*/
void ResourceManager::Init()
{
	Resource_Declare();
}