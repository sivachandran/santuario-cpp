set(SOURCES
    enc/XSECCryptoX509.cpp
    enc/NSS/NSSCryptoHash.cpp
    enc/NSS/NSSCryptoKeyRSA.cpp
    enc/NSS/NSSCryptoHashHMAC.cpp
    enc/NSS/NSSCryptoKeyDSA.cpp
    enc/NSS/NSSCryptoSymmetricKey.cpp
    enc/NSS/NSSCryptoKeyHMAC.cpp
    enc/NSS/NSSCryptoProvider.cpp
    enc/NSS/NSSCryptoX509.cpp
    enc/WinCAPI/WinCAPICryptoKeyDSA.cpp
    enc/WinCAPI/WinCAPICryptoProvider.cpp
    enc/WinCAPI/WinCAPICryptoHashHMAC.cpp
    enc/WinCAPI/WinCAPICryptoX509.cpp
    enc/WinCAPI/WinCAPICryptoHash.cpp
    enc/WinCAPI/WinCAPICryptoKeyHMAC.cpp
    enc/WinCAPI/WinCAPICryptoKeyRSA.cpp
    enc/WinCAPI/WinCAPICryptoSymmetricKey.cpp
    enc/XSECCryptoException.cpp
    enc/XSECKeyInfoResolverDefault.cpp
    enc/XSECCryptoUtils.cpp
    enc/XSECCryptoBase64.cpp
    enc/XSCrypt/XSCryptCryptoBase64.cpp
    enc/OpenSSL/OpenSSLCryptoKeyHMAC.cpp
    enc/OpenSSL/OpenSSLCryptoProvider.cpp
    enc/OpenSSL/OpenSSLCryptoSymmetricKey.cpp
    enc/OpenSSL/OpenSSLCryptoX509.cpp
    enc/OpenSSL/OpenSSLCryptoBase64.cpp
    enc/OpenSSL/OpenSSLCryptoHash.cpp
    enc/OpenSSL/OpenSSLSupport.cpp
    enc/OpenSSL/OpenSSLCryptoKeyDSA.cpp
    enc/OpenSSL/OpenSSLCryptoHashHMAC.cpp
    enc/OpenSSL/OpenSSLCryptoKeyEC.cpp
    enc/OpenSSL/OpenSSLCryptoKeyRSA.cpp
    transformers/TXFMXPathFilter.cpp
    transformers/TXFMXSL.cpp
    transformers/TXFMConcatChains.cpp
    transformers/TXFMChar.cpp
    transformers/TXFMURL.cpp
    transformers/TXFMBase.cpp
    transformers/TXFMSB.cpp
    transformers/TXFMEnvelope.cpp
    transformers/TXFMParser.cpp
    transformers/TXFMHash.cpp
    transformers/TXFMChain.cpp
    transformers/TXFMOutputFile.cpp
    transformers/TXFMCipher.cpp
    transformers/TXFMC14n.cpp
    transformers/TXFMDocObject.cpp
    transformers/TXFMXPath.cpp
    transformers/TXFMBase64.cpp
    dsig/DSIGSignedInfo.cpp
    dsig/DSIGKeyInfoX509.cpp
    dsig/DSIGTransformXPath.cpp
    dsig/DSIGKeyInfoPGPData.cpp
    dsig/DSIGConstants.cpp
    dsig/DSIGTransformC14n.cpp
    dsig/DSIGKeyInfoExt.cpp
    dsig/DSIGAlgorithmHandlerDefault.cpp
    dsig/DSIGTransformList.cpp
    dsig/DSIGTransformEnvelope.cpp
    dsig/DSIGXPathFilterExpr.cpp
    dsig/DSIGReference.cpp
    dsig/DSIGTransformXPathFilter.cpp
    dsig/DSIGTransformXSL.cpp
    dsig/DSIGKeyInfoValue.cpp
    dsig/DSIGTransformBase64.cpp
    dsig/DSIGKeyInfoDEREncoded.cpp
    dsig/DSIGKeyInfoSPKIData.cpp
    dsig/DSIGSignature.cpp
    dsig/DSIGObject.cpp
    dsig/DSIGXPathHere.cpp
    dsig/DSIGKeyInfoName.cpp
    dsig/DSIGKeyInfoList.cpp
    dsig/DSIGTransform.cpp
    dsig/DSIGKeyInfoMgmtData.cpp
    dsig/DSIGReferenceList.cpp
    utils/XSECDOMUtils.cpp
    utils/unixutils/XSECSOAPRequestorSimpleUnix.cpp
    utils/XSECXPathNodeList.cpp
    utils/XSECSOAPRequestorSimple.cpp
    utils/XSECSafeBuffer.cpp
    utils/XSECNameSpaceExpander.cpp
    utils/XSECSafeBufferFormatter.cpp
    utils/XSECAlgorithmSupport.cpp
    utils/XSECPlatformUtils.cpp
    utils/XSECBinTXFMInputStream.cpp
    utils/XSECTXFMInputSource.cpp
    utils/winutils/XSECSOAPRequestorSimpleWin32.cpp
    xenc/impl/XENCEncryptedKeyImpl.cpp
    xenc/impl/XENCCipherValueImpl.cpp
    xenc/impl/XENCCipherReferenceImpl.cpp
    xenc/impl/XENCCipherImpl.cpp
    xenc/impl/XENCEncryptedDataImpl.cpp
    xenc/impl/XENCEncryptedTypeImpl.cpp
    xenc/impl/XENCCipherDataImpl.cpp
    xenc/impl/XENCEncryptionMethodImpl.cpp
    xenc/impl/XENCAlgorithmHandlerDefault.cpp
    framework/XSECException.cpp
    framework/XSECError.cpp
    framework/XSECURIResolverXerces.cpp
    framework/XSECAlgorithmMapper.cpp
    framework/XSECProvider.cpp
    framework/XSECEnv.cpp
    xkms/XKMSConstants.cpp
    xkms/impl/XKMSStatusRequestImpl.cpp
    xkms/impl/XKMSRespondWithImpl.cpp
    xkms/impl/XKMSMessageAbstractTypeImpl.cpp
    xkms/impl/XKMSMessageFactoryImpl.cpp
    xkms/impl/XKMSResultTypeImpl.cpp
    xkms/impl/XKMSRecoverResultImpl.cpp
    xkms/impl/XKMSResultImpl.cpp
    xkms/impl/XKMSReissueResultImpl.cpp
    xkms/impl/XKMSStatusImpl.cpp
    xkms/impl/XKMSAuthenticationImpl.cpp
    xkms/impl/XKMSLocateRequestImpl.cpp
    xkms/impl/XKMSCompoundRequestImpl.cpp
    xkms/impl/XKMSReissueKeyBindingImpl.cpp
    xkms/impl/XKMSRevokeRequestImpl.cpp
    xkms/impl/XKMSReissueRequestImpl.cpp
    xkms/impl/XKMSResponseMechanismImpl.cpp
    xkms/impl/XKMSUnverifiedKeyBindingImpl.cpp
    xkms/impl/XKMSValidateResultImpl.cpp
    xkms/impl/XKMSUseKeyWithImpl.cpp
    xkms/impl/XKMSPendingRequestImpl.cpp
    xkms/impl/XKMSQueryKeyBindingImpl.cpp
    xkms/impl/XKMSRevokeKeyBindingImpl.cpp
    xkms/impl/XKMSLocateResultImpl.cpp
    xkms/impl/XKMSValidateRequestImpl.cpp
    xkms/impl/XKMSRecoverKeyBindingImpl.cpp
    xkms/impl/XKMSRegisterRequestImpl.cpp
    xkms/impl/XKMSRegisterResultImpl.cpp
    xkms/impl/XKMSStatusResultImpl.cpp
    xkms/impl/XKMSKeyBindingAbstractTypeImpl.cpp
    xkms/impl/XKMSNotBoundAuthentication.cpp
    xkms/impl/XKMSPrototypeKeyBindingImpl.cpp
    xkms/impl/XKMSKeyBindingImpl.cpp
    xkms/impl/XKMSRequestAbstractTypeImpl.cpp
    xkms/impl/XKMSRecoverRequestImpl.cpp
    xkms/impl/XKMSValidityIntervalImpl.cpp
    xkms/impl/XKMSRSAKeyPairImpl.cpp
    xkms/impl/XKMSCompoundResultImpl.cpp
    xkms/impl/XKMSRevokeResultImpl.cpp
    canon/XSECXMLNSStack.cpp
    canon/XSECCanon.cpp
    canon/XSECC14n20010315.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/framework/XSECConfig.hpp.in
               ${CMAKE_CURRENT_BINARY_DIR}/framework/XSECConfig.hpp)

add_library(xml-security-c ${SOURCES})

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_SOURCE_DIR)
cmake_path(GET CMAKE_CURRENT_BINARY_DIR PARENT_PATH PARENT_BINARY_DIR)

target_include_directories(
  xml-security-c
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${PARENT_SOURCE_DIR}/include>
  PRIVATE ${PARENT_BINARY_DIR})

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
