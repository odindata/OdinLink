//
//  ODLSDKRestoreDelegate.h
//  OdinLink
//
//  Created by nathan on 2019/6/19.
//  Copyright © 2019 odin. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 场景恢复方式枚举LL
 - ODPresent: Present
 - ODPush: Push
 */
typedef enum : NSUInteger {
    ODLDefault,
    ODLPresent,
    ODLLPush,
} RestoreStyle;

@class ODLSDKScene;

@protocol ODLSDKRestoreDelegate <NSObject>

@optional


/**
 即将进行场景还原(注意: 一旦实现该方法,请务必执行restoreHandler)
 
 @param scene 场景参数
 @param restoreHandler 恢复回调 回调参数YES,或者不实现本方法,将会进行自动场景恢复;回调参数 NO,则不会进行自动恢复场景,请自行根据场景对象scene进行处理;style 为期望场景恢复方式,当传入的不是Default时MobLink会根据期望的方式去进行场景恢复,但前提是期望方式可行,如果期望方式无法达到时,MobLink会自动选择默认方式.
 */
- (void)ODLSDKWillRestoreScene:(ODLSDKScene *)scene Restore:(void (^)(BOOL isRestore, RestoreStyle style))restoreHandler;

/**
 完成场景恢复
 
 @param scene 场景参数
 */
- (void)ODLSDKCompleteRestore:(ODLSDKScene *)scene;

/**
 无法进行场景恢复,原因可能是以下几个: 1.需要恢复的控制器,没有实现 UIViewController+MLSDKRestore 中的相关方法; 2.控制器实现了 UIViewController+MLSDKRestore 中的方法,但恢复的场景无法匹配到对应的控制器路径;
 
 @param scene 场景参数
 */
- (void)ODLSDKNotFoundScene:(ODLSDKScene *)scene;

@end;
