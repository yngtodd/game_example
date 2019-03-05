#pragma once

#ifdef _MSC_VER
#  ifdef GAME_EXPORTS
#   define GAME_API __declspec(dllexport)
#  else
#    ifdef GAME_IMPORTS
#     define GAME_API __declspec(dllimport)
#    else
#	  define GAME_API
#    endif
#  endif
#endif
