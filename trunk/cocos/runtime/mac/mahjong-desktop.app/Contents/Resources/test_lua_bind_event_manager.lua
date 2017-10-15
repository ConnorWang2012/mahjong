print( "[test lua_bind_event_manager]" )

local event_manager = gamer.EventManager:getInstance()
print( "enabled : " .. tostring(event_manager:is_enabled()) )

event_manager:dispatchEvent( 2014 )
event_manager:dispatchEvent( 2015 )

print( "[test lua_bind_event_manager] success" )
