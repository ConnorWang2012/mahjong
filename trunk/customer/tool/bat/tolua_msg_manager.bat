cd ..
tolua++ -n msg_manager -o ../src/cpp/logic/lua_bind/auto/lua_bind_msg_manager.cc tolua_pkg/msg_manager.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg