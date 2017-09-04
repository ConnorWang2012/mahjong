cd ..
tolua++ -n mylog -o ../src/cpp/logic/lua_bind/auto/lua_bind_mylog.cc tolua_pkg/mylog.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg