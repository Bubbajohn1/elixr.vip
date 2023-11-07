#pragma once

#include "../utils/vector.hpp"

class input_message {
  public:
    void set_aim_angles( vec3 );
};

class input_state {
  public:
    input_message* get_input_message(  );
};

class player_input {
  public:
    vec2 get_view_angles(  );
    vec2 get_recoil_angles(  );
    
    void set_view_angles( vec2 angle );
    void set_head_rotation( vec4 angle );
    void set_recoil_angles( vec2 angle );

    input_state* get_input_state();
};

class c_baseplayer {
  public:
      
};
