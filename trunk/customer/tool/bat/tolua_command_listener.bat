cd ..
tolua++ -n command_listener -o ../src/cpp/logic/lua_bind/auto/lua_bind_command_listener.cc tolua_pkg/command_listener.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg