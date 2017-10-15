print( "[test lua_bind_event_listener]" )

local function event_callback( event )

    print( "[event_callback] event_callback be called!" )
    if nil == event then
        print( "[event_callback] nil == event" )
        return
    end

    local event = tolua.cast( event, "gamer::Event" )
    print( "[event_callback] event_id : " .. event:event_id() )

end

--print( "1" )
--local cb = tolua.cast( event_callback, "std::function<void(gamer::Event*)>" )
local event_listener = gamer.EventListener:create( 2014, event_callback, "my_event_name1", 1 )
--print( "2" )
if nil == event_listener then
    print( "nil == event_listener" )
    return
end
--print( "3" )
local listener_name = event_listener:listener_name()
local event_id = event_listener:event_id()
print( "listener_name1 : " .. listener_name ) 
print( "event_id1 : " .. event_id )


local event_listener2 = gamer.EventListener:create( 2015, event_callback, "my_event_name2", 2)
local listener_name2 = event_listener2:listener_name()
local event_id2 = event_listener2:event_id()
print( "listener_name2 : " .. listener_name2 ) 
print( "event_id2 : " .. event_id2 )

local event_manager = gamer.EventManager:getInstance()
event_manager:addEventListener( event_listener )
event_manager:addEventListener( event_listener2 )
--event_manager:dispatchEvent( 2014 )
print( "[test lua_bind_event_listener] success" )