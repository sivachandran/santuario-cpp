cmake_minimum_required(VERSION 3.12...3.27)

# Xerces-C++ require C++17
set(CMAKE_CXX_STANDARD 17)

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

#
# The following are sample programs.  They are NOT installed
#

add_custom_target(samples)

# HMAC sign

set(xsec_simpleHMAC_SOURCES
    xsec/samples/simpleHMAC.cpp
    xsec/samples/IOStreamOutputter.cpp
    xsec/samples/IOStreamOutputter.hpp)
add_executable(simpleHMAC EXCLUDE_FROM_ALL ${xsec_simpleHMAC_SOURCES})
target_include_directories(simpleHMAC PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(simpleHMAC xml-security-c)
add_dependencies(samples simpleHMAC)

# HMAC validate

set(xsec_simpleValidate_SOURCES
    xsec/samples/simpleValidate.cpp
    xsec/samples/IOStreamOutputter.cpp
    xsec/samples/IOStreamOutputter.hpp)
add_executable(simpleValidate EXCLUDE_FROM_ALL ${xsec_simpleValidate_SOURCES})
target_include_directories(simpleValidate PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(simpleValidate xml-security-c)
add_dependencies(samples simpleValidate)

# Encrypt

set(xsec_simpleEncrypt_SOURCES
    xsec/samples/simpleEncrypt.cpp
    xsec/samples/IOStreamOutputter.cpp
    xsec/samples/IOStreamOutputter.hpp)
add_executable(simpleEncrypt EXCLUDE_FROM_ALL ${xsec_simpleEncrypt_SOURCES})
target_include_directories(simpleEncrypt PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(simpleEncrypt xml-security-c)
add_dependencies(samples simpleEncrypt)

# Decrypt

set(xsec_simpleDecrypt_SOURCES
    xsec/samples/simpleDecrypt.cpp
    xsec/samples/IOStreamOutputter.cpp
    xsec/samples/IOStreamOutputter.hpp)
add_executable(simpleDecrypt EXCLUDE_FROM_ALL ${xsec_simpleDecrypt_SOURCES})
target_include_directories(simpleDecrypt PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(simpleDecrypt xml-security-c)
add_dependencies(samples simpleDecrypt)

#
# Finally we compile the tools that can be used to manipulate
# XML Security inputs and outputs
#

add_custom_target(tools)
set(TOOLS_DEFINITIONS "-DXSEC_BUILDING_TOOLS")

if (NOT WIN32)
  set(TOOLS_DEFINITIONS "${TOOLS_DEFINITIONS} -DHAVE_STRCASECMP -DHAVE_UNISTD_H")
endif()

# xtest

set(xsec_xtest_SOURCES
    xsec/tools/xtest/xtest.cpp)
add_executable(xtest EXCLUDE_FROM_ALL ${xsec_xtest_SOURCES})
target_compile_definitions(xtest PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(xtest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(xtest xml-security-c)
add_dependencies(tools xtest)

# c14n
set(xsec_c14n_SOURCES
   xsec/tools/c14n/c14n.cpp)
add_executable(c14n EXCLUDE_FROM_ALL ${xsec_c14n_SOURCES})
target_compile_definitions(c14n PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(c14n PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(c14n xml-security-c)
add_dependencies(tools c14n)

# checksig
set(xsec_checksig_SOURCES
    xsec/tools/checksig/checksig.cpp
    xsec/tools/checksig/AnonymousResolver.hpp
    xsec/tools/checksig/AnonymousResolver.cpp
    xsec/tools/checksig/InteropResolver.hpp
    xsec/tools/checksig/InteropResolver.cpp)
add_executable(checksig EXCLUDE_FROM_ALL ${xsec_checksig_SOURCES})
target_compile_definitions(checksig PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(checksig PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(checksig xml-security-c)
add_dependencies(tools checksig)

# templatesign
set(xsec_templatesign_SOURCES
    xsec/tools/templatesign/templatesign.cpp)
add_executable(templatesign EXCLUDE_FROM_ALL ${xsec_templatesign_SOURCES})
target_compile_definitions(templatesign PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(templatesign PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(templatesign xml-security-c)
add_dependencies(tools templatesign)

# txfmout
set(xsec_txfmout_SOURCES
    xsec/tools/txfmout/txfmout.cpp)
add_executable(txfmout EXCLUDE_FROM_ALL ${xsec_txfmout_SOURCES})
target_compile_definitions(txfmout PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(txfmout PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(txfmout xml-security-c)
add_dependencies(tools txfmout)

# siginf
set(xsec_siginf_SOURCES
    xsec/tools/siginf/siginf.cpp)
add_executable(siginf EXCLUDE_FROM_ALL ${xsec_siginf_SOURCES})
target_compile_definitions(siginf PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(siginf PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(siginf xml-security-c)
add_dependencies(tools siginf)

# cipher
set(xsec_cipher_SOURCES
    xsec/tools/cipher/cipher.cpp
    xsec/tools/cipher/XencInteropResolver.hpp
    xsec/tools/cipher/XencInteropResolver.cpp)
add_executable(cipher EXCLUDE_FROM_ALL ${xsec_cipher_SOURCES})
target_compile_definitions(cipher PUBLIC ${TOOLS_DEFINITIONS})
target_include_directories(cipher PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(cipher xml-security-c)
add_dependencies(tools cipher)

# xklient
# set(xsec_xklient_SOURCES
#     xsec/tools/xklient/xklient.cpp
#     enc/OpenSSL/OpenSSLSupport.hpp)
# add_executable(xklient EXCLUDE_FROM_ALL ${xsec_xklient_SOURCES})
# target_compile_definitions(xklient PUBLIC -DXSEC_BUILDING_TOOLS)
# target_link_libraries(xklient OpenSSL::Crypto)
# add_dependencies(tools xklient)

set(canoninclude_HEADERS
    xsec/canon/XSECXMLNSStack.hpp
    xsec/canon/XSECCanon.hpp
    xsec/canon/XSECC14n20010315.hpp)

set(encinclude_HEADERS
    xsec/enc/XSECCryptoKeyHMAC.hpp
    xsec/enc/XSECCryptoX509.hpp
    xsec/enc/XSECCryptoKeyDSA.hpp
    xsec/enc/XSECCryptoKeyEC.hpp
    xsec/enc/XSECKeyInfoResolver.hpp
    xsec/enc/XSECCryptoHash.hpp
    xsec/enc/XSECCryptoBase64.hpp
    xsec/enc/XSECCryptoSymmetricKey.hpp
    xsec/enc/XSECCryptoKey.hpp
    xsec/enc/XSECCryptoProvider.hpp
    xsec/enc/XSECKeyInfoResolverDefault.hpp
    xsec/enc/XSECCryptoKeyRSA.hpp
    xsec/enc/XSECCryptoException.hpp
    xsec/enc/XSECCryptoUtils.hpp)

set(xscryptinclude_HEADERS
    xsec/enc/XSCrypt/XSCryptCryptoBase64.hpp)

set(opensslinclude_HEADERS
    xsec/enc/OpenSSL/OpenSSLCryptoBase64.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoProvider.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoX509.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyHMAC.hpp
    xsec/enc/OpenSSL/OpenSSLCryptoHash.hpp
    xsec/enc/OpenSSL/OpenSSLSupport.hpp)

set(nssinclude_HEADERS
    xsec/enc/NSS/NSSCryptoX509.hpp
    xsec/enc/NSS/NSSCryptoHashHMAC.hpp
    xsec/enc/NSS/NSSCryptoKeyDSA.hpp
    xsec/enc/NSS/NSSCryptoKeyHMAC.hpp
    xsec/enc/NSS/NSSCryptoHash.hpp
    xsec/enc/NSS/NSSCryptoSymmetricKey.hpp
    xsec/enc/NSS/NSSCryptoProvider.hpp
    xsec/enc/NSS/NSSCryptoKeyRSA.hpp)

set(dsiginclude_HEADERS
    xsec/dsig/DSIGKeyInfoSPKIData.hpp
    xsec/dsig/DSIGXPathHere.hpp
    xsec/dsig/DSIGAlgorithmHandlerDefault.hpp
    xsec/dsig/DSIGXPathFilterExpr.hpp
    xsec/dsig/DSIGKeyInfoX509.hpp
    xsec/dsig/DSIGKeyInfoList.hpp
    xsec/dsig/DSIGKeyInfoValue.hpp
    xsec/dsig/DSIGKeyInfoDEREncoded.hpp
    xsec/dsig/DSIGTransformC14n.hpp
    xsec/dsig/DSIGTransformXSL.hpp
    xsec/dsig/DSIGKeyInfo.hpp
    xsec/dsig/DSIGKeyInfoPGPData.hpp
    xsec/dsig/DSIGKeyInfoExt.hpp
    xsec/dsig/DSIGObject.hpp
    xsec/dsig/DSIGTransformList.hpp
    xsec/dsig/DSIGTransform.hpp
    xsec/dsig/DSIGTransformBase64.hpp
    xsec/dsig/DSIGTransformXPath.hpp
    xsec/dsig/DSIGKeyInfoMgmtData.hpp
    xsec/dsig/DSIGSignedInfo.hpp
    xsec/dsig/DSIGTransformXPathFilter.hpp
    xsec/dsig/DSIGReferenceList.hpp
    xsec/dsig/DSIGReference.hpp
    xsec/dsig/DSIGSignature.hpp
    xsec/dsig/DSIGKeyInfoName.hpp
    xsec/dsig/DSIGTransformEnvelope.hpp
    xsec/dsig/DSIGConstants.hpp)

set(frameworkinclude_HEADERS
    xsec/framework/XSECAlgorithmHandler.hpp
    xsec/framework/XSECURIResolver.hpp
    xsec/framework/XSECDefs.hpp
    xsec/framework/XSECEnv.hpp
    xsec/framework/XSECException.hpp
    xsec/framework/XSECError.hpp
    xsec/framework/XSECProvider.hpp
    xsec/framework/XSECURIResolverXerces.hpp
    xsec/framework/XSECAlgorithmMapper.hpp
    xsec/framework/XSECW32Config.hpp
    xsec/framework/XSECVersion.hpp)

set(transformersinclude_HEADERS
    xsec/transformers/TXFMXPathFilter.hpp
    xsec/transformers/TXFMHash.hpp
    xsec/transformers/TXFMParser.hpp
    xsec/transformers/TXFMOutputFile.hpp
    xsec/transformers/TXFMURL.hpp
    xsec/transformers/TXFMBase.hpp
    xsec/transformers/TXFMChar.hpp
    xsec/transformers/TXFMCipher.hpp
    xsec/transformers/TXFMEnvelope.hpp
    xsec/transformers/TXFMChain.hpp
    xsec/transformers/TXFMDocObject.hpp
    xsec/transformers/TXFMConcatChains.hpp
    xsec/transformers/TXFMSB.hpp
    xsec/transformers/TXFMC14n.hpp
    xsec/transformers/TXFMXSL.hpp
    xsec/transformers/TXFMXPath.hpp
    xsec/transformers/TXFMBase64.hpp)

set(utilsinclude_HEADERS
    xsec/utils/XSECSafeBuffer.hpp
    xsec/utils/XSECSOAPRequestor.hpp
    xsec/utils/XSECTXFMInputSource.hpp
    xsec/utils/XSECNameSpaceExpander.hpp
    xsec/utils/XSECSOAPRequestorSimple.hpp
    xsec/utils/XSECXPathNodeList.hpp
    xsec/utils/XSECSafeBufferFormatter.hpp
    xsec/utils/XSECBinTXFMInputStream.hpp
    xsec/utils/XSECPlatformUtils.hpp)

set(xencinclude_HEADERS
    xsec/xenc/XENCEncryptionMethod.hpp
    xsec/xenc/XENCEncryptedType.hpp
    xsec/xenc/XENCCipherData.hpp
    xsec/xenc/XENCEncryptedKey.hpp
    xsec/xenc/XENCCipherValue.hpp
    xsec/xenc/XENCEncryptedData.hpp
    xsec/xenc/XENCCipherReference.hpp
    xsec/xenc/XENCCipher.hpp)

set(xkmsinclude_HEADERS
    xsec/xkms/XKMSNotBoundAuthentication.hpp
    xsec/xkms/XKMSValidateResult.hpp
    xsec/xkms/XKMSValidityInterval.hpp
    xsec/xkms/XKMSStatusRequest.hpp
    xsec/xkms/XKMSRegisterRequest.hpp
    xsec/xkms/XKMSPendingRequest.hpp
    xsec/xkms/XKMSCompoundRequest.hpp
    xsec/xkms/XKMSUseKeyWith.hpp
    xsec/xkms/XKMSValidateRequest.hpp
    xsec/xkms/XKMSUnverifiedKeyBinding.hpp
    xsec/xkms/XKMSLocateResult.hpp
    xsec/xkms/XKMSRespondWith.hpp
    xsec/xkms/XKMSQueryKeyBinding.hpp
    xsec/xkms/XKMSPrototypeKeyBinding.hpp
    xsec/xkms/XKMSKeyBindingAbstractType.hpp
    xsec/xkms/XKMSMessageAbstractType.hpp
    xsec/xkms/XKMSMessageFactory.hpp
    xsec/xkms/XKMSConstants.hpp
    xsec/xkms/XKMSRequestAbstractType.hpp
    xsec/xkms/XKMSResult.hpp
    xsec/xkms/XKMSAuthentication.hpp
    xsec/xkms/XKMSLocateRequest.hpp
    xsec/xkms/XKMSResultType.hpp
    xsec/xkms/XKMSStatusResult.hpp
    xsec/xkms/XKMSKeyBinding.hpp
    xsec/xkms/XKMSCompoundResult.hpp
    xsec/xkms/XKMSRegisterResult.hpp
    xsec/xkms/XKMSResponseMechanism.hpp
    xsec/xkms/XKMSStatus.hpp
    xsec/xkms/XKMSRevokeRequest.hpp
    xsec/xkms/XKMSRevokeResult.hpp
    xsec/xkms/XKMSRecoverKeyBinding.hpp
    xsec/xkms/XKMSRevokeKeyBinding.hpp
    xsec/xkms/XKMSRSAKeyPair.hpp
    xsec/xkms/XKMSRecoverResult.hpp
    xsec/xkms/XKMSReissueResult.hpp
    xsec/xkms/XKMSRecoverRequest.hpp
    xsec/xkms/XKMSReissueRequest.hpp
    xsec/xkms/XKMSReissueKeyBinding.hpp)

set(include_HEADERS
    ${xkmsinclude_HEADERS}
    ${xencinclude_HEADERS}
    ${utilsinclude_HEADERS}
    ${transformersinclude_HEADERS}
    ${frameworkinclude_HEADERS}
    ${dsiginclude_HEADERS}
    ${nssinclude_HEADERS}
    ${opensslinclude_HEADERS}
    ${xscryptinclude_HEADERS}
    ${encinclude_HEADERS}
    ${canoninclude_HEADERS}
    ${XENCAlgorithmHandlerDefault}
    ${XSECAlgorithmSupport})

# canon

set(canon_SOURCES
    xsec/canon/XSECC14n20010315.cpp
    xsec/canon/XSECXMLNSStack.cpp
    xsec/canon/XSECCanon.cpp)

# Signature

set(dsig_SOURCES
    xsec/dsig/DSIGKeyInfoPGPData.cpp
    xsec/dsig/DSIGReferenceList.cpp
    xsec/dsig/DSIGKeyInfoValue.cpp
    xsec/dsig/DSIGKeyInfoDEREncoded.cpp
    xsec/dsig/DSIGXPathHere.cpp
    xsec/dsig/DSIGAlgorithmHandlerDefault.cpp
    xsec/dsig/DSIGXPathFilterExpr.cpp
    xsec/dsig/DSIGKeyInfoMgmtData.cpp
    xsec/dsig/DSIGTransformXPathFilter.cpp
    xsec/dsig/DSIGSignedInfo.cpp
    xsec/dsig/DSIGKeyInfoList.cpp
    xsec/dsig/DSIGConstants.cpp
    xsec/dsig/DSIGSignature.cpp
    xsec/dsig/DSIGTransformXSL.cpp
    xsec/dsig/DSIGObject.cpp
    xsec/dsig/DSIGTransformXPath.cpp
    xsec/dsig/DSIGTransformEnvelope.cpp
    xsec/dsig/DSIGKeyInfoName.cpp
    xsec/dsig/DSIGTransformBase64.cpp
    xsec/dsig/DSIGReference.cpp
    xsec/dsig/DSIGKeyInfoSPKIData.cpp
    xsec/dsig/DSIGTransformList.cpp
    xsec/dsig/DSIGKeyInfoX509.cpp
    xsec/dsig/DSIGKeyInfoExt.cpp
    xsec/dsig/DSIGTransform.cpp
    xsec/dsig/DSIGTransformC14n.cpp)

# Main Crypto interface routines

set(enc_SOURCES
   xsec/enc/XSECCryptoX509.cpp
   xsec/enc/XSECKeyInfoResolverDefault.cpp
   xsec/enc/XSECCryptoUtils.cpp
   xsec/enc/XSECCryptoBase64.cpp
   xsec/enc/XSCrypt/XSCryptCryptoBase64.cpp
   xsec/enc/XSECCryptoException.cpp)

# Framework files

set(framework_SOURCES
    xsec/framework/XSECError.cpp
    xsec/framework/XSECAlgorithmMapper.cpp
    xsec/framework/XSECEnv.cpp
    xsec/framework/XSECProvider.cpp
    xsec/framework/XSECException.cpp
    xsec/framework/XSECURIResolverXerces.cpp)

set(txfm_SOURCES
    xsec/transformers/TXFMBase.cpp
    xsec/transformers/TXFMChain.cpp
    xsec/transformers/TXFMCipher.cpp
    xsec/transformers/TXFMParser.cpp
    xsec/transformers/TXFMSB.cpp
    xsec/transformers/TXFMEnvelope.cpp
    xsec/transformers/TXFMBase64.cpp
    xsec/transformers/TXFMXPathFilter.cpp
    xsec/transformers/TXFMHash.cpp
    xsec/transformers/TXFMC14n.cpp
    xsec/transformers/TXFMURL.cpp
    xsec/transformers/TXFMOutputFile.cpp
    xsec/transformers/TXFMXPath.cpp
    xsec/transformers/TXFMXSL.cpp
    xsec/transformers/TXFMDocObject.cpp
    xsec/transformers/TXFMConcatChains.cpp
    xsec/transformers/TXFMChar.cpp)

# Utility files.  Note we don't worry about checking if the UNIX stuff is
# necessary - we just assume that we are running on a *NIX system because
# compiling under make.  Cygwin compiles use the UNIX utilities, not windows

set(utils_SOURCES
    xsec/utils/XSECAlgorithmSupport.hpp
    xsec/utils/XSECAlgorithmSupport.cpp
    xsec/utils/XSECAutoPtr.hpp
    xsec/utils/XSECBinTXFMInputStream.cpp
    xsec/utils/XSECXPathNodeList.cpp
    xsec/utils/XSECSafeBuffer.cpp
    xsec/utils/XSECTXFMInputSource.cpp
    xsec/utils/XSECDOMUtils.hpp
    xsec/utils/XSECDOMUtils.cpp
    xsec/utils/XSECSafeBufferFormatter.cpp
    xsec/utils/XSECNameSpaceExpander.cpp
    xsec/utils/XSECPlatformUtils.cpp
    xsec/utils/XSECSOAPRequestorSimple.cpp)

if (WIN32)
  list(APPEND utils_SOURCES xsec/utils/winutils/XSECSOAPRequestorSimpleWin32.cpp)
else()
  list(APPEND utils_SOURCES xsec/utils/unixutils/XSECSOAPRequestorSimpleUnix.cpp)
endif()

# XML Encryption

set(xenc_SOURCES
    xsec/xenc/impl/XENCCipherReferenceImpl.cpp
    xsec/xenc/impl/XENCEncryptionMethodImpl.cpp
    xsec/xenc/impl/XENCEncryptedKeyImpl.hpp
    xsec/xenc/impl/XENCCipherValueImpl.cpp
    xsec/xenc/impl/XENCCipherImpl.hpp
    xsec/xenc/impl/XENCAlgorithmHandlerDefault.hpp
    xsec/xenc/impl/XENCCipherDataImpl.hpp
    xsec/xenc/impl/XENCEncryptionMethodImpl.hpp
    xsec/xenc/impl/XENCAlgorithmHandlerDefault.cpp
    xsec/xenc/impl/XENCEncryptedDataImpl.cpp
    xsec/xenc/impl/XENCEncryptedTypeImpl.hpp
    xsec/xenc/impl/XENCCipherDataImpl.cpp
    xsec/xenc/impl/XENCEncryptedDataImpl.hpp
    xsec/xenc/impl/XENCCipherValueImpl.hpp
    xsec/xenc/impl/XENCEncryptedTypeImpl.cpp
    xsec/xenc/impl/XENCCipherImpl.cpp
    xsec/xenc/impl/XENCEncryptedKeyImpl.cpp
    xsec/xenc/impl/XENCCipherReferenceImpl.hpp)

# XML Key Management
set(xkms_SOURCES
    xsec/xkms/XKMSConstants.cpp
    xsec/xkms/impl/XKMSCompoundRequestImpl.cpp
    xsec/xkms/impl/XKMSRevokeKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSRecoverRequestImpl.cpp
    xsec/xkms/impl/XKMSRegisterResultImpl.cpp
    xsec/xkms/impl/XKMSRecoverResultImpl.cpp
    xsec/xkms/impl/XKMSValidateResultImpl.hpp
    xsec/xkms/impl/XKMSRevokeResultImpl.hpp
    xsec/xkms/impl/XKMSCompoundResultImpl.cpp
    xsec/xkms/impl/XKMSRevokeKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSCompoundResultImpl.hpp
    xsec/xkms/impl/XKMSUnverifiedKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSKeyBindingAbstractTypeImpl.cpp
    xsec/xkms/impl/XKMSQueryKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSPrototypeKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSValidateResultImpl.cpp
    xsec/xkms/impl/XKMSRSAKeyPairImpl.hpp
    xsec/xkms/impl/XKMSAuthenticationImpl.cpp
    xsec/xkms/impl/XKMSNotBoundAuthenticationImpl.hpp
    xsec/xkms/impl/XKMSCompoundRequestImpl.hpp
    xsec/xkms/impl/XKMSPendingRequestImpl.hpp
    xsec/xkms/impl/XKMSStatusResultImpl.cpp
    xsec/xkms/impl/XKMSStatusImpl.hpp
    xsec/xkms/impl/XKMSRegisterRequestImpl.hpp
    xsec/xkms/impl/XKMSReissueRequestImpl.cpp
    xsec/xkms/impl/XKMSKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSUseKeyWithImpl.hpp
    xsec/xkms/impl/XKMSRequestAbstractTypeImpl.cpp
    xsec/xkms/impl/XKMSRespondWithImpl.cpp
    xsec/xkms/impl/XKMSResponseMechanismImpl.hpp
    xsec/xkms/impl/XKMSResultImpl.hpp
    xsec/xkms/impl/XKMSReissueResultImpl.cpp
    xsec/xkms/impl/XKMSAuthenticationImpl.hpp
    xsec/xkms/impl/XKMSMessageAbstractTypeImpl.cpp
    xsec/xkms/impl/XKMSRevokeResultImpl.cpp
    xsec/xkms/impl/XKMSStatusResultImpl.hpp
    xsec/xkms/impl/XKMSReissueKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSRespondWithImpl.hpp
    xsec/xkms/impl/XKMSRevokeRequestImpl.cpp
    xsec/xkms/impl/XKMSPendingRequestImpl.cpp
    xsec/xkms/impl/XKMSRecoverResultImpl.hpp
    xsec/xkms/impl/XKMSValidateRequestImpl.cpp
    xsec/xkms/impl/XKMSStatusRequestImpl.hpp
    xsec/xkms/impl/XKMSRecoverRequestImpl.hpp
    xsec/xkms/impl/XKMSRecoverKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSRSAKeyPairImpl.cpp
    xsec/xkms/impl/XKMSMessageAbstractTypeImpl.hpp
    xsec/xkms/impl/XKMSUnverifiedKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSValidityIntervalImpl.hpp
    xsec/xkms/impl/XKMSLocateResultImpl.hpp
    xsec/xkms/impl/XKMSLocateRequestImpl.cpp
    xsec/xkms/impl/XKMSResultTypeImpl.cpp
    xsec/xkms/impl/XKMSRecoverKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSResultImpl.cpp
    xsec/xkms/impl/XKMSValidityIntervalImpl.cpp
    xsec/xkms/impl/XKMSRegisterRequestImpl.cpp
    xsec/xkms/impl/XKMSReissueResultImpl.hpp
    xsec/xkms/impl/XKMSStatusImpl.cpp
    xsec/xkms/impl/XKMSReissueRequestImpl.hpp
    xsec/xkms/impl/XKMSStatusRequestImpl.cpp
    xsec/xkms/impl/XKMSReissueKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSValidateRequestImpl.hpp
    xsec/xkms/impl/XKMSKeyBindingAbstractTypeImpl.hpp
    xsec/xkms/impl/XKMSResultTypeImpl.hpp
    xsec/xkms/impl/XKMSMessageFactoryImpl.cpp
    xsec/xkms/impl/XKMSRevokeRequestImpl.hpp
    xsec/xkms/impl/XKMSResponseMechanismImpl.cpp
    xsec/xkms/impl/XKMSNotBoundAuthentication.cpp
    xsec/xkms/impl/XKMSLocateRequestImpl.hpp
    xsec/xkms/impl/XKMSLocateResultImpl.cpp
    xsec/xkms/impl/XKMSRequestAbstractTypeImpl.hpp
    xsec/xkms/impl/XKMSQueryKeyBindingImpl.cpp
    xsec/xkms/impl/XKMSUseKeyWithImpl.cpp
    xsec/xkms/impl/XKMSMessageFactoryImpl.hpp
    xsec/xkms/impl/XKMSPrototypeKeyBindingImpl.hpp
    xsec/xkms/impl/XKMSRegisterResultImpl.hpp)

# Conditional crypto routines

set(openssl_SOURCES
    xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoHash.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoProvider.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoX509.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoBase64.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.cpp
    xsec/enc/OpenSSL/OpenSSLCryptoKeyHMAC.cpp
    xsec/enc/OpenSSL/OpenSSLSupport.cpp)

set(nss_SOURCES
    xsec/enc/NSS/NSSCryptoX509.cpp
    xsec/enc/NSS/NSSCryptoHashHMAC.cpp
    xsec/enc/NSS/NSSCryptoHash.cpp
    xsec/enc/NSS/NSSCryptoKeyDSA.cpp
    xsec/enc/NSS/NSSCryptoProvider.cpp
    xsec/enc/NSS/NSSCryptoSymmetricKey.cpp
    xsec/enc/NSS/NSSCryptoKeyRSA.cpp
    xsec/enc/NSS/NSSCryptoKeyHMAC.cpp)

set(SOURCES
    ${canon_SOURCES}
    ${dsig_SOURCES}
    ${enc_SOURCES}
    ${framework_SOURCES}
    ${txfm_SOURCES}
    ${utils_SOURCES}
    ${xenc_SOURCES}
    ${xkms_SOURCES}
    ${openssl_SOURCES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/xsec/framework/XSECConfig.hpp.in
               ${CMAKE_CURRENT_BINARY_DIR}/xsec/framework/XSECConfig.hpp)

add_library(xml-security-c ${SOURCES})

target_include_directories(
  xml-security-c
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(xml-security-c PUBLIC XercesC::XercesC OpenSSL::Crypto)

if(USE_XALAN)
  target_link_libraries(xml-security-c PUBLIC XalanC::XalanC)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

if(WIN32)
  set(xmlsecurityc_config_dir "cmake")
else()
  set(xmlsecurityc_config_dir "${CMAKE_INSTALL_LIBDIR}/cmake/XmlSecurityC")
endif()

include(GNUInstallDirs)

install(
  TARGETS xml-security-c
  EXPORT XmlSecurityCConfigInternal
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT "runtime"
  INCLUDES
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(
  EXPORT XmlSecurityCConfigInternal
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

foreach(hdr IN LISTS include_HEADERS)
  get_filename_component(hdrdir ${hdr} DIRECTORY)
  install(
    FILES "${hdr}"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${hdrdir}"
    COMPONENT "development")
endforeach()

# Install configure data file xsec/framework/XSECConfig.hpp
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/xsec/framework/XSECConfig.hpp"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/xsec/framework"
  COMPONENT "development")

# Generate pkg-config file
set(pkgconfig-dir "${CMAKE_INSTALL_LIBDIR}/pkgconfig" CACHE STRING "pkg-config installation directory (default ${CMAKE_INSTALL_LIBDIR}/pkgconfig)")
set(PKGCONFIGDIR "${pkgconfig-dir}")

set(prefix "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix "${CMAKE_INSTALL_PREFIX}")
set(libdir "${CMAKE_INSTALL_FULL_LIBDIR}")
set(includedir "${CMAKE_INSTALL_FULL_INCLUDEDIR}")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/xml-security-c.pc.in
               ${CMAKE_CURRENT_BINARY_DIR}/xml-security-c.pc)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/xml-security-c.pc
  DESTINATION "${PKGCONFIGDIR}"
  COMPONENT "development")
