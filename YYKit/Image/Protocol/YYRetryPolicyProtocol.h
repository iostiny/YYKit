//
//  YYRetryPolicyProtocol.h
//  MGTV-iPhone
//
//  Created by cheyongzi on 2020/8/12.
//  Copyright © 2020 hunantv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YYRetryPolicyProtocol <NSObject>

@optional
/**
 根据当前请求的地址和原始地址返回可重试的请求地址
 */
- (NSString*)retryURL:(NSString*)current orign:(NSString*)orign;

/*
 根据请求的地址替换成master地址
 */
- (NSString*)masterRequestStr:(NSString*)orignStr;

/**
 是否允许重试：1，允许重试
 -1 重试config数据为空或者错误
 -2 重试config中开关为关或者重试域名列表为空
 -3 未匹配到master
 -4 非UIImageView
 -5 当前域名重试列表为空
 -6 已重试到最大次数
 0 其他错误
 */
- (NSInteger)isAllowRetry:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
