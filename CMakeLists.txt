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

set(SOURCES
    xsec/enc/XSECCryptoX509.cpp
    xsec/enc/NSS/NSSCryptoHash.cpp
    xsec/enc/NSS/NSSCryptoKeyRSA.cpp
    xsec/enc/NSS/NSSCryptoHashHMAC.cpp
    xsec/enc/NSS/NSSCryptoKeyDSA.cpp
    xsec/enc/NSS/NSSCryptoSymmetricKey.cpp
    xsec/enc/NSS/NSSCryptoKeyHMAC.cpp
    xsec/enc/NSS/NSSCryptoProvider.cpp
    xsec/enc/NSS/NSSCryptoX509.cpp
    xsec/enc/WinCAPI/WinCAPICryptoKeyDSA.cpp
    xsec/enc/WinCAPI/WinCAPICryptoProvider.cpp
    xsec/enc/WinCAPI/WinCAPICryptoHashHMAC.cpp
    xsec/enc/WinCAPI/WinCAPICryptoX509.cpp
    xsec/enc/WinCAPI/WinCAPICryptoHash.cpp
    xsec/enc/WinCAPI/WinCAPICryptoKeyHMAC.cpp
    xsec/enc/WinCAPI/WinCAPICryptoKeyRSA.cpp
    xsec/enc/WinCAPI/WinCAPICryptoSymmetricKey.cpp
    xsec/enc/XSECCryptoException.cpp
    xsec/enc/XSECKeyInfoResolverDefault.cpp
    xsec/enc/XSECCryptoUtils.cpp
    xsec/enc/XSECCryptoBase64.cpp
    xsec/enc/XSCrypt/XSCryptCryptoBase64.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyHMAC.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoProvider.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoX509.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoBase64.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoHash.cpp
    xsec/enc/OpenSSL/OpenSSLSupport.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.cpp
    xsec/transformers/TXFMXPathFilter.cpp
    xsec/transformers/TXFMXSL.cpp
    xsec/transformers/TXFMConcatChains.cpp
    xsec/transformers/TXFMChar.cpp
    xsec/transformers/TXFMURL.cpp
    xsec/transformers/TXFMBase.cpp
    xsec/transformers/TXFMSB.cpp
    xsec/transformers/TXFMEnvelope.cpp
    xsec/transformers/TXFMParser.cpp
    xsec/transformers/TXFMHash.cpp
    xsec/transformers/TXFMChain.cpp
    xsec/transformers/TXFMOutputFile.cpp
    xsec/transformers/TXFMCipher.cpp
    xsec/transformers/TXFMC14n.cpp
    xsec/transformers/TXFMDocObject.cpp
    xsec/transformers/TXFMXPath.cpp
    xsec/transformers/TXFMBase64.cpp
    xsec/dsig/DSIGSignedInfo.cpp
    xsec/dsig/DSIGKeyInfoX509.cpp
    xsec/dsig/DSIGTransformXPath.cpp
    xsec/dsig/DSIGKeyInfoPGPData.cpp
    xsec/dsig/DSIGConstants.cpp
    xsec/dsig/DSIGTransformC14n.cpp
    xsec/dsig/DSIGKeyInfoExt.cpp
    xsec/dsig/DSIGAlgorithmHandlerDefault.cpp
    xsec/dsig/DSIGTransformList.cpp
    xsec/dsig/DSIGTransformEnvelope.cpp
    xsec/dsig/DSIGXPathFilterExpr.cpp
    xsec/dsig/DSIGReference.cpp
    xsec/dsig/DSIGTransformXPathFilter.cpp
    xsec/dsig/DSIGTransformXSL.cpp
    xsec/dsig/DSIGKeyInfoValue.cpp
    xsec/dsig/DSIGTransformBase64.cpp
    xsec/dsig/DSIGKeyInfoDEREncoded.cpp
    xsec/dsig/DSIGKeyInfoSPKIData.cpp
    xsec/dsig/DSIGSignature.cpp
    xsec/dsig/DSIGObject.cpp
    xsec/dsig/DSIGXPathHere.cpp
    xsec/dsig/DSIGKeyInfoName.cpp
    xsec/dsig/DSIGKeyInfoList.cpp
    xsec/dsig/DSIGTransform.cpp
    xsec/dsig/DSIGKeyInfoMgmtData.cpp
    xsec/dsig/DSIGReferenceList.cpp
    xsec/utils/XSECDOMUtils.cpp
    xsec/utils/unixutils/XSECSOAPRequestorSimpleUnix.cpp
    xsec/utils/XSECXPathNodeList.cpp
    xsec/utils/XSECSOAPRequestorSimple.cpp
    xsec/utils/XSECSafeBuffer.cpp
    xsec/utils/XSECNameSpaceExpander.cpp
    xsec/utils/XSECSafeBufferFormatter.cpp
    xsec/utils/XSECAlgorithmSupport.cpp
    xsec/utils/XSECPlatformUtils.cpp
    xsec/utils/XSECBinTXFMInputStream.cpp
    xsec/utils/XSECTXFMInputSource.cpp
    xsec/utils/winutils/XSECSOAPRequestorSimpleWin32.cpp
    xsec/xenc/impl/XENCEncryptedKeyImpl.cpp
    xsec/xenc/impl/XENCCipherValueImpl.cpp
    xsec/xenc/impl/XENCCipherReferenceImpl.cpp
    xsec/xenc/impl/XENCCipherImpl.cpp
    xsec/xenc/impl/XENCEncryptedDataImpl.cpp
    xsec/xenc/impl/XENCEncryptedTypeImpl.cpp
    xsec/xenc/impl/XENCCipherDataImpl.cpp
    xsec/xenc/impl/XENCEncryptionMethodImpl.cpp
    xsec/xenc/impl/XENCAlgorithmHandlerDefault.cpp
    xsec/framework/XSECException.cpp
    xsec/framework/XSECError.cpp
    xsec/framework/XSECURIResolverXerces.cpp
    xsec/framework/XSECAlgorithmMapper.cpp
    xsec/framework/XSECProvider.cpp
    xsec/framework/XSECEnv.cpp
    xsec/xkms/XKMSConstants.cpp
    xsec/xkms/impl/XKMSStatusRequestImpl.cpp
    xsec/xkms/impl/XKMSRespondWithImpl.cpp
    xsec/xkms/impl/XKMSMessageAbstractTypeImpl.cpp
    xsec/xkms/impl/XKMSMessageFactoryImpl.cpp
    xsec/xkms/impl/XKMSResultTypeImpl.cpp
    xsec/xkms/impl/XKMSRecoverResultImpl.cpp
    xsec/xkms/impl/XKMSResultImpl.cpp
    xsec/xkms/impl/XKMSReissueResultImpl.cpp
    xsec/xkms/impl/XKMSStatusImpl.cpp
    xsec/xkms/impl/XKMSAuthenticationImpl.cpp
    xsec/xkms/impl/XKMSLocateRequestImpl.cpp
    xsec/xkms/impl/XKMSCompoundRequestImpl.cpp
    xsec/xkms/impl/XKMSReissueKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSRevokeRequestImpl.cpp
    xsec/xkms/impl/XKMSReissueRequestImpl.cpp
    xsec/xkms/impl/XKMSResponseMechanismImpl.cpp
    xsec/xkms/impl/XKMSUnverifiedKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSValidateResultImpl.cpp
    xsec/xkms/impl/XKMSUseKeyWithImpl.cpp
    xsec/xkms/impl/XKMSPendingRequestImpl.cpp
    xsec/xkms/impl/XKMSQueryKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSRevokeKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSLocateResultImpl.cpp
    xsec/xkms/impl/XKMSValidateRequestImpl.cpp
    xsec/xkms/impl/XKMSRecoverKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSRegisterRequestImpl.cpp
    xsec/xkms/impl/XKMSRegisterResultImpl.cpp
    xsec/xkms/impl/XKMSStatusResultImpl.cpp
    xsec/xkms/impl/XKMSKeyBindingAbstractTypeImpl.cpp
    xsec/xkms/impl/XKMSNotBoundAuthentication.cpp
    xsec/xkms/impl/XKMSPrototypeKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSRequestAbstractTypeImpl.cpp
    xsec/xkms/impl/XKMSRecoverRequestImpl.cpp
    xsec/xkms/impl/XKMSValidityIntervalImpl.cpp
    xsec/xkms/impl/XKMSRSAKeyPairImpl.cpp
    xsec/xkms/impl/XKMSCompoundResultImpl.cpp
    xsec/xkms/impl/XKMSRevokeResultImpl.cpp
    xsec/canon/XSECXMLNSStack.cpp
    xsec/canon/XSECCanon.cpp
    xsec/canon/XSECC14n20010315.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/xsec/framework/XSECConfig.hpp.in
               ${CMAKE_CURRENT_BINARY_DIR}/xsec/framework/XSECConfig.hpp)

add_library(xml-security-c ${SOURCES})

target_include_directories(
  xml-security-c
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(xml-security-c PUBLIC XercesC::XercesC OpenSSL::Crypto)

if(USE_XALAN)
  target_link_libraries(xml-security-c PUBLIC XalanC::XalanC)
endif()

if(WIN32)
  set(xmlsecurityc_config_dir "cmake")
else()
  set(xmlsecurityc_config_dir "${CMAKE_INSTALL_LIBDIR}/cmake/XmlSecurityC")
endif()

install(TARGETS xml-security-c
  EXPORT XmlSecurityCConfigInternal
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT "runtime"
  INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(EXPORT XmlSecurityCConfigInternal
        DESTINATION "${xmlsecurityc_config_dir}"
        NAMESPACE "xmlsecurityc_"
        COMPONENT "development")

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/XmlSecurityCConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/XmlSecurityCConfig.cmake"
  INSTALL_DESTINATION "${xmlsecurityc_config_dir}")
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/XmlSecurityCConfigVersion.cmake
  VERSION "${PROJECT_VERSION}"
  COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/XmlSecurityCConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/XmlSecurityCConfigVersion.cmake
              DESTINATION "${xmlsecurityc_config_dir}")
