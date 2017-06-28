cd ..
tolua++ -n play_card_msg_protocol -o ../src/cpp/logic/lua_bind/auto/lua_bind_play_card_msg_protocol.cc tolua_pkg/play_card_msg_protocol.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg