#include "lua_pack_binary_auto.hpp"
#include "Binary.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_Binary_Binary_writeByte(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "cc.Binary:writeByte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeByte'", nullptr);
            return 0;
        }
        cobj->writeByte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeByte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeByte'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "cc.Binary:writeShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeShort'", nullptr);
            return 0;
        }
        cobj->writeShort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeShort'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readBool(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readBool'", nullptr);
            return 0;
        }
        bool ret = cobj->readBool();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readBool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readBool'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readChar'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readChar'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readByte(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readByte'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->readByte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readByte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readByte'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_finish(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_finish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_finish'", nullptr);
            return 0;
        }
        cobj->finish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:finish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_finish'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_initWrite(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_initWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_initWrite'", nullptr);
            return 0;
        }
        bool ret = cobj->initWrite();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:initWrite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_initWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Binary:writeString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeString'", nullptr);
            return 0;
        }
        cobj->writeString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeString'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readFloat'", nullptr);
            return 0;
        }
        double ret = cobj->readFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Binary:writeDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeDouble'", nullptr);
            return 0;
        }
        cobj->writeDouble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeBool(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.Binary:writeBool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeBool'", nullptr);
            return 0;
        }
        cobj->writeBool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeBool'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Binary:writeFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeFloat'", nullptr);
            return 0;
        }
        cobj->writeFloat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_getStream(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_getStream'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_getStream'", nullptr);
            return 0;
        }
        const std::string ret = cobj->getStream();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:getStream",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_getStream'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_isBigEndian(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_isBigEndian'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_isBigEndian'", nullptr);
            return 0;
        }
        const bool ret = cobj->isBigEndian();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:isBigEndian",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_isBigEndian'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readShort'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "cc.Binary:writeChar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeChar'", nullptr);
            return 0;
        }
        cobj->writeChar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeChar'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readInt'", nullptr);
            return 0;
        }
        int ret = cobj->readInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readInt'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_initRead(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_initRead'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Binary:initRead");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_initRead'", nullptr);
            return 0;
        }
        bool ret = cobj->initRead(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:initRead",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_initRead'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_setEndian(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_setEndian'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.Binary:setEndian");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_setEndian'", nullptr);
            return 0;
        }
        cobj->setEndian(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:setEndian",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_setEndian'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readDouble'", nullptr);
            return 0;
        }
        double ret = cobj->readDouble();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readDouble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readString'", nullptr);
            return 0;
        }
        std::string ret = cobj->readString();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readString'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "cc.Binary:writeLong");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeLong'", nullptr);
            return 0;
        }
        cobj->writeLong(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeLong",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeLong'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_readLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_readLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_readLong'", nullptr);
            return 0;
        }
        long long ret = cobj->readLong();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:readLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_readLong'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_writeInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Binary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Binary_Binary_writeInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Binary:writeInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_writeInt'", nullptr);
            return 0;
        }
        cobj->writeInt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:writeInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_writeInt'.",&tolua_err);
#endif

    return 0;
}
int lua_Binary_Binary_createRead(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Binary:createRead");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_createRead'", nullptr);
            return 0;
        }
        cocos2d::Binary* ret = cocos2d::Binary::createRead(arg0);
        object_to_luaval<cocos2d::Binary>(tolua_S, "cc.Binary",(cocos2d::Binary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Binary:createRead",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_createRead'.",&tolua_err);
#endif
    return 0;
}
int lua_Binary_Binary_createWrite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Binary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_createWrite'", nullptr);
            return 0;
        }
        cocos2d::Binary* ret = cocos2d::Binary::createWrite();
        object_to_luaval<cocos2d::Binary>(tolua_S, "cc.Binary",(cocos2d::Binary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Binary:createWrite",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_createWrite'.",&tolua_err);
#endif
    return 0;
}
int lua_Binary_Binary_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Binary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Binary_Binary_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::Binary();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Binary");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Binary:Binary",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_Binary_Binary_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_Binary_Binary_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Binary)");
    return 0;
}

int lua_register_Binary_Binary(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Binary");
    tolua_cclass(tolua_S,"Binary","cc.Binary","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Binary");
        tolua_function(tolua_S,"new",lua_Binary_Binary_constructor);
        tolua_function(tolua_S,"writeByte",lua_Binary_Binary_writeByte);
        tolua_function(tolua_S,"writeShort",lua_Binary_Binary_writeShort);
        tolua_function(tolua_S,"readBool",lua_Binary_Binary_readBool);
        tolua_function(tolua_S,"readChar",lua_Binary_Binary_readChar);
        tolua_function(tolua_S,"readByte",lua_Binary_Binary_readByte);
        tolua_function(tolua_S,"finish",lua_Binary_Binary_finish);
        tolua_function(tolua_S,"initWrite",lua_Binary_Binary_initWrite);
        tolua_function(tolua_S,"writeString",lua_Binary_Binary_writeString);
        tolua_function(tolua_S,"readFloat",lua_Binary_Binary_readFloat);
        tolua_function(tolua_S,"writeDouble",lua_Binary_Binary_writeDouble);
        tolua_function(tolua_S,"writeBool",lua_Binary_Binary_writeBool);
        tolua_function(tolua_S,"writeFloat",lua_Binary_Binary_writeFloat);
        tolua_function(tolua_S,"getStream",lua_Binary_Binary_getStream);
        tolua_function(tolua_S,"isBigEndian",lua_Binary_Binary_isBigEndian);
        tolua_function(tolua_S,"readShort",lua_Binary_Binary_readShort);
        tolua_function(tolua_S,"writeChar",lua_Binary_Binary_writeChar);
        tolua_function(tolua_S,"readInt",lua_Binary_Binary_readInt);
        tolua_function(tolua_S,"initRead",lua_Binary_Binary_initRead);
        tolua_function(tolua_S,"setEndian",lua_Binary_Binary_setEndian);
        tolua_function(tolua_S,"readDouble",lua_Binary_Binary_readDouble);
        tolua_function(tolua_S,"readString",lua_Binary_Binary_readString);
        tolua_function(tolua_S,"writeLong",lua_Binary_Binary_writeLong);
        tolua_function(tolua_S,"readLong",lua_Binary_Binary_readLong);
        tolua_function(tolua_S,"writeInt",lua_Binary_Binary_writeInt);
        tolua_function(tolua_S,"createRead", lua_Binary_Binary_createRead);
        tolua_function(tolua_S,"createWrite", lua_Binary_Binary_createWrite);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::Binary).name();
    g_luaType[typeName] = "cc.Binary";
    g_typeCast["Binary"] = "cc.Binary";
    return 1;
}
TOLUA_API int register_all_Binary(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_Binary_Binary(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

