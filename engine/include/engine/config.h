#pragma once

#ifdef _MSC_VER
#  ifdef ENGINE_EXPORTS
#   define ENGINE_API __declspec(dllexport)
#  else
#    ifdef ENGINE_IMPORTS
#     define ENGINE_API __declspec(dllimport)
#    else
#	  define ENGINE_API
#    endif
#  endif
#endif
