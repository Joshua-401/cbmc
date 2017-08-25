/*******************************************************************\

Module: Read OS X Fat Binaries

Author:

\*******************************************************************/

/// \file
/// Read OS X Fat Binaries

#ifndef CPROVER_GOTO_PROGRAMS_OSX_FAT_READER_H
#define CPROVER_GOTO_PROGRAMS_OSX_FAT_READER_H

#include <fstream>
#include <string>

// we follow
// https://developer.apple.com/library/mac/#documentation/DeveloperTools/Conceptual/MachORuntime/Reference/reference.html

class osx_fat_readert
{
public:
  explicit osx_fat_readert(std::ifstream &in);

  bool has_gb() const { return has_gb_arch; }

  bool extract_gb(
    const std::string &source,
    const std::string &dest) const;

private:
  bool has_gb_arch;
};

bool is_osx_fat_magic(char hdr[4]);

#endif // CPROVER_GOTO_PROGRAMS_OSX_FAT_READER_H
