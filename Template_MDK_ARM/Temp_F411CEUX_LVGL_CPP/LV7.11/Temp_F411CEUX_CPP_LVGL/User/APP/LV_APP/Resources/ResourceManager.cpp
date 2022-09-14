/*********************
 
 *      资源管理

 *********************/
#include "ResourceManager.h"

/*实例化*/
ResourceManager resourceManager;

/*资源导入*/
static void Resource_Declare()
{
	/*Images*/
	//LV_IMG_DECLARE(img_clock);
	
	/*Font*/
	//LV_FONT_DECLARE(font_Mono_16);
}
/*初始化*/
void ResourceManager::Init()
{
	Resource_Declare();
}