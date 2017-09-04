/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  macros.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2014-09-12
 @ description:   define common base macros.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CONNOR_GAME_SRC_BASE_MACROS_H_
#define CONNOR_GAME_SRC_BASE_MACROS_H_

namespace gamer 
{

#define GAMER_PLATFORM_WIN32			1	
#define GAMER_PLATFORM_ANDROID			2
#define GAMER_PLATFORM_IOS				3

#define GAMER_PLATFORM					GAMER_PLATFORM_WIN32

#define NS_GAMER_BEGIN					namespace gamer {
#define NS_GAMER_END					}
#define USING_NS_GAMER					using namespace gamer

#define SAFE_DELETE(p)					do { if(nullptr != (p)) { delete (p); (p) = nullptr; } } while(0)

#define CALLBACK_SELECTOR_0(__selector__, __target__, ...) std::bind(&__selector__, __target__, ##__VA_ARGS__)
#define CALLBACK_SELECTOR_1(__selector__, __target__, ...) std::bind(&__selector__, __target__, std::placeholders::_1, ##__VA_ARGS__)
#define CALLBACK_SELECTOR_2(__selector__, __target__, ...) std::bind(&__selector__, __target__, std::placeholders::_1, std::placeholders::_2, ##__VA_ARGS__)
#define CALLBACK_SELECTOR_3(__selector__, __target__, ...) std::bind(&__selector__, __target__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, ##__VA_ARGS__)

#if !defined(CONNOR_GAME_LOG_OPENED) || CONNOR_GAME_LOG_OPENED == 0
#define MYPRINTF(...)      do {} while (0)
#define PRINTFERROR(...)   do {} while (0)
#define PRINTFGREEN(...)   do {} while (0)
#define PRINTFWARNING(...) do {} while (0)
#define WRITELOG(...)      do {} while (0)
#elif CONNOR_GAME_LOG_OPENED == 1
#define MYPRINTF(format, ...)      gamer::printf(format, ##__VA_ARGS__)
#define PRINTFERROR(format, ...)   gamer::printferr(format, ##__VA_ARGS__)
#define PRINTFGREEN(format, ...)   gamer::printfgreen(format, ##__VA_ARGS__)
#define PRINTFWARNING(...)         gamer::printfwarning(format, ##__VA_ARGS__)
#define WRITELOG(format, ...)      gamer::writelog(format, ##__VA_ARGS__)
#endif

typedef int LuaFunction;
} // namespace gamer

#endif // CONNOR_GAME_SRC_BASE_MACROS_H_
