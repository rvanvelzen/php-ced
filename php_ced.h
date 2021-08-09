#ifndef PHP_CED_H
#define PHP_CED_H

extern zend_module_entry ced_module_entry;
#define phpext_ced_ptr &ced_module_entry

extern zend_class_entry *php_ced_CompactEncDet_ce;

#define PHP_CED_VERSION "0.1.0"

#endif