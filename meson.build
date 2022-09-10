project('xml-security-c', ['cpp'],
    version: '2.0.4',
    license: 'Apache v2.0',
    default_options: [
        'default_library=static',
        'warning_level=1',
    ]
)

host_system = host_machine.system()
cxx = meson.get_compiler('cpp')

config_data = configuration_data()

if host_system == 'linux'
    add_project_arguments(['-D_FILE_OFFSET_BITS=64'], language: ['cpp'])
    config_data.set('FILE_OFFSET_BITS', 64)
elif host_system == 'windows'
    add_project_arguments([
        '-DWIN32',
        '-D_WINDOWS',
        '-D_USRDLL',
        '-DXSEC_HAVE_WINCAPI',
        ],
        language: ['cpp'],
    )
endif

if get_option('enable-debug').enabled()
    add_project_arguments(['-D_DEBUG'], language: ['cpp'])
    if host_system == 'windows'
        add_project_arguments(['-D_XSEC_DO_MEMDEBUG'], language: ['cpp'])
    endif
else
    if host_system == 'windows'
        add_project_arguments(['-D_CRT_SECURE_NO_DEPRECATE', '-DNDEBUG'], language: ['cpp'])
    endif
endif

# TODO: configure and generate xml-security-c.pc

dependency('threads')

if cxx.get_id() == 'gcc'
    add_project_arguments(['-Wall', '-W'], language: ['cpp'])
endif

config_data.set('HAVE_UNISTD_H', false)
if cxx.has_header('unistd.h')
    config_data.set('HAVE_UNISTD_H', 1)
endif

config_data.set('HAVE_DIRECT_H', false)
if cxx.has_header('direct.h')
    config_data.set('HAVE_DIRECT_H', 1)
endif

config_data.set('HAVE_STRCASECMP', false)
if cxx.has_function('strcasecmp')
    config_data.set('HAVE_STRCASECMP', 1)
endif

config_data.set('XSEC_HAVE_GETCWD_DYN', false)
code = '''
#include <stdlib.h>
#include <unistd.h>
int main() {
    char *cwd = getcwd(NULL, 0);
    return (cwd != NULL) ? EXIT_SUCCESS : EXIT_FAILURE;
}
'''
result = cxx.run(code, name: 'whether getcwd(NULL, 0) works')
if result.compiled() and result.returncode() == 0
    config_data.set('XSEC_HAVE_GETCWD_DYN', 1)
endif

xercesc_dep = dependency('xerces-c')

if get_option('with-xalan') != ''
    xalan_dep = dependency('xalan', dirs: [get_option('with-xalan')])
else
    xalan_dep = dependency('xalan', required: false)
endif

config_data.set('XSEC_HAVE_XALAN', false)
if xalan_dep.found()
    code = '''
    #include <xalanc/Include/XalanVersion.hpp>
    int main() {
        #if  _XALAN_VERSION >= 11100
        int i = 0;
        #else
        #error requires Xalan version 1.11+
        #endif
        return 0;
    }
    '''
    if cxx.compiles(code, name: 'Xalan version', dependencies: xalan_dep)
        config_data.set('XSEC_HAVE_XALAN', 1)
    else
        error('Xalan-C 1.11+ is required')
    endif
endif


if get_option('with-openssl') != ''
    openssl_dep = dependency('openssl', modules: 'libcrypto', dirs: [get_option('with-openssl')])
else
    openssl_dep = dependency('openssl', modules: 'libcrypto', required: false)
endif

config_data.set('XSEC_HAVE_OPENSSL', false)
config_data.set('XSEC_OPENSSL_CONST_BUFFERS', false)
config_data.set('XSEC_OPENSSL_HAVE_EVP_PKEY_ID', false)
config_data.set('XSEC_OPENSSL_HAVE_AES', false)
config_data.set('XSEC_OPENSSL_HAVE_GCM', false)
config_data.set('XSEC_OPENSSL_HAVE_MGF1', false)
config_data.set('XSEC_OPENSSL_HAVE_EC', false)
config_data.set('XSEC_OPENSSL_HAVE_SHA2', false)
config_data.set('XSEC_OPENSSL_CANSET_PADDING', false)
config_data.set('XSEC_OPENSSL_HAVE_CRYPTO_CLEANUP_ALL_EX_DATA', false)
config_data.set('XSEC_OPENSSL_D2IX509_CONST_BUFFER', false)
if openssl_dep.found()
    config_data.set('XSEC_HAVE_OPENSSL', 1)

    code = '''
    #include <openssl/rsa.h>
    int main() {
        const unsigned char * buf;
        unsigned char * outbuf;
        RSA rsa;
        RSA_private_decrypt(1,buf,outbuf,&rsa,RSA_PKCS1_PADDING);
        return 0;
    }
    '''
    if cxx.compiles(code, name: 'const input buffers in OpenSSL', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_CONST_BUFFERS', 1)
    endif

    if cxx.has_header_symbol('openssl/evp.h', 'EVP_PKEY_id', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_EVP_PKEY_ID', 1)
    endif

    code = '''
    #include <openssl/evp.h>
    int main() { EVP_aes_256_cbc(); return 0; }
    '''
    if cxx.links(code, name: 'non-broken AES support', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_AES', 1)
    endif

    code = '''
    #include <openssl/evp.h>
    int main() { EVP_aes_256_gcm(); return 0; }
    '''
    if cxx.links(code, name: 'GCM support', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_GCM', 1)
    endif

    if cxx.has_header_symbol('openssl/rsa.h', 'PKCS1_MGF1', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_MGF1', 1)
    endif

    if cxx.has_header_symbol('openssl/evp.h', 'EVP_PKEY_set1_EC_KEY', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_EC', 1)
    endif

    if cxx.has_header_symbol('openssl/evp.h', 'EVP_sha512', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_SHA2', 1)
    endif

    if cxx.has_header_symbol('openssl/evp.h', 'EVP_CIPHER_CTX_set_padding', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_CANSET_PADDING', 1)
    endif

    if cxx.has_header_symbol('openssl/crypto.h', 'CRYPTO_cleanup_all_ex_data', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_HAVE_CRYPTO_CLEANUP_ALL_EX_DATA', 1)
    endif

    code = '''
    #include <openssl/x509.h>
    int main() { const unsigned char * buf; d2i_X509(NULL, &buf, 1); return 0;}
    '''
    if cxx.compiles(code, name: 'const input buffer in loadX509Base64Bin', dependencies: openssl_dep)
        config_data.set('XSEC_OPENSSL_D2IX509_CONST_BUFFER', 1)
    endif
endif


if get_option('with-nss') != ''
    nss_dep = dependency('nss', dirs: [get_option('with-nss')])
else
    nss_dep = dependency('', required: false)
endif

config_data.set('XSEC_HAVE_NSS', false)
if nss_dep.found()
    nss_dep = dependency('nss', dirs: [get_option('with-nss')])
    config_data.set('XSEC_HAVE_NSS', 1)
    message('WARNING: NSS is no longer officially supported')
endif

config_data.set('XSEC_HAVE_WINCAPI', false)
if host_system == 'windows'
    config_data.set('XSEC_HAVE_WINCAPI', 1)
endif

config_data.set('XSEC_XKMS_ENABLED', false)
xsec_xkms_enabled = false
if get_option('xkms').enabled()
    config_data.set('XSEC_XKMS_ENABLED', 1)
    xsec_xkms_enabled = true
endif

configure_file(
    input: 'config.h.in',
    output: 'config.h',
    configuration: config_data)

subdir('xsec/framework')
subdir('xsec')
