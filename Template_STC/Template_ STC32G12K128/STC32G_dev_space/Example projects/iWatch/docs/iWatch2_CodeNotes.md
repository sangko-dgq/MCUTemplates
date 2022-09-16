## iWatch2.0_CodeNote

### EEP-ROM 可编程只读存储器

1. 电可擦编程只读存储器(Electrically Erasable Programmable Read-Only Memory);



### Memory leak 内存泄漏

**内存泄漏**（Memory leak），疏忽或错误造成程序**未能释放已经不再使用的[内存](https://zh.wikipedia.org/wiki/内存)。**





###  |=  

x |= y 

等价于 

x = x | y 

类似于 += 这样去理解





### 链表的本质就是结构体

链表的本质是将若干[内存块](https://www.zhihu.com/search?q=内存块&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A1193261358})串联在一起。在C语言里面用struct表示一个内存块（图中的小方块），一个内存块分两部分：数据区（item）和指针（next），数据区就是用来存数据的，比如int啊double啊什么的，指针负责将一个内存块与另一个内存块链接，通过这种方式在内存的世界里表达一张表。