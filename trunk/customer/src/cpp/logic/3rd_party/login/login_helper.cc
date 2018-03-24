/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   login_helper.cc
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: see the header.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#include "login_helper.h"

#include "event_headers.h"
#include "macros.h"

#if GAMER_PLATFORM == GAMER_PLATFORM_ANDROID
#include "cocos/platform/android/jni/JniHelper.h"
#elif GAMER_PLATFORM == GAMER_PLATFORM_IOS 
//#include "scripting/lua-bindings/manual/platform/ios/CCLuaObjcBridge.h"
#endif

namespace gamer
{

gamer::LoginHelper* gamer::LoginHelper::s_login_helper_ = nullptr;

LoginHelper* LoginHelper::getInstance()
{
	if (nullptr == s_login_helper_)
	{
		s_login_helper_ = new gamer::LoginHelper();
		if ( !s_login_helper_->init() )
		{
			SAFE_DELETE(s_login_helper_);
			return nullptr;
		}
	}
	return s_login_helper_;
}

void LoginHelper::destoryInstance()
{
	SAFE_DELETE(s_login_helper_);
}

bool LoginHelper::init()
{
	return true;
}

void LoginHelper::login(LoginTypes login_type)
{
	if (login_type == LoginTypes::LOGIN_TYPE_WEIXIN)
	{
		LoginHelper::getInstance()->loginByWeixin();
	}
	else if (login_type == LoginTypes::LOGIN_TYPE_QQ)
	{
		LoginHelper::getInstance()->loginByQQ();
	}
	else if (login_type == LoginTypes::LOGIN_TYPE_MY_ACCOUNT)
	{
		LoginHelper::getInstance()->loginByMyAccount();
	}
}

void LoginHelper::onLoginResponse(int code)
{
	if (code == (int)LoginHelper::LoginResponseCodes::CODE_SUCCESS)
	{
		EventManager::getInstance()->dispatch((id_t)EventIDs::EVENT_ID_LOGIN_SUCCESS);
	}
	else if (code == (int)LoginHelper::LoginResponseCodes::CODE_FAILED)
	{
		EventManager::getInstance()->dispatch((id_t)EventIDs::EVENT_ID_LOGIN_FAILED);
	}
	else
	{
		EventManager::getInstance()->dispatch((id_t)EventIDs::EVENT_ID_LOGIN_FAILED);
	}
}

void LoginHelper::loginByWeixin()
{
#if GAMER_PLATFORM == GAMER_PLATFORM_WIN32 
#elif GAMER_PLATFORM == GAMER_PLATFORM_ANDROID 
	cocos2d::JniHelper::callStaticVoidMethod("com/connor/thirdparty/LoginHelper", "LoginByWeixin");
#elif GAMER_PLATFORM == GAMER_PLATFORM_IOS 

#endif
}

void LoginHelper::loginByQQ()
{
#if GAMER_PLATFORM == GAMER_PLATFORM_WIN32 
#elif GAMER_PLATFORM == GAMER_PLATFORM_ANDROID 
	cocos2d::JniHelper::callStaticVoidMethod("com/connor/thirdparty/LoginHelper", "LoginByQQ");
#elif GAMER_PLATFORM == GAMER_PLATFORM_IOS 

#endif
}

void LoginHelper::loginByMyAccount()
{
}

} // namespace gamer
