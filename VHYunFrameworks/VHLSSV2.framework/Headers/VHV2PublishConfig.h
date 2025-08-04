//
//  VHV2PublishConfig.h
//  VHLSSV2
//
//  Created by 郭超 on 2025/1/16.
//  Copyright © 2025 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 视频画面填充模式
 */
typedef NS_ENUM(NSInteger, VHV2PublishFillMode) {
    ///  图像铺满屏幕，超出显示视窗的视频部分将被裁剪，画面显示可能不完整。
    VHV2PublishFillModeFill,
    ///  图像长边填满屏幕，短边区域会被填充黑色，画面的内容完整。
    VHV2PublishFillModeFit,
    ///  图像拉伸铺满，因此长度和宽度可能不会按比例变化。
    VHV2PublishFillModeScaleFill
};

/**
 * 视频分辨率
 */
typedef NS_ENUM(NSInteger, VHV2PublishResolution) {
    /// 分辨率 160*160，码率范围：100Kbps ~ 150Kbps，帧率：15fps。
    VHV2PublishResolution160x160,
    /// 分辨率 270*270，码率范围：200Kbps ~ 300Kbps，帧率：15fps。
    VHV2PublishResolution270x270,
    /// 分辨率 480*480，码率范围：350Kbps ~ 525Kbps，帧率：15fps。
    VHV2PublishResolution480x480,
    /// 分辨率 320*240，码率范围：250Kbps ~ 375Kbps，帧率：15fps。
    VHV2PublishResolution320x240,
    ///  分辨率 480*360，码率范围：400Kbps ~ 600Kbps，帧率：15fps。
    VHV2PublishResolution480x360,
    ///  分辨率 640*480，码率范围：600Kbps ~ 900Kbps，帧率：15fps。
    VHV2PublishResolution640x480,
    /// 分辨率 320*180，码率范围：250Kbps ~ 400Kbps，帧率：15fps。
    VHV2PublishResolution320x180,
    ///  分辨率 480*270，码率范围：350Kbps ~ 550Kbps，帧率：15fps。
    VHV2PublishResolution480x270,
    /// 分辨率 640*360，码率范围：500Kbps ~ 900Kbps，帧率：15fps。
    VHV2PublishResolution640x360,
    ///  分辨率 960*540，码率范围：800Kbps ~ 1500Kbps，帧率：15fps。
    VHV2PublishResolution960x540,
    ///  分辨率 1280*720，码率范围：1000Kbps ~ 1800Kbps，帧率：15fps。
    VHV2PublishResolution1280x720,
    ///  分辨率 1920*1080，码率范围：2500Kbps ~ 3000Kbps，帧率：15fps。
    VHV2PublishResolution1920x1080
};

/**
 * 视频宽高比模式
 *
 * @info 视频宽高比模式。
 * @note
 * - 横屏模式下的分辨率: VHV2PublishResolution640x360 + VHV2PublishResolutionModeLandscape = 640 × 360。
 * - 竖屏模式下的分辨率: VHV2PublishResolution640x360 + VHV2PublishResolutionModePortrait  = 360 × 640。
 */
typedef NS_ENUM(NSInteger, VHV2PublishResolutionMode) {
    ///  横屏模式。
    VHV2PublishResolutionModeLandscape = 0,
    ///  竖屏模式。
    VHV2PublishResolutionModePortrait = 1,
};

/**
 * 推流播放器状态
 */
typedef NS_ENUM(NSInteger, VHV2PublishStatus) {
    ///  与服务器断开连接。
    VHV2PublishStatusDisconnected,
    ///  正在连接服务器。
    VHV2PublishStatusConnecting,
    ///  连接服务器成功。
    VHV2PublishStatusConnectSuccess,
    ///  重连服务器中。
    VHV2PublishStatusReconnecting,
};

/**
 * 推流播放器错误
 */
typedef NS_ENUM(NSInteger, VHV2PublishCode) {
    ///  没有错误。
    VHV2_OK = 0,

    ///  暂未归类的通用错误。
    VHV2_ERROR_FAILED = -1,

    /// 调用 API 时，传入的参数不合法。
    VHV2_ERROR_INVALID_PARAMETER = -2,

    ///  API 调用被拒绝。
    VHV2_ERROR_REFUSED = -3,

    /// 当前 API 不支持调用。
    VHV2_ERROR_NOT_SUPPORTED = -4,

    ///  license 不合法，调用失败。
    VHV2_ERROR_INVALID_LICENSE = -5,

    ///  请求服务器超时。
    VHV2_ERROR_REQUEST_TIMEOUT = -6,

    ///  服务器无法处理您的请求。
    VHV2_ERROR_SERVER_PROCESS_FAILED = -7,

    ///  连接断开。
    VHV2_ERROR_DISCONNECTED = -8,

    ///  找不到可用的 HEVC 解码器。
    VHV2_ERROR_NO_AVAILABLE_HEVC_DECODERS = -2304,

    /////////////////////////////////////////////////////////////////////////////////
    //
    //      网络相关的警告码
    //
    /////////////////////////////////////////////////////////////////////////////////

    ///  网络状况不佳：上行带宽太小，上传数据受阻。
    VHV2_WARNING_NETWORK_BUSY = 1101,

    /// 当前视频播放出现卡顿。
    VHV2_WARNING_VIDEO_BLOCK = 2105,

    /////////////////////////////////////////////////////////////////////////////////
    //
    //             摄像头相关的警告码
    //
    /////////////////////////////////////////////////////////////////////////////////

    /// 摄像头打开失败。
    VHV2_WARNING_CAMERA_START_FAILED = -1301,

    /// 摄像头正在被占用中，可尝试打开其他摄像头。
    VHV2_WARNING_CAMERA_OCCUPIED = -1316,

    ///  摄像头设备未授权，通常在移动设备出现，可能是权限被用户拒绝了。
    VHV2_WARNING_CAMERA_NO_PERMISSION = -1314,

    /////////////////////////////////////////////////////////////////////////////////
    //
    //             麦克风相关的警告码
    //
    /////////////////////////////////////////////////////////////////////////////////

    /// 麦克风打开失败。
    VHV2_WARNING_MICROPHONE_START_FAILED = -1302,

    ///  麦克风正在被占用中，例如移动设备正在通话时，打开麦克风会失败。
    VHV2_WARNING_MICROPHONE_OCCUPIED = -1319,

    ///  麦克风设备未授权，通常在移动设备出现，可能是权限被用户拒绝了。
    VHV2_WARNING_MICROPHONE_NO_PERMISSION = -1317,

    /////////////////////////////////////////////////////////////////////////////////
    //
    //             屏幕分享相关警告码
    //
    /////////////////////////////////////////////////////////////////////////////////

    /// 当前系统不支持屏幕分享。
    VHV2_WARNING_SCREEN_CAPTURE_NOT_SUPPORTED = -1309,

    ///  开始录屏失败，如果在移动设备出现，可能是权限被用户拒绝了。
    VHV2_WARNING_SCREEN_CAPTURE_START_FAILED = -1308,

    ///  录屏被系统中断。
    VHV2_WARNING_SCREEN_CAPTURE_INTERRUPTED = -7001,

    /////////////////////////////////////////////////////////////////////////////////
    //
    //             编解码相关警告码
    //
    /////////////////////////////////////////////////////////////////////////////////

    ///  表示编码器发生改变，可以通过 onWarning 函数的扩展信息中的 codec_type 字段来获取当前的编码格式。
    /// 其中 1 代表 265 编码，0 代表 264 编码。注意 Windows 端不支持此错误码的扩展信息。
    VHV2_WARNING_CURRENT_ENCODE_TYPE_CHANGED = 1104,

    ///  表示解码器发生改变，可以通过 onWarning 函数的扩展信息中的 codec_type 字段来获取当前的解码格式。
    /// 其中 1 代表 265 解码，0 代表 264 解码。注意 Windows 端不支持此错误码的扩展信息。
    VHV2_WARNING_CURRENT_DECODE_TYPE_CHANGED = 2008,

    VHV2_PublishErrorPusherError = 1002,       //  推流相关错误@{code："10001" ,content: "xxxxx"}
    VHV2_PublishErrorAuthError = 1003,         //  接口\验证等相关错误
    VHV2_PublishErrorParamError = 1004,        //  参数相关错误
    VHV2_PublishErrorCaptureError = 1005,      //  采集相关错误
};

/**
 * 视频画面顺时针旋转角度
 */
typedef NS_ENUM(NSInteger, VHV2LiveRotation) {

    ///  不旋转。
    VHV2LiveRotation0,

    ///  顺时针旋转90度。
    VHV2LiveRotation90,

    ///  顺时针旋转180度。
    VHV2LiveRotation180,

    ///  顺时针旋转270度。
    VHV2LiveRotation270

};

NS_ASSUME_NONNULL_BEGIN

@interface VHV2PublishConfig : NSObject

/// 【字段含义】 视频分辨率。
/// 【特别说明】如需使用竖屏分辨率，请指定 videoResolutionMode 为 Portrait，例如： 640 × 360 + Portrait = 360 × 640。
/// 【推荐取值】
///  - 桌面平台（Win + Mac）：建议选择 640 × 360 及以上分辨率，videoResolutionMode 选择 Landscape，即横屏分辨率。
@property(nonatomic, assign) VHV2PublishResolution videoResolution;

/// 【字段含义】分辨率模式（横屏分辨率 or 竖屏分辨率）。
/// 【推荐取值】桌面平台（Windows、Mac）建议选择 Landscape。
/// 【特别说明】如需使用竖屏分辨率，请指定 resMode 为 Portrait，例如： 640 × 360 + Portrait = 360 × 640。
@property(nonatomic, assign) VHV2PublishResolutionMode videoResolutionMode;

/// 【字段含义】视频采集帧率。
/// 【推荐取值】15fps 或 20fps。5fps 以下，卡顿感明显。10fps 以下，会有轻微卡顿感。20fps 以上，会浪费带宽（电影的帧率为 24fps）。
@property(nonatomic, assign) int videoFps;

/// 【字段含义】目标视频码率，SDK 会按照目标码率进行编码，只有在弱网络环境下才会主动降低视频码率。
/// 【推荐取值】请参考 VHV2PublishResolution 在各档位注释的最佳码率，也可以在此基础上适当调高。
///           比如：VHV2PublishResolution1280x720 对应 1200kbps 的目标码率，您也可以设置为 1500kbps 用来获得更好的观感清晰度。
/// 【特别说明】您可以通过同时设置 videoBitrate 和 minVideoBitrate 两个参数，用于约束 SDK 对视频码率的调整范围：
///  - 如果您将 videoBitrate 和 minVideoBitrate 设置为同一个值，等价于关闭 SDK 对视频码率的自适应调节能力。
@property(nonatomic, assign) int videoBitrate;

/// 【字段含义】最低视频码率，SDK 会在网络不佳的情况下主动降低视频码率以保持流畅度，最低会降至 minVideoBitrate 所设定的数值。
/// 【推荐取值】您可以通过同时设置 videoBitrate 和 minVideoBitrate 两个参数，用于约束 SDK 对视频码率的调整范围：
///  - 如果您将 videoBitrate 和 minVideoBitrate 设置为同一个值，等价于关闭 SDK 对视频码率的自适应调节能力。
@property(nonatomic, assign) int minVideoBitrate;

/// 高级美颜功能[自动开启，无需设置]
@property (nonatomic, assign) BOOL advancedBeautifyEnable;

/// 旋转镜像
@property (nonatomic, assign) BOOL enableRotation;

@end

@interface VHV2TXLivePusherStatistics : NSObject

///  【字段含义】当前 App 的 CPU 使用率（％）。
@property(nonatomic, assign) NSUInteger appCpu;

///  【字段含义】当前系统的 CPU 使用率（％）。
@property(nonatomic, assign) NSUInteger systemCpu;

///  【字段含义】视频宽度。
@property(nonatomic, assign) NSUInteger width;

///  【字段含义】视频高度。
@property(nonatomic, assign) NSUInteger height;

///  【字段含义】帧率（fps）。
@property(nonatomic, assign) NSUInteger fps;

///  【字段含义】视频码率（Kbps）。
@property(nonatomic, assign) NSUInteger videoBitrate;

///  【字段含义】音频码率（Kbps）。
@property(nonatomic, assign) NSUInteger audioBitrate;

///  【字段含义】从 SDK 到云端的往返延时（ms）
@property(nonatomic, assign) NSUInteger rtt;

///  【字段含义】上行速度（kbps）
@property(nonatomic, assign) NSUInteger netSpeed;

@end


NS_ASSUME_NONNULL_END
