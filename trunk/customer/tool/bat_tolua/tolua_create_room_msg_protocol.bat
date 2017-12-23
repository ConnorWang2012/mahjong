cd ..
tolua++ -n create_room_msg_protocol -o ../src/cpp/logic/lua_bind/auto/lua_bind_create_room_msg_protocol.cc ../tolua_pkg/create_room_msg_protocol.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg