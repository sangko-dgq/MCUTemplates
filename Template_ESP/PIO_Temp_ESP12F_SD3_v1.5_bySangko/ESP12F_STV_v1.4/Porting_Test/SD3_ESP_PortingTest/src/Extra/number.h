#ifndef NUMBER_H
#define NUMBER_H

#include "../../lib/TFT_eSPI/TFT_eSPI.h"

#include "../Asset/font/O_3660_i0.h"
#include "../Asset/font/O_3660_i1.h"
#include "../Asset/font/O_3660_i2.h"
#include "../Asset/font/O_3660_i3.h"
#include "../Asset/font/O_3660_i4.h"
#include "../Asset/font/O_3660_i5.h"
#include "../Asset/font/O_3660_i6.h"
#include "../Asset/font/O_3660_i7.h"
#include "../Asset/font/O_3660_i8.h"
#include "../Asset/font/O_3660_i9.h"

#include "../Asset/font/W_3660_i0.h"
#include "../Asset/font/W_3660_i1.h"
#include "../Asset/font/W_3660_i2.h"
#include "../Asset/font/W_3660_i3.h"
#include "../Asset/font/W_3660_i4.h"
#include "../Asset/font/W_3660_i5.h"
#include "../Asset/font/W_3660_i6.h"
#include "../Asset/font/W_3660_i7.h"
#include "../Asset/font/W_3660_i8.h"
#include "../Asset/font/W_3660_i9.h"

#include "../Asset/font/W_1830_i0.h"
#include "../Asset/font/W_1830_i1.h"
#include "../Asset/font/W_1830_i2.h"
#include "../Asset/font/W_1830_i3.h"
#include "../Asset/font/W_1830_i4.h"
#include "../Asset/font/W_1830_i5.h"
#include "../Asset/font/W_1830_i6.h"
#include "../Asset/font/W_1830_i7.h"
#include "../Asset/font/W_1830_i8.h"
#include "../Asset/font/W_1830_i9.h"


class Number
{
private:


public:
  //void init();
  void printfW3660(int numx,int numy,int numn);
  void printfO3660(int numx,int numy,int numn);
  void printfW1830(int numx,int numy,int numn);
};


#endif
