//
//  GrowthPush.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#ifndef __GROWTHPUSHPLUGIN_GROWTHPUSH_H__
#define __GROWTHPUSHPLUGIN_GROWTHPUSH_H__

#include "cocos2d.h"

#include "GPEnvironment.h"

NS_GROWTHPUSH_BEGIN

/* APNS/GCM did receive callback function */
typedef std::function<void(cocos2d::Value)> gpDidReceiveRemoteNotificationCallback;
typedef std::function<void(std::string)> ShowMessageHandler;

class CC_DLL GrowthPush
{
public:

	GrowthPush();
	~GrowthPush();
	static GrowthPush* getInstance();

    void initialize(const std::string& applicationId, const std::string& credentialId, GPEnvironment environment);

    void initialize(const std::string& applicationId, const std::string& credentialId, GPEnvironment environment, bool adInfoEnable);

    /**
     * Set device token
     */
    void requestDeviceToken();

    /**
     * Set device token
     *
     * @param senderID Google Project Number
     */
    void requestDeviceToken(const std::string &senderId);

    /**
     * Track event
     *
     * @param name Event name such as "Launch" (max 64 characters)
     */
    void trackEvent(const std::string &name);

    /**
     * Track event with additional information
     *
     * @param name Event name (max 64 characters)
     * @param value Additional information
     */
    void trackEvent(const std::string &name, const std::string &value);

    void trackEvent(const std::string &name, const std::string &value, const ShowMessageHandler& showMessageHandle);

    /**
     * Create a tag for the device
     *
     * @param name Tag name such as "Finished Tutorial" (max 64 characters)
     */
    void setTag(const std::string &name);

    /**
     * Create a tag with value for the device
     *
     * @param name Tag name such as "Gender" (max 64 characters)
     * @param value Tag value such as "male"
     */
    void setTag(const std::string &name, const std::string &value);

    /**
     * Create tags including device model, OS version, language, time zone and app version
     */
    void setDeviceTags(void);

    /**
     * Clear badge of app icon
     */
    void clearBadge(void);

    /**
     * Adds an callback for the specified target.
     *
     * @param target The target which wants to observe notification events.
     * @param selector The callback function which will be invoked when the specified notification event was posted.
     */
     void setOpenNotificationCallback(const gpDidReceiveRemoteNotificationCallback &callback);

    void renderMessage(const std::string &udid);

private:
    static GrowthPush* instance;
};

NS_GROWTHPUSH_END

#endif  // __GROWTHPUSHPLUGIN_GROWTHPUSH_H__
