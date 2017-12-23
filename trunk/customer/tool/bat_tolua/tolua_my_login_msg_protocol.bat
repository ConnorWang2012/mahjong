cd ..
tolua++ -n my_login_msg_protocol -o ../src/cpp/logic/lua_bind/auto/lua_bind_my_login_msg_protocol.cc ../tolua_pkg/my_login_msg_protocol.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg