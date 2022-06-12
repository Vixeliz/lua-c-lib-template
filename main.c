#include <lua.h>
#include <lauxlib.h>

static int l_test(lua_State* L)
{
    double number = luaL_checknumber(L, 1);
    lua_pushnumber(L, number);
    return 1;
}

int luaopen_libnative(lua_State* L)
{
    static const struct luaL_Reg nativeFuncLib [] =
    {
         {"test", l_test},
         {NULL, NULL}
    };
    luaL_register(L, "nativelib", nativeFuncLib);
    return 1;
}
