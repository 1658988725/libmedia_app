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
	


