cd ..
tolua++ -n table_msg_protocol -o ../src/cpp/logic/lua_bind/auto/lua_bind_table_msg_protocol.cc ../tolua_pkg/table_msg_protocol.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg