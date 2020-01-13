# libmedia_app
### 一、项目说明

3561av200 + ar0144 二次开发库

目前支持：

1.系统初始化；

2.支持一路视频流初始化

3.支持获取frame 做算法处理

4.支持frame 直接编码为jpg;



### 二、编译

	mkdir build
	
	cd build
	
	cmake ..
	
	make -j


### 三、目前支持接口

	int media_init(char *ispcfg);
	
	int media_uninit(void);
	
	int media_run(void);
	
	IPX_IMAGE_S* media_getframe(void);
	
	int media_setexptime(unsigned int exptime_us);
	
	int media_startstream(char *name,int port);
	
	int media_encodejpg(IPX_IMAGE_S *pstVideoFrame,IPX_RECT_S *rc,void *jpg);
	
### 四、具体板子效果如下链接
	https://www.jianshu.com/p/20a3f7f09a8b
	
### 五、硬件开发板链接

 	https://item.taobao.com/item.htm?spm=a230r.1.14.1.4bcc3f48dcdrBy&id=599347093302&ns=1&abbucket=8#detail
	
### 六、其它
	todo...

