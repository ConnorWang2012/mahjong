cd ..
tolua++ -n data_manager -o ../src/cpp/logic/lua_bind/auto/lua_bind_data_manager.cc ../tolua_pkg/data_manager.pkg
pause
rem tolua -a -n pkgname -o myfile.c myfile.pkg