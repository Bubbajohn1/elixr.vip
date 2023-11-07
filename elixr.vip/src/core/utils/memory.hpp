#pragma once

#include <cstdint>
#include <vector>
#include <stdlib.h>
#include <limits.h>
#include <cctype>
#include <climits>

namespace memory {
  uintptr_t sigscan( const char* module, const char* pattern, int jump = 0 );
  uintptr_t find( uintptr_t range_start, uintptr_t range_end, const char* pattern );
  uintptr_t find( const char* mod, const char* pattern );
  uintptr_t find_rel( const char* mod, const char* pattern, ptrdiff_t position = 0, ptrdiff_t jump_size = 3, ptrdiff_t instruction_size = 7 );

  template< typename T = uintptr_t >
  T read( uintptr_t address ) {
    if( !address )
      return T(  );
    else if( address < 0xffffff )
      return T( );
    else if( address > 0x7fffffff0000 )
      return T( );
    else
      return *reinterpret_cast< T* >( address );
  }

  template< typename T >
  T read_chain( uintptr_t address, std::vector< uintptr_t > chain ) {
    uintptr_t current_address = address;

    for( int i = 0; i < chain.size( ) - 1; ++i )
      current_address = read< uintptr_t >( current_address + chain[ i ] );

    return read< T >( current_address + chain[ chain.size() - 1 ] );
  }
} // memory namespace
