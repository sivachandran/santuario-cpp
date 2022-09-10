add_project_arguments('-DXSEC_BUILDING_LIBRARY', language: ['cpp'])

# 'Sources', 'are', 'build', 'up', 'using', 'a', 'find', 'command',:
#
# 'find', 'xsec/transformers/', -name '*.cpp' -exec 'echo', {} \\ ";" | 'sed', "s/xsec\//  '..',\/xsec\//g"

# 'canon',

canon_sources = [
    'canon/XSECC14n20010315.cpp',
    'canon/XSECXMLNSStack.cpp',
    'canon/XSECCanon.cpp',
]

# 'Signature',

dsig_sources = [
    'dsig/DSIGKeyInfoPGPData.cpp',
    'dsig/DSIGReferenceList.cpp',
    'dsig/DSIGKeyInfoValue.cpp',
    'dsig/DSIGKeyInfoDEREncoded.cpp',
    'dsig/DSIGXPathHere.cpp',
    'dsig/DSIGAlgorithmHandlerDefault.cpp',
    'dsig/DSIGXPathFilterExpr.cpp',
    'dsig/DSIGKeyInfoMgmtData.cpp',
    'dsig/DSIGTransformXPathFilter.cpp',
    'dsig/DSIGSignedInfo.cpp',
    'dsig/DSIGKeyInfoList.cpp',
    'dsig/DSIGConstants.cpp',
    'dsig/DSIGSignature.cpp',
    'dsig/DSIGTransformXSL.cpp',
    'dsig/DSIGObject.cpp',
    'dsig/DSIGTransformXPath.cpp',
    'dsig/DSIGTransformEnvelope.cpp',
    'dsig/DSIGKeyInfoName.cpp',
    'dsig/DSIGTransformBase64.cpp',
    'dsig/DSIGReference.cpp',
    'dsig/DSIGKeyInfoSPKIData.cpp',
    'dsig/DSIGTransformList.cpp',
    'dsig/DSIGKeyInfoX509.cpp',
    'dsig/DSIGKeyInfoExt.cpp',
    'dsig/DSIGTransform.cpp',
    'dsig/DSIGTransformC14n.cpp',
]

# 'Main', 'Crypto', 'interface', 'routines',

enc_sources = [
    'enc/XSECCryptoX509.cpp',
    'enc/XSECKeyInfoResolverDefault.cpp',
    'enc/XSECCryptoUtils.cpp',
    'enc/XSECCryptoBase64.cpp',
    'enc/XSCrypt/XSCryptCryptoBase64.cpp',
    'enc/XSECCryptoException.cpp',
]

# 'Framework', 'files',

framework_sources = [
    'framework/XSECError.cpp',
    'framework/XSECAlgorithmMapper.cpp',
    'framework/XSECEnv.cpp',
    'framework/XSECProvider.cpp',
    'framework/XSECException.cpp',
    'framework/XSECURIResolverXerces.cpp',
]

if host_system == 'windows'
    windows = import('windows')
    framework_sources += windows.compile_resources('framework/version.rc')
endif

txfm_sources = [
    'transformers/TXFMBase.cpp',
    'transformers/TXFMChain.cpp',
    'transformers/TXFMCipher.cpp',
    'transformers/TXFMParser.cpp',
    'transformers/TXFMSB.cpp',
    'transformers/TXFMEnvelope.cpp',
    'transformers/TXFMBase64.cpp',
    'transformers/TXFMXPathFilter.cpp',
    'transformers/TXFMHash.cpp',
    'transformers/TXFMC14n.cpp',
    'transformers/TXFMURL.cpp',
    'transformers/TXFMOutputFile.cpp',
    'transformers/TXFMXPath.cpp',
    'transformers/TXFMXSL.cpp',
    'transformers/TXFMDocObject.cpp',
    'transformers/TXFMConcatChains.cpp',
    'transformers/TXFMChar.cpp',
]

# 'Utility', 'files.',  'Note', 'we', 'don','t 'worry', 'about', 'checking',
# 'if', 'the', 'UNIX', 'stuff', 'is', 'necessary', - 'we', 'just', 'assume', 'that',
# 'we', 'are', 'running', 'on', 'a', *NIX 'system', 'because', 'compiling', 'under',
# 'make.',  'Cygwin', 'compiles', 'use', 'the', 'UNIX', 'utilities',, 'not', 'windows',

utils_sources = [
    'utils/XSECAlgorithmSupport.hpp',
    'utils/XSECAlgorithmSupport.cpp',
    'utils/XSECAutoPtr.hpp',
    'utils/XSECBinTXFMInputStream.cpp',
    'utils/XSECXPathNodeList.cpp',
    'utils/XSECSafeBuffer.cpp',
    'utils/XSECTXFMInputSource.cpp',
    'utils/XSECDOMUtils.hpp',
    'utils/XSECDOMUtils.cpp',
    'utils/XSECSafeBufferFormatter.cpp',
    'utils/XSECNameSpaceExpander.cpp',
    'utils/XSECPlatformUtils.cpp',
    'utils/XSECSOAPRequestorSimple.cpp',
]

if host_system == 'windows'
    utils_sources += 'utils/winutils/XSECSOAPRequestorSimpleWin32.cpp'
else
    utils_sources += 'utils/unixutils/XSECSOAPRequestorSimpleUnix.cpp'
endif

# 'XML', 'Encryption',

xenc_sources = [
    'xenc/impl/XENCCipherReferenceImpl.cpp',
    'xenc/impl/XENCEncryptionMethodImpl.cpp',
    'xenc/impl/XENCCipherValueImpl.cpp',
    'xenc/impl/XENCAlgorithmHandlerDefault.cpp',
    'xenc/impl/XENCEncryptedDataImpl.cpp',
    'xenc/impl/XENCCipherDataImpl.cpp',
    'xenc/impl/XENCEncryptedTypeImpl.cpp',
    'xenc/impl/XENCCipherImpl.cpp',
    'xenc/impl/XENCEncryptedKeyImpl.cpp',
]

# 'XML', 'Key', 'Management',
xkms_sources = [
    'xkms/XKMSConstants.cpp',
    'xkms/impl/XKMSCompoundRequestImpl.cpp',
    'xkms/impl/XKMSRecoverRequestImpl.cpp',
    'xkms/impl/XKMSRegisterResultImpl.cpp',
    'xkms/impl/XKMSRecoverResultImpl.cpp',
    'xkms/impl/XKMSCompoundResultImpl.cpp',
    'xkms/impl/XKMSRevokeKeyBindingImpl.cpp',
    'xkms/impl/XKMSKeyBindingAbstractTypeImpl.cpp',
    'xkms/impl/XKMSPrototypeKeyBindingImpl.cpp',
    'xkms/impl/XKMSValidateResultImpl.cpp',
    'xkms/impl/XKMSAuthenticationImpl.cpp',
    'xkms/impl/XKMSStatusResultImpl.cpp',
    'xkms/impl/XKMSReissueRequestImpl.cpp',
    'xkms/impl/XKMSKeyBindingImpl.cpp',
    'xkms/impl/XKMSRequestAbstractTypeImpl.cpp',
    'xkms/impl/XKMSRespondWithImpl.cpp',
    'xkms/impl/XKMSReissueResultImpl.cpp',
    'xkms/impl/XKMSMessageAbstractTypeImpl.cpp',
    'xkms/impl/XKMSRevokeResultImpl.cpp',
    'xkms/impl/XKMSRevokeRequestImpl.cpp',
    'xkms/impl/XKMSPendingRequestImpl.cpp',
    'xkms/impl/XKMSValidateRequestImpl.cpp',
    'xkms/impl/XKMSRecoverKeyBindingImpl.cpp',
    'xkms/impl/XKMSRSAKeyPairImpl.cpp',
    'xkms/impl/XKMSUnverifiedKeyBindingImpl.cpp',
    'xkms/impl/XKMSLocateRequestImpl.cpp',
    'xkms/impl/XKMSResultTypeImpl.cpp',
    'xkms/impl/XKMSResultImpl.cpp',
    'xkms/impl/XKMSValidityIntervalImpl.cpp',
    'xkms/impl/XKMSRegisterRequestImpl.cpp',
    'xkms/impl/XKMSStatusImpl.cpp',
    'xkms/impl/XKMSStatusRequestImpl.cpp',
    'xkms/impl/XKMSReissueKeyBindingImpl.cpp',
    'xkms/impl/XKMSMessageFactoryImpl.cpp',
    'xkms/impl/XKMSResponseMechanismImpl.cpp',
    'xkms/impl/XKMSNotBoundAuthentication.cpp',
    'xkms/impl/XKMSLocateResultImpl.cpp',
    'xkms/impl/XKMSQueryKeyBindingImpl.cpp',
    'xkms/impl/XKMSUseKeyWithImpl.cpp',
]

# 'Conditional', 'crypto', 'routines',

openssl_sources = [
    'enc/OpenSSL/OpenSSLCryptoHashHMAC.cpp',
    'enc/OpenSSL/OpenSSLCryptoKeyRSA.cpp',
    'enc/OpenSSL/OpenSSLCryptoHash.cpp',
    'enc/OpenSSL/OpenSSLCryptoProvider.cpp',
    'enc/OpenSSL/OpenSSLCryptoX509.cpp',
    'enc/OpenSSL/OpenSSLCryptoBase64.cpp',
    'enc/OpenSSL/OpenSSLCryptoKeyDSA.cpp',
    'enc/OpenSSL/OpenSSLCryptoKeyEC.cpp',
    'enc/OpenSSL/OpenSSLCryptoSymmetricKey.cpp',
    'enc/OpenSSL/OpenSSLCryptoKeyHMAC.cpp',
    'enc/OpenSSL/OpenSSLSupport.cpp',
]

nss_sources = [
    'enc/NSS/NSSCryptoX509.cpp',
    'enc/NSS/NSSCryptoHashHMAC.cpp',
    'enc/NSS/NSSCryptoHash.cpp',
    'enc/NSS/NSSCryptoKeyDSA.cpp',
    'enc/NSS/NSSCryptoProvider.cpp',
    'enc/NSS/NSSCryptoSymmetricKey.cpp',
    'enc/NSS/NSSCryptoKeyRSA.cpp',
    'enc/NSS/NSSCryptoKeyHMAC.cpp',
]

wincapi_sources = [
    'enc/WinCAPI/WinCAPICryptoHash.cpp',
    'enc/WinCAPI/WinCAPICryptoHashHMAC.cpp',
    'enc/WinCAPI/WinCAPICryptoKeyDSA.cpp',
    'enc/WinCAPI/WinCAPICryptoKeyHMAC.cpp',
    'enc/WinCAPI/WinCAPICryptoKeyRSA.cpp',
    'enc/WinCAPI/WinCAPICryptoProvider.cpp',
    'enc/WinCAPI/WinCAPICryptoSymmetricKey.cpp',
    'enc/WinCAPI/WinCAPICryptoX509.cpp',
]

libxmlsecurityc_sources = \
    canon_sources + \
    dsig_sources + \
    enc_sources + \
    framework_sources + \
    txfm_sources + \
    utils_sources + \
    xenc_sources + \
    xkms_sources + \
    openssl_sources + \
    nss_sources

if host_system == 'windows'
    libxmlsecurityc_sources += wincapi_sources
endif

libxmlsecurityc_deps = [xercesc_dep]

if host_system == 'windows'
    libxmlsecurityc_deps += cxx.find_library('crypt32')
elif openssl_dep.found()
    libxmlsecurityc_deps += openssl_dep
endif

if xalan_dep.found()
    libxmlsecurityc_deps += xalan_dep
endif

if nss_dep.found()
    libxmlsecurityc_deps += nss_dep
endif

incdirs = [
    '..',
]

libxmlsecurityc_lib = library('xml-security-c', libxmlsecurityc_sources,
    cpp_args: ['-DXSEC_BUILDING_LIBRARY'],
    dependencies: libxmlsecurityc_deps,
    include_directories: include_directories(incdirs),
)

libxmlsecurity_dep = declare_dependency(
    include_directories: include_directories('.'),
    dependencies: libxmlsecurityc_deps,
    link_with: libxmlsecurityc_lib,
)

meson.override_dependency('xml-security-c', libxmlsecurity_dep)

#
# The following are sample programs.  They are NOT installed
#

# HMAC sign
sample_deps = [libxmlsecurity_dep, xercesc_dep, xalan_dep, openssl_dep]

executable('xsec-simpleHMAC', [
        'samples/simpleHMAC.cpp',
        'samples/IOStreamOutputter.cpp',
        'samples/IOStreamOutputter.hpp',
    ],
    dependencies: sample_deps,
    include_directories: incdirs,
)

# HMAC validate

executable('xsec-simpleValidate', [
        'samples/simpleValidate.cpp',
        'samples/IOStreamOutputter.cpp',
        'samples/IOStreamOutputter.hpp',
    ],
    dependencies: sample_deps,
    include_directories: incdirs,
)

# Encrypt

executable('xsec-simpleEncrypt', [
        'samples/simpleEncrypt.cpp',
        'samples/IOStreamOutputter.cpp',
        'samples/IOStreamOutputter.hpp',
    ],
    dependencies: sample_deps,
    include_directories: incdirs,
)

# Encrypt

executable('xsec-simpleDecrypt', [
        'samples/simpleDecrypt.cpp',
        'samples/IOStreamOutputter.cpp',
        'samples/IOStreamOutputter.hpp',
    ],
    dependencies: sample_deps,
    include_directories: incdirs,
)

#
# Finally we compile the tools that can be used to manipulate
# XML Security inputs and outputs
#

tools_args = ['-DXSEC_BUILDING_TOOLS']
tools_deps = [libxmlsecurity_dep]

# xtest

executable('xsec-c14n', [
        'tools/c14n/c14n.cpp',
    ],
    cpp_args: tools_args,
    dependencies: tools_deps,
    include_directories: incdirs,
)

executable('xsec-checksig', [
        'tools/checksig/checksig.cpp',
        'tools/checksig/AnonymousResolver.hpp',
        'tools/checksig/AnonymousResolver.cpp',
        'tools/checksig/InteropResolver.hpp',
        'tools/checksig/InteropResolver.cpp',
    ],
    cpp_args: tools_args,
    dependencies: tools_deps,
    include_directories: incdirs,
)

executable('xsec-templatesign', [
        'tools/templatesign/templatesign.cpp',
    ],
    cpp_args: tools_args,
    dependencies: tools_deps,
    include_directories: incdirs,
)

executable('xsec-txfmout', [
        'tools/txfmout/txfmout.cpp',
    ],
    cpp_args: tools_args,
    dependencies: tools_deps,
    include_directories: incdirs,
)

executable('xsec-siginf', [
        'tools/siginf/siginf.cpp',
    ],
    cpp_args: tools_args,
    dependencies: tools_deps,
    include_directories: incdirs,
)

executable('xsec-cipher', [
        'tools/cipher/cipher.cpp',
        'tools/cipher/XencInteropResolver.hpp',
        'tools/cipher/XencInteropResolver.cpp',
    ],
    cpp_args: tools_args,
    dependencies: tools_deps,
    include_directories: incdirs,
)

if xsec_xkms_enabled
    executable('xsec-xklient', [
            'tools/xklient/xklient.cpp',
            'enc/OpenSSL/OpenSSLSupport.hpp',
        ],
        cpp_args: tools_args,
        dependencies: tools_deps,
        include_directories: incdirs,
    )
endif
