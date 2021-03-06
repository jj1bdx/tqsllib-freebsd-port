#KC2YWE - Copied from 2.8 dist and modified

# - Find curl
# Find the native CURL headers and libraries.
#
#  CURL_INCLUDE_DIRS - where to find curl/curl.h, etc.
#  CURL_LIBRARIES    - List of libraries when using curl.
#  CURL_FOUND        - True if curl found.

#=============================================================================
# Copyright 2006-2009 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

# Look for the header file.
FIND_PATH(CURL_INCLUDE_DIR curl/curl.h
	#for windows, there has to be a better way
	"C:\\curl\\include\\"
	"C:\\curl-7.31.0\\builds\\libcurl-vc-x86-release-static-ipv6-sspi-spnego-winssl\\include"
	"C:\\curl-7.29.0\\builds\\libcurl-vc-x86-release-static-ipv6-sspi-spnego-winssl\\include"
	"C:\\curl-7.28.1\\builds\\libcurl-vc-x86-release-static-ipv6-sspi-spnego-winssl\\include"
)
MARK_AS_ADVANCED(CURL_INCLUDE_DIR)

# Look for the library.
FIND_LIBRARY(CURL_LIBRARY NAMES 
    curl
  # Windows MSVC prebuilts:
    curllib
	libcurl_a
	libcurl
    libcurl_imp
    curllib_static
	PATHS
	"C:\\curl-7.31.0\\builds\\libcurl-vc-x86-release-static-ipv6-sspi-spnego-winssl\\lib" #winssl
	"C:\\curl-7.29.0\\builds\\libcurl-vc-x86-release-static-ipv6-sspi-spnego-winssl\\lib" #winssl
	"C:\\curl-7.28.1\\builds\\libcurl-vc-x86-release-static-ipv6-sspi-spnego-winssl\\lib" #winssl
	"C:\\curl\\lib\\"
	"C:\\curl-7.28.1\\lib\\"
)
MARK_AS_ADVANCED(CURL_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set CURL_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CURL DEFAULT_MSG CURL_LIBRARY CURL_INCLUDE_DIR)

IF(CURL_FOUND)
  SET(CURL_LIBRARIES ${CURL_LIBRARY})
  SET(CURL_INCLUDE_DIRS ${CURL_INCLUDE_DIR})
ENDIF(CURL_FOUND)
