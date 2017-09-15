/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   log.h
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: log.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_FRAMEWORK_LOG_H_
#define CONNOR_GAME_SRC_FRAMEWORK_LOG_H_

#include <fstream>
#include <iostream>
#include <string>

namespace gamer 
{
    enum class Colors 
    {
	    COLOR_BLUE		= 1,
	    COLOR_GREEN		= 2,
	    COLOR_RED		= 4,
	    COLOR_YELLOW	= 6,
	    COLOR_WHITE		= 7
    };

    void initlog();

    // used by c++ only
    void writelog(const char* format, ...);

    // used by lua only
    void writelog(const std::string& s);

    void printf(const char* s);

    template<typename T, typename... Args>
    void printf(const char* s, T value, Args... args)
    {
	    while (*s) 
        {
		    if (*s == '%' && *(++s) != '%') 
            {
			    std::cout << value;
			    printf(*s ? ++s : s, args...); // work with the normal method printf
			    return;
		    }
		    std::cout << *s++;
	    }
	    throw std::logic_error("extra arguments provided to printf");
    }

    void printfcolor(Colors c, const char* format, ...);

    void printfgreen(const char* format, ...);

    void printfwarning(const char* format, ...);

    void printferror(const char* format, ...);

    // D:\aaa\bbb\ccc\abc.txt --> D:/aaa/bbb/ccc/abc.txt
    inline std::string convertPathFormatToUnixStyle(const std::string& path);

    std::string stringWideCharToUtf8(const std::wstring& ws);

    static std::ofstream s_ofs_log_;
    static std::string s_log_path_;
} // namespace gamer

#endif // CONNOR_GAME_SRC_FRAMEWORK_LOG_H_