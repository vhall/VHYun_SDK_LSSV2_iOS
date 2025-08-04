//
//  VHV2LivePublisher.h
//  VHLssVod_v2
//
//  Created by 郭超 on 2025/1/14.
//  Copyright © 2025 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TXLiteAVSDK_Professional/TXLiteAVSDK.h>
#import <TXLiteAVSDK_Professional/TXLiveBase.h>
#import <TXLiteAVSDK_Professional/V2TXLivePusher.h>

#import "VHV2PublishConfig.h"
#import "IVHBeautifyModule.h"

NS_ASSUME_NONNULL_BEGIN



@protocol VHV2LivePublisherDelegate;

@interface VHV2LivePublisher : NSObject

@property (nonatomic,weak)id <VHV2LivePublisherDelegate> delegate;

/// 推流状态
@property (nonatomic, assign, readonly) BOOL isPublishing;
/// 是否为前置摄像头
@property (nonatomic, assign, readonly) BOOL frontCamera;
/// 是否镜像
@property (nonatomic, assign, readonly) BOOL mirror;
/// 推流参数
@property (nonatomic, strong) VHV2PublishConfig* config;

/**
 *  初始化
 *  @param config config参数
 *  @param logParam 日志上报
 *  @param module 高级美颜module
 */
- (instancetype)initWithConfig:(VHV2PublishConfig *)config logParam:(NSDictionary *)logParam AndvancedBeautify:(id<IVHBeautifyModule>)module HandleError:(void(^)(NSError *error))handle;
- (instancetype)initWithConfig:(VHV2PublishConfig *)config licenseUrl:(NSString*)licenseUrl licenseKey:(NSString*)licenseKey logParam:(NSDictionary *)logParam AndvancedBeautify:(id<IVHBeautifyModule>)module HandleError:(void(^)(NSError *error))handle;

/**
 *  销毁初始化数据，同步销毁，如果感觉销毁太慢，可以开线程去销毁
 */
- (void)destoryObject;

/**
 * 设置本地摄像头预览 View
 * @param view 本地摄像头预览 View。
 */
- (int)setRenderView:(UIView *)view;

/**
 *  开始推流
 *  @param roomID       房间ID
 *  @param accessToken  accessToken
 */
- (BOOL)startPublish:(NSString *)roomID accessToken:(NSString *)accessToken;

/**
 *  暂停推流 如电话接入、进入后台等
 */
- (BOOL)pause;

/**
 *  恢复推流
 */
- (BOOL)resume;

/**
 *  停止推流
 */
- (BOOL)stopPublish;

/**
 * 打开本地摄像头
 * @param frontCamera 是否为前置摄像头。
 *         - YES 【默认值】: 切换到前置摄像头。
 *         - NO: 切换到后置摄像头。
 */
- (int)startCamera:(BOOL)frontCamera;

/**
 * 关闭本地摄像头
 */
- (int)stopCamera;

/**
 * 开启图片推流
 * 
 * @param image 图片。
 * @param rotation 角度
 * @note startVirtualCamera，startCamera，startScreenCapture，同一 Pusher
 * 实例下，仅有一个采集源可以上行，不同采集源之间切换，请先关闭前一采集源，再开启后一采集源，保证同一采集源的开启和关闭是成对调用的。比如：采集源从Camera切换到VirtualCamera，调用顺序是 startCamera -> stopCamera -> startVirtualCamera。
 */
- (int)startVirtualCamera:(UIImage *)image rotation:(VHV2LiveRotation)rotation;

/**
 * 关闭图片推流
 */
- (int)stopVirtualCamera;

/**
 * 打开麦克风
 */
- (int)startMicrophone;

/**
 * 关闭麦克风
 */
- (int)stopMicrophone;

/**
 *  切换前后摄像头
 *  @param frontCamera 是否为前置摄像头。
 *  @return 是否切换成功
 */
- (int)switchCamera:(BOOL)frontCamera;

/**
 *  填充模式
 */
- (int)setContentMode:(VHV2PublishFillMode)contentMode;

/**
 *  镜像摄像头
 *  @param mirror YES:镜像 NO:不镜像
 */
- (int)camVidMirror:(BOOL)mirror;

/**
 * 查询是否支持开启闪光灯（仅适用于移动端）
 */
- (BOOL)isCameraTorchSupported;

/**
 * 开启/关闭闪光灯，也就是手电筒模式（仅适用于移动端）
 * @param enabled 是否开启闪光灯
 */
- (NSInteger)enableCameraTorch:(BOOL)enabled;

/**
 *  设置摄像头的曝光参数，取值范围从-1到1, 0正常
 *  @param value 曝光值
 */
- (NSInteger)setExposureCompensation:(CGFloat)value;

/**
 * 查询当前摄像头是否支持缩放（仅适用于移动端）
 */
- (BOOL)isCameraZoomSupported;

/**
 * 获取摄像头的最大缩放倍数（仅适用于移动端）
 */
- (CGFloat)getCameraZoomMaxRatio;

/**
 * 设置摄像头的缩放倍数（仅适用于移动端）
 *
 * @param zoomRatio 取值范围1 - 5，取值为1表示最远视角（正常镜头），取值为5表示最近视角（放大镜头）。最大值推荐为5，若超过5，视频数据会变得模糊不清。
 */
- (NSInteger)setCameraZoomRatio:(CGFloat)zoomRatio;

/**
 * 设置本地摄像头预览画面的旋转角度
 *
 * @param rotation 预览画面的旋转角度 {@link V2TXLiveRotation}。
 *         - V2TXLiveRotation0【默认值】: 0度, 不旋转。
 *         - V2TXLiveRotation90:  顺时针旋转90度。
 *         - V2TXLiveRotation180: 顺时针旋转180度。
 *         - V2TXLiveRotation270: 顺时针旋转270度。
 *         - V2TXLIVE_OK: 成功。
 * @note  只旋转本地预览画面，不影响推流出去的画面。
 */
- (int)setRenderRotation:(VHV2LiveRotation)rotation;


/*
 *设置摄像头对焦位置
 *postion: 对焦位置
 ***/
-(int)setCameraFocusPostion:(CGPoint)postion;

/**
 * 重新设置分辨率及其他主要采集参数
 * @param videoWidth 宽
 * @param videoHeight  高
 * @param videoBitRate bit
 * @param videoCaptureFPS  fps
 * @param minVideoBitrate 最小bit
 * @param resolutionMode VHV2PublishResolutionModePortrait 竖屏 VHV2PublishResolutionModeLandscape 横屏
 */
- (void)updateVideoCaptureWidth:(NSInteger)videoWidth videoHeight:(NSInteger)videoHeight videoBitRate:(NSInteger)videoBitRate videoCaptureFPS:(NSInteger)videoCaptureFPS minVideoBitrate:(NSInteger)minVideoBitrate resolutionMode:(VHV2PublishResolutionMode)resolutionMode;

/**
 *  获得当前SDK版本号
 */
+ (NSString *) getSDKVersion;


@end

@protocol VHV2LivePublisherDelegate <NSObject>

@optional
/**
 *  推流状态回调
 *  @param status   状态类型
 *  @param info     状态信息
 *      VHPublishStatusPushConnectSucceed,//直播连接成功
 *      VHPublishStatusUploadSpeed,//直播上传速率
 *      VHPublishStatusUploadNetworkException,//发起端网络环境差
 *      VHPublishStatusUploadNetworkOK, //发起端网络环境恢复正常
 *      VHPublishStatusStoped//发起端停止推流
 *      VHPublishStatusReconnecting//重连
 */
- (void)onPublishStatusV2:(VHV2PublishStatus)status info:(NSDictionary*)info;

/**
 *  错误回调
 *  @param error    错误类型
 *  @param info     错误信息
 *      VHPublishErrorPusherError,       //  推流相关错误@{code："10001" ,content: "xxxxx"}
 *      VHPublishErrorAuthError,         //  接口\验证等相关错误
 *      VHPublishErrorParamError,        //  参数相关错误
 *      VHPublishErrorCaptureError,      //  采集相关错误
 */
- (void)onPublishErrorV2:(VHV2PublishCode)error info:(NSDictionary*)info;

/**
 * @param code    错误类型
 * @param message  描述
 * @param extraInfo 详情
 */
- (void)onWarning:(VHV2PublishCode)code message:(NSString *)message extraInfo:(NSDictionary *)extraInfo;

/**
 *  推流器的统计数据
 *  @param statistics 数据
 */
- (void)onStatisticsUpdate:(V2TXLivePusherStatistics *)statistics;

@end

NS_ASSUME_NONNULL_END
