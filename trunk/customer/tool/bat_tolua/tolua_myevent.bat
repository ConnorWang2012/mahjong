cd ..
tolua++ -n myevent -o ../src/cpp/logic/lua_bind/auto/lua_bind_myevent.cc ../tolua_pkg/myevent.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg