cd ..
tolua++ -n network_manager -o ../src/cpp/logic/lua_bind/lua_bind_network_manager.cc tolua_pkg/network_manager.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg