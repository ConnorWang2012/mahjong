cd ..
tolua++ -n event_manager -o ../src/cpp/logic/lua_bind/auto/lua_bind_event_manager.cc ../tolua_pkg/event_manager.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg