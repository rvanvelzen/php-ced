#include "zend_portability.h"

BEGIN_EXTERN_C()

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_ced.h"
#include "php_ced_arginfo.h"
#include "zend_exceptions.h"

END_EXTERN_C()

#include "compact_enc_det/compact_enc_det.h"

const char *ced_detect_encoding(const char *text, int text_length) {
    bool is_reliable;
    int bytes_consumed;

    Encoding encoding = CompactEncDet::DetectEncoding(
        text,
        text_length,
        nullptr,
        nullptr,
        nullptr,
        UNKNOWN_ENCODING,
        UNKNOWN_LANGUAGE,
        CompactEncDet::QUERY_CORPUS,
        true,
        &bytes_consumed,
        &is_reliable
    );

    return MimeEncodingName(encoding);
}

zend_class_entry *php_ced_CompactEncDet_ce;

PHP_METHOD (CompactEncDet_CompactEncDet, __construct) {
    zend_throw_exception(nullptr, "An object of this type cannot be created with the new operator", 0);
}

PHP_METHOD (CompactEncDet_CompactEncDet, detectEncoding) {
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len > INT_MAX) {
        input_len = INT_MAX;
    }

    RETURN_STRING(ced_detect_encoding(input, input_len));
}

PHP_MINIT_FUNCTION (ced) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "CompactEncDet\\CompactEncDet", class_CompactEncDet_CompactEncDet_methods);

    php_ced_CompactEncDet_ce = zend_register_internal_class(&ce);

    return SUCCESS;
}

PHP_MINFO_FUNCTION (ced) {
    php_info_print_table_start();
    php_info_print_table_header(2, "ced support", "enabled");
    php_info_print_table_row(2, "CED version", CompactEncDet::Version());
    php_info_print_table_end();
}

zend_module_entry ced_module_entry = {
    STANDARD_MODULE_HEADER,
    "ced",
    nullptr,
    PHP_MINIT(ced),
    nullptr,
    nullptr,
    nullptr,
    PHP_MINFO(ced),
    PHP_CED_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CED
BEGIN_EXTERN_C()
ZEND_GET_MODULE(ced)
END_EXTERN_C()
#endif