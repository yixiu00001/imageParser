# Install script for directory: /home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libintegraltransform.so.0.3.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libintegraltransform.so.0.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libintegraltransform.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/yx/fr/project/imageParser/vosm-0.3.3/lib/libintegraltransform.so.0.3.2"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/lib/libintegraltransform.so.0.3"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/lib/libintegraltransform.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libintegraltransform.so.0.3.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libintegraltransform.so.0.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libintegraltransform.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vosm/integraltransform" TYPE FILE FILES
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_Gabor.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_ReverseBiorthogonal.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_Symlets.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_DiscreteWavelet.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_Gauss.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_Coiflets.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_CohenDaubechiesFeauveau.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_WindowFunc.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_DiscreteFIRMeyer.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_IntegralTransform.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_Haar.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_STFT.h"
    "/home/yx/fr/project/imageParser/vosm-0.3.3/modules/integraltransform/include/VO_Daubechies.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

