/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   login_helper.h
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: login helper.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_3RD_PARTY_LOGIN_HELPER_H_
#define CONNOR_GAME_SRC_3RD_PARTY_LOGIN_HELPER_H_

#include <string>

namespace gamer
{

class LoginHelper
{
public:
	enum class LoginTypes
	{
		LOGIN_TYPE_WEIXIN,
		LOGIN_TYPE_QQ,
		LOGIN_TYPE_MY_ACCOUNT
	};

	enum class LoginResponseCodes
	{
		CODE_ERROR,
		CODE_SUCCESS,
		CODE_FAILED
	};

	LoginHelper& operator=(const LoginHelper&) = delete;

	LoginHelper(const LoginHelper&) = delete;

	static LoginHelper* getInstance();

	static void destoryInstance();

	void login(LoginTypes login_type);

	// do not invoke this.it will be invoked by native.
	static void onLoginResponse(int code);

private:
	LoginHelper() = default;

	bool init();

	void loginByWeixin();

	void loginByQQ();

	void loginByMyAccount();

	static LoginHelper* s_login_helper_;
}; // class LoginHelper3rdParty

} // namespace gamer

#endif // CONNOR_GAME_SRC_3RD_PARTY_LOGIN_HELPER_H_