cmake_minimum_required(VERSION 3.20...3.27)

include(CheckCXXSourceCompiles)

project(
  xml-security-c
  VERSION 2.0.4
  DESCRIPTION "Apache XML security C++ library"
  LANGUAGES CXX)

option(USE_XALAN "Enable Xalan integration" OFF)

find_package(XercesC REQUIRED)

if(USE_XALAN)
  find_package(XalanC REQUIRED)
  set(XSEC_HAVE_XALAN TRUE)
endif()

find_package(OpenSSL REQUIRED)
set(XSEC_HAVE_OPENSSL TRUE)

add_subdirectory(xsec)
