cd ..
tolua++ -n msg -o ../src/cpp/logic/lua_bind/auto/lua_bind_msg.cc tolua_pkg/msg.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg