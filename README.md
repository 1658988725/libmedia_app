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

extern int media_init(char *ispcfg);

extern int media_uninit(void);

extern int media_run(void);

extern IPX_IMAGE_S* media_getframe(void);

extern int media_setexptime(int ms); not

extern int media_startstream(char *name,int port);

extern int media_encodejpg(IPX_IMAGE_S *pstVideoFrame,IPX_RECT_S *rc,void *jpg);


