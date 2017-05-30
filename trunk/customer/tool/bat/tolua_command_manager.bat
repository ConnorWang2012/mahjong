cd ..
tolua++ -n command_manager -o ../src/cpp/logic/lua_bind/lua_bind_command_manager.cc tolua_pkg/command_manager.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg