cd ..
tolua++ -n game_start_msg_protocol -o ../src/cpp/logic/lua_bind/auto/lua_bind_game_start_msg_protocol.cc tolua_pkg/game_start_msg_protocol.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg