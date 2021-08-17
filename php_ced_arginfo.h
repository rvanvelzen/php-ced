ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CompactEncDet_detectEncoding, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, allowUtf8Utf8, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(detectEncoding);

static const zend_function_entry ext_functions[] = {
	ZEND_NS_FE("CompactEncDet", detectEncoding, arginfo_CompactEncDet_detectEncoding)
	ZEND_FE_END
};
