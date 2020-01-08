#ifndef __DEV_IPC_H__
#define __DEV_IPC_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct _ipx_image_s
{
	unsigned int	au64PhyAddr[3]; /* RW;The physical address of the image */
	unsigned int	au64VirAddr[3]; /* RW;The virtual address of the image */
	unsigned int	au32Stride[3];	/* RW;The stride of the image */
	unsigned int	u32Width;		/* RW;The width of the image */
	unsigned int	u32Height;		/* RW;The height of the image */
	unsigned int	u64PTS;
	unsigned int          u32TimeRef;
	int  enType; /* RW;The type of the image */ 	
}IPX_IMAGE_S;
typedef struct _ipx_RECT_S
{
	int s32X;
	int s32Y;
	unsigned int u32Width;
	unsigned int u32Height;
} IPX_RECT_S;	

extern int media_init(char *ispcfg);
extern int media_uninit(void);
extern int media_run(void);
extern IPX_IMAGE_S* media_getframe(void);
extern int media_setexptime(int ms);
extern int media_startstream(char *name,int port);
extern int media_encodejpg(IPX_IMAGE_S *pstVideoFrame,IPX_RECT_S *rc,void *jpg);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
