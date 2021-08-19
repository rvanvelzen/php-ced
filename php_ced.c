#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_ced.h"
#include "ced.h"

#if PHP_VERSION_ID >= 80000
# include "php_ced_arginfo.h"
#else
# include "php_ced_legacy_arginfo.h"
#endif

PHP_FUNCTION (detectEncoding) {
    char *input;
    size_t input_len;
    zend_bool allow_utf8utf8 = 0;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_STRING(input, input_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_BOOL(allow_utf8utf8)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len > INT_MAX) {
        input_len = INT_MAX;
    }

    RETURN_STRING(ced_detect_encoding(input, input_len, allow_utf8utf8));
}

PHP_MINFO_FUNCTION (ced) {
    php_info_print_table_start();
    php_info_print_table_header(2, "ced support", "enabled");
    php_info_print_table_row(2, "CED version", ced_version());
    php_info_print_table_end();
}

zend_module_entry ced_module_entry = {
    STANDARD_MODULE_HEADER,
    "ced",
    ext_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_MINFO(ced),
    PHP_CED_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CED
ZEND_GET_MODULE(ced)
#endif
