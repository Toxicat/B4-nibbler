//
// Library.hpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 12:21:01 2014 Nathan AUBERT
// Last update Sun Apr  6 12:21:17 2014 Nathan AUBERT
//

#ifndef NIBBLER_LIBRARY_HPP_
# define NIBBLER_LIBRARY_HPP_

# include <iostream>

# if defined(__GNUG__)
#  include <dlfcn.h>
#elif defined(_MSC_VER)
#  include <Windows.h>
#  include <atlstr.h>
#  include <string>
# else
#  error G++ or MS compiler required
#endif

namespace Library
{
# if defined(_MSC_VER)
  void    convert_name(std::string &dllName)
  {
    const size_t  pos = dllName.rfind(".so");

    if (pos != std::string::npos)
      dllName.replace(pos, std::string::npos, ".dll");
  }
# endif

  void    *open(const char *filename)
  {
    std::string dllName(filename);

# if defined(__GNUG__)
    return dlopen(filename, RTLD_LAZY);
# elif defined(_MSC_VER)
    convert_name(dllName);
    std::cout << dllName << std::endl;
    return LoadLibrary(dllName.c_str());
# else
#		error G++ or MS compiler required
# endif
  }

  void    *sym(void *handle, const char *symbol)
  {
# if defined(__GNUG__)
    return dlsym(handle, symbol);
# elif defined(_MSC_VER)
    return GetProcAddress(reinterpret_cast<HMODULE>(handle), symbol);
# else
#		error G++ or MS compiler required
# endif
  }

  char            *error(void)
  {
# if defined(__GNUG__)
    return dlerror();
# elif defined(_MSC_VER)
    int         error_code;
    static char errstr[128];

    if((error_code = GetLastError()) == 0)
      return((char *)0);
    SetLastError(0);
    sprintf_s(errstr, "Error <%d>\n", error_code);
    return errstr;
# else
#		error G++ or MS compiler required
# endif
  }

  int		close(void *handle)
  {
# if defined(__GNUG__)
    return dlclose(handle);
# elif defined(_MSC_VER)
    if (FreeLibrary(reinterpret_cast<HMODULE>(handle)) == 0)
      return GetLastError();
    return 0;
# else
#		error G++ or MS compiler required
# endif
  }
}

#endif /* !NIBBLER_LIBRARY_HPP_ */
