#include "c_baseplayer.h"
#include "../il2.hpp"
#include "../utils/xor.hpp"
#include "../offsets.hpp"

void input_message::set_aim_angles( vec3 value ) {
  uintptr_t entity = reinterpret_cast< uintptr_t >( this );

  if( !entity )
    return;

  uintptr_t addr = 0;

  if( !addr )
    return;

  *reinterpret_cast< vec3* >( entity + addr ) = value;
}

input_message* input_state::get_input_message(  ) {
  uintptr_t entity = reinterpret_cast< uintptr_t >( this );

  if( !entity )
    return NULL;
  
  uintptr_t addr = 0;

  if( !addr )
    return NULL;

  return *reinterpret_cast< input_message** >( entity + addr );
}

vec2 player_input::get_view_angles(  ) {
  uintptr_t entity = reinterpret_cast< uintptr_t >( this );
  
  if( !entity )
    return vec2(  );

  uintptr_t addr = 0;

  if( !addr )
    return vec2(  );

  return *reinterpret_cast< vec2* >( entity + addr );
}
