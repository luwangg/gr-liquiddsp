#
# Find the LiquidDSP includes and library
#
# This module defines
# LIQUID_INCLUDE_DIR, where to find liquid.h, etc.
# LIQUID_LIBRARIES, the libraries to link against to use Liquid.
# LIQUID_FOUND, If false, do not try to use Liquid.

INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_LIQUID "liquid")

FIND_PATH(LIQUID_INCLUDE_DIRS
    NAMES liquid/liquid.h
    HINTS ${PC_LIQUID_INCLUDE_DIR}
    PATHS
    /usr/local/include
    /usr/include
)

FIND_LIBRARY(LIQUID_LIBRARIES
    NAMES liquid
    HINTS ${PC_LIQUID_LIBDIR}
    PATHS
    ${LIQUID_INCLUDE_DIRS}/../lib
    /usr/local/lib
    /usr/lib
)

LIST(APPEND LIQUID_LIBRARIES ${CMAKE_DL_LIBS})
SET(LIQUID_LIBRARY_DIRS ${PC_LIQUID_LIBDIR})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIQUID DEFAULT_MSG
  LIQUID_LIBRARIES LIQUID_INCLUDE_DIRS LIQUID_LIBRARY_DIRS)
MARK_AS_ADVANCED(LIQUID_LIBRARIES LIQUID_INCLUDE_DIRS LIQUID_LIBRARY_DIRS)
