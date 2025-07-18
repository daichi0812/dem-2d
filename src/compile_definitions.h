#ifndef COMPILE_DEFINITIONS_H
#define COMPILE_DEFINITIONS_H

namespace CompileDefinitions
{

    // SHA1 hash of the Git commit for this build
    constexpr char GitSHA1[] = "GITDIR-NOTFOUND";

    // Build mode (Debug, Release, etc)
    constexpr char BuildMode[] = "Release";

    // C compiler used for this build
    constexpr char CCompiler[] = "/usr/bin/cc";

    // C++ compiler used for this build
    constexpr char CXXCompiler[] = "/usr/bin/c++";

    // Date and time
    constexpr char BuildDateTime[] = "2025-07-08 17:31:41";

}

#endif
