#pragma once

#include <string>
#include "utils/lazy_importer.hpp"

// '##' merges the two values provided. example: STR_MERGE_IMPL(10, 20) output: 1020
// example: MERGE(10, 10); output = 1020
#define MERGE( a, b ) a##b

// Declares a variable and uses the counter to seperate the vars.
// example: MAKE_PAD(10) = _pad0[10]
// example: MAKE_PAD(15) = _pad1[15]
#define MAKE_PAD( size ) MERGE( _pad, __COUNTER__ )[ size ]

// Defines a struct with 2 items stored in it. One being a pad with the size of the given offset,
// the other with the type and name given
// example: DEFINE_MEMBER( int, example_var, 8 ) = struct { unsigned char _pad0[8]; int example_var; }
#define DEFINE_MEMBER( type, name, offset ) struct { unsigned char MAKE_PAD( offset ); type name; }

namespace il2 {
  inline uintptr_t game_assembly = 0;
  inline uintptr_t unity_player = 0;

  void init(  );

  uintptr_t init_class( const char* name, const char* name_space = ( "" ) );
  uintptr_t method( std::string kl, std::string name, int param_count, const char* name_space = ( "" ), bool param_check = false, int param_idx = 0, std::string param_name = "" );
  uintptr_t hook(void* our_func, std::string kl, std::string name, int arg, const char* name_space = (""));
  uintptr_t hook_virt(const char* classname, const char* function_to_hook, void* our_func, int param_count, const char* name_space = (""));
  uintptr_t field(uintptr_t klass, const char* field_name);
  uintptr_t value(const char* kl, const char* name, bool get_offset = true, const char* name_space = (""));
  uintptr_t type_object(const char* name_space, const char* name);

  class il2cppstring
  {
  public:
	  char pad_0000[0x10];
	  int len;
	  wchar_t buffer[0];

	  static il2cppstring* New(const char* str);
  };

  namespace methods
  {
	  using il2cpp_domain_get = uintptr_t(*)();
	  static il2cpp_domain_get domain_get = LI_FIND_DEF(il2cpp_domain_get);

	  using il2cpp_class_get_methods = uintptr_t(*)(uintptr_t, uintptr_t*);
	  static auto class_get_methods = LI_FIND_DEF(il2cpp_class_get_methods);

	  using il2cpp_method_get_param = uintptr_t(*)(uintptr_t, int);
	  static auto method_get_param = LI_FIND_DEF(il2cpp_method_get_param);

	  using il2cpp_method_get_param_count = int (*)(uintptr_t);
	  static auto method_get_param_count = LI_FIND_DEF(il2cpp_method_get_param_count);

	  using il2cpp_assembly_get_image = uintptr_t(*)(uintptr_t);
	  static auto assembly_get_image = LI_FIND_DEF(il2cpp_assembly_get_image);

	  using il2cpp_domain_get_assemblies = uintptr_t * (*)(void* domain, uintptr_t* size);
	  static auto domain_get_assemblies = LI_FIND_DEF(il2cpp_domain_get_assemblies);

	  using il2cpp_object_new = uintptr_t(*)(uintptr_t);
	  static auto object_new = LI_FIND_DEF(il2cpp_object_new);

	  using il2cpp_type_get_object = uintptr_t(*)(uintptr_t);
	  static auto type_get_object = LI_FIND_DEF(il2cpp_type_get_object);

	  using il2cpp_class_get_type = uintptr_t(*)(uintptr_t);
	  static auto class_get_type = LI_FIND_DEF(il2cpp_class_get_type);

	  using il2cpp_class_from_name = uintptr_t(*)(uintptr_t, const char*, const char*);
	  static auto class_from_name = LI_FIND_DEF(il2cpp_class_from_name);

	  using il2cpp_resolve_icall = uintptr_t(*)(const char*);
	  static auto resolve_icall = LI_FIND_DEF(il2cpp_resolve_icall);

	  using il2cpp_class_get_field_from_name = uintptr_t(*)(uintptr_t, const char*);
	  static auto class_get_field_from_name = LI_FIND_DEF(il2cpp_class_get_field_from_name);

	  using il2cpp_field_static_get_value = uintptr_t(*)(uintptr_t, uintptr_t*);
	  static auto field_static_get_value = LI_FIND_DEF(il2cpp_field_static_get_value);

	  using il2cpp_class_get_fields = uintptr_t(*)(uintptr_t, uintptr_t*);
	  static auto class_get_fields = LI_FIND_DEF(il2cpp_class_get_fields);

	  using il2cpp_field_get_offset = uintptr_t(*)(uintptr_t);
	  static auto field_get_offset = LI_FIND_DEF(il2cpp_field_get_offset);

	  using il2cpp_runtime_class_init = uintptr_t(*)(uintptr_t);
	  static auto runtime_class_init = LI_FIND_DEF(il2cpp_runtime_class_init);

	  using il2cpp_string_new_wrapper = il2cppstring * (*)(const char*);
	  static auto new_string = LI_FIND_DEF(il2cpp_string_new_wrapper);

	  using  il2cpp_class_get_method_from_name = uintptr_t(*)(uintptr_t, const char*, int);
	  static il2cpp_class_get_method_from_name class_get_method_from_name = LI_FIND_DEF(il2cpp_class_get_method_from_name);
  } // methods namespace
} // il2 namespace
