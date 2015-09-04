//
//  GrowthAnalytics.mm
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "Growthbeat.h"

#import "GrowthbeatCCInternal.h"

USING_NS_CC;

growthanalytics::Growthbeat::Growthbeat() {};

void growthanalytics::Growthbeat::initialize(const std::string& applicationId, const std::string& credentialId) {
    [GrowthbeatCCInternal initializeWithApplicationId:[NSString stringWithUTF8String:applicationId.c_str()]
                                              credentialId:[NSString stringWithUTF8String:credentialId.c_str()]];
}

void growthanalytics::Growthbeat::start(void) {
    [GrowthbeatCCInternal start];
}
void growthanalytics::Growthbeat::stop(void) {
    [GrowthbeatCCInternal stop];
}

#endif