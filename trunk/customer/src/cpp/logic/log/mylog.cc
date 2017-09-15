/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   log.cc
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

#include "mylog.h"

#include <chrono>

#ifdef _WIN32
#include <direct.h> 
#include <io.h> 
#include <iomanip>
#include <windows.h>
#elif __APPLE__

#elif __ANDROID__

#elif __linux__

#elif __unix__ 

#endif

namespace gamer 
{
	
void initlog() 
{
	auto now = std::chrono::system_clock::now();
	auto curtime = std::chrono::system_clock::to_time_t(now);
	auto tm = std::localtime(&curtime);
	auto y = tm->tm_year + 1900;
	auto m = tm->tm_mon + 1;
	auto d = tm->tm_mday;

#ifdef _WIN32
    WCHAR full_path[MAX_PATH] = { 0 };
    ::GetModuleFileName(nullptr, full_path, MAX_PATH);
    std::wstring path_tmp = full_path;
    path_tmp = path_tmp.substr(0, path_tmp.rfind(L"\\") + 1);
    auto path = gamer::convertPathFormatToUnixStyle(gamer::stringWideCharToUtf8(path_tmp));
    path += "mylog";
    if (_access(path.c_str(), 0) < 0)
    {
        _mkdir(path.c_str());
    }

    char buf[MAX_PATH];
    snprintf(buf, sizeof(buf), "%s/%d-%d-%d", path.c_str(), y, m, d);
	if (_access(buf, 0) < 0) 
    {
		_mkdir(buf);
	}
#else
	// TODO : other platform
#endif
	
	s_log_path_ = std::string(buf) + "/mylog.dat";
}

void writelog(const char* format, ...) 
{
	if ( !s_ofs_log_.is_open() ) 
    {
		s_ofs_log_.open(s_log_path_.c_str(),
			std::ofstream::out | std::ofstream::binary | std::ofstream::app);
	}
	
	// time
	auto now = std::chrono::system_clock::now();
	auto curtime = std::chrono::system_clock::to_time_t(now);
	auto tm = std::localtime(&curtime);
	auto time = std::put_time(tm, "%Y-%m-%d %H:%M:%S");

	// context
	va_list args;
	va_start(args, format);
	char buf[256];
	vsnprintf(buf, sizeof(buf), format, args);
	s_ofs_log_ << time << " " << buf << "\n";
	va_end(args);

	s_ofs_log_.close();
}

void writelog(const std::string& s)
{
    if ( !s_ofs_log_.is_open() )
    {
        s_ofs_log_.open(s_log_path_.c_str(),
            std::ofstream::out | std::ofstream::binary | std::ofstream::app);
    }

    // time
    auto now = std::chrono::system_clock::now();
    auto curtime = std::chrono::system_clock::to_time_t(now);
    auto tm = std::localtime(&curtime);
    auto time = std::put_time(tm, "%Y-%m-%d %H:%M:%S");

    // context
    s_ofs_log_ << time << " " << s.c_str() << "\n";

    s_ofs_log_.close();
}

void printf(const char* s)
{
	while (*s) 
    {
		if (*s == '%' && *(++s) != '%')
			throw std::runtime_error("invalid format string: missing arguments");
		std::cout << *s++;
	}
}

void printfcolor(Colors c, const char* format, ...) 
{
	va_list args;
	va_start(args, format);
	char buf[256];
	vsnprintf(buf, sizeof(buf), format, args);
#ifdef _WIN32
	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)c);
	std::cout << buf << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_WHITE);
#else
	// TODO : other platform
	std::cout << buf << std::endl;
#endif
	va_end(args);
}

void printfgreen(const char* format, ...) 
{
	va_list args;
	va_start(args, format);
	char buf[256];
	vsnprintf(buf, sizeof(buf), format, args);
#ifdef _WIN32
	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_GREEN);
	std::cout << buf << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_WHITE);
#else
	// TODO : other platform
	std::cout << buf << std::endl;
#endif
	va_end(args);
}

void printfwarning(const char* format, ...) 
{
	va_list args;
	va_start(args, format);
	char buf[256];
	vsnprintf(buf, sizeof(buf), format, args);
#ifdef _WIN32
	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_YELLOW);
	std::cout << buf << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_WHITE);
#else
	// TODO : other platform
	std::cout << buf << std::endl;
#endif
	va_end(args);
}

void printferror(const char* format, ...) 
{
	va_list args;
	va_start(args, format);
	char buf[256];
	vsnprintf(buf, sizeof(buf), format, args);
#ifdef _WIN32
	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_RED);
	std::cout << buf << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | (int)Colors::COLOR_WHITE);
#else
	// TODO : other platform
	std::cout << buf << std::endl;
#endif
	va_end(args);
}

inline std::string convertPathFormatToUnixStyle(const std::string& path)
{
    std::string ret = path;
    int len = ret.length();
    for (int i = 0; i < len; ++i)
    {
        if (ret[i] == '\\')
        {
            ret[i] = '/';
        }
    }
    return ret;
}

std::string stringWideCharToUtf8(const std::wstring& ws)
{
    std::string ret;
#ifdef _WIN32
    if ( !ws.empty() )
    {
        int num = WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), -1, nullptr, 0, nullptr, FALSE);
        if (num)
        {
            char* utf8 = new char[num + 1];
            utf8[0] = 0;

            num = WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), -1, utf8, num + 1, nullptr, FALSE);

            ret = utf8;
            delete[] utf8;
        }
    }
#elif __APPLE__

#elif __ANDROID__


#endif

    return ret;
}

} // namespace gamer