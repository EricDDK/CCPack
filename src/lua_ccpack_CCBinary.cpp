#include "lua_ccpack_CCBinary.hpp"
#include "CCBinary.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_ccbinary_CCBinary_writeByte(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "cc.CCBinary:writeByte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeByte'", nullptr);
            return 0;
        }
        cobj->writeByte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeByte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeByte'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "cc.CCBinary:writeShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeShort'", nullptr);
            return 0;
        }
        cobj->writeShort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeShort'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readBool(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readBool'", nullptr);
            return 0;
        }
        bool ret = cobj->readBool();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readBool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readBool'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readChar'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readChar'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readByte(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readByte'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->readByte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readByte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readByte'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_initWrite(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_initWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_initWrite'", nullptr);
            return 0;
        }
        bool ret = cobj->initWrite();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:initWrite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_initWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.CCBinary:writeString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeString'", nullptr);
            return 0;
        }
        cobj->writeString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeString'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readFloat'", nullptr);
            return 0;
        }
        double ret = cobj->readFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCBinary:writeDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeDouble'", nullptr);
            return 0;
        }
        cobj->writeDouble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeBool(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.CCBinary:writeBool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeBool'", nullptr);
            return 0;
        }
        cobj->writeBool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeBool'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCBinary:writeFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeFloat'", nullptr);
            return 0;
        }
        cobj->writeFloat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_isBigEndian(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_isBigEndian'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_isBigEndian'", nullptr);
            return 0;
        }
        const bool ret = cobj->isBigEndian();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:isBigEndian",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_isBigEndian'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readShort'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "cc.CCBinary:writeChar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeChar'", nullptr);
            return 0;
        }
        cobj->writeChar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeChar'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readInt'", nullptr);
            return 0;
        }
        int ret = cobj->readInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readInt'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_initRead(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_initRead'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.CCBinary:initRead");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_initRead'", nullptr);
            return 0;
        }
        bool ret = cobj->initRead(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:initRead",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_initRead'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_setEndian(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_setEndian'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.CCBinary:setEndian");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_setEndian'", nullptr);
            return 0;
        }
        cobj->setEndian(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:setEndian",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_setEndian'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readDouble'", nullptr);
            return 0;
        }
        double ret = cobj->readDouble();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readDouble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readString'", nullptr);
            return 0;
        }
        char* ret = cobj->readString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readString'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "cc.CCBinary:writeLong");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeLong'", nullptr);
            return 0;
        }
        cobj->writeLong(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeLong",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeLong'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_readLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_readLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_readLong'", nullptr);
            return 0;
        }
        long long ret = cobj->readLong();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:readLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_readLong'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_writeInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBinary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ccbinary_CCBinary_writeInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.CCBinary:writeInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_writeInt'", nullptr);
            return 0;
        }
        cobj->writeInt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:writeInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_writeInt'.",&tolua_err);
#endif

    return 0;
}
int lua_ccbinary_CCBinary_createRead(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.CCBinary:createRead");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_createRead'", nullptr);
            return 0;
        }
        cocos2d::CCBinary* ret = cocos2d::CCBinary::createRead(arg0);
        object_to_luaval<cocos2d::CCBinary>(tolua_S, "cc.CCBinary",(cocos2d::CCBinary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.CCBinary:createRead",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_createRead'.",&tolua_err);
#endif
    return 0;
}
int lua_ccbinary_CCBinary_createWrite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCBinary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_createWrite'", nullptr);
            return 0;
        }
        cocos2d::CCBinary* ret = cocos2d::CCBinary::createWrite();
        object_to_luaval<cocos2d::CCBinary>(tolua_S, "cc.CCBinary",(cocos2d::CCBinary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.CCBinary:createWrite",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_createWrite'.",&tolua_err);
#endif
    return 0;
}
int lua_ccbinary_CCBinary_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBinary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ccbinary_CCBinary_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::CCBinary();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.CCBinary");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCBinary:CCBinary",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_ccbinary_CCBinary_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_ccbinary_CCBinary_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCBinary)");
    return 0;
}

int lua_register_ccbinary_CCBinary(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCBinary");
    tolua_cclass(tolua_S,"CCBinary","cc.CCBinary","",nullptr);

    tolua_beginmodule(tolua_S,"CCBinary");
        tolua_function(tolua_S,"new",lua_ccbinary_CCBinary_constructor);
        tolua_function(tolua_S,"writeByte",lua_ccbinary_CCBinary_writeByte);
        tolua_function(tolua_S,"writeShort",lua_ccbinary_CCBinary_writeShort);
        tolua_function(tolua_S,"readBool",lua_ccbinary_CCBinary_readBool);
        tolua_function(tolua_S,"readChar",lua_ccbinary_CCBinary_readChar);
        tolua_function(tolua_S,"readByte",lua_ccbinary_CCBinary_readByte);
        tolua_function(tolua_S,"initWrite",lua_ccbinary_CCBinary_initWrite);
        tolua_function(tolua_S,"writeString",lua_ccbinary_CCBinary_writeString);
        tolua_function(tolua_S,"readFloat",lua_ccbinary_CCBinary_readFloat);
        tolua_function(tolua_S,"writeDouble",lua_ccbinary_CCBinary_writeDouble);
        tolua_function(tolua_S,"writeBool",lua_ccbinary_CCBinary_writeBool);
        tolua_function(tolua_S,"writeFloat",lua_ccbinary_CCBinary_writeFloat);
        tolua_function(tolua_S,"isBigEndian",lua_ccbinary_CCBinary_isBigEndian);
        tolua_function(tolua_S,"readShort",lua_ccbinary_CCBinary_readShort);
        tolua_function(tolua_S,"writeChar",lua_ccbinary_CCBinary_writeChar);
        tolua_function(tolua_S,"readInt",lua_ccbinary_CCBinary_readInt);
        tolua_function(tolua_S,"initRead",lua_ccbinary_CCBinary_initRead);
        tolua_function(tolua_S,"setEndian",lua_ccbinary_CCBinary_setEndian);
        tolua_function(tolua_S,"readDouble",lua_ccbinary_CCBinary_readDouble);
        tolua_function(tolua_S,"readString",lua_ccbinary_CCBinary_readString);
        tolua_function(tolua_S,"writeLong",lua_ccbinary_CCBinary_writeLong);
        tolua_function(tolua_S,"readLong",lua_ccbinary_CCBinary_readLong);
        tolua_function(tolua_S,"writeInt",lua_ccbinary_CCBinary_writeInt);
        tolua_function(tolua_S,"createRead", lua_ccbinary_CCBinary_createRead);
        tolua_function(tolua_S,"createWrite", lua_ccbinary_CCBinary_createWrite);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCBinary).name();
    g_luaType[typeName] = "cc.CCBinary";
    g_typeCast["CCBinary"] = "cc.CCBinary";
    return 1;
}
TOLUA_API int register_all_ccbinary(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_ccbinary_CCBinary(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

