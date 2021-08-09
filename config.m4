PHP_ARG_ENABLE([ced],
  [whether to enable ced support],
  [AS_HELP_STRING([--enable-ced],
    [Enable ced support])],
  [no])

if test "$PHP_CED" != "no"; then
  PHP_REQUIRE_CXX()

  PHP_ADD_INCLUDE(compact_enc_det)

  PHP_NEW_EXTENSION(ced, php_ced.cpp \
    compact_enc_det/compact_enc_det/compact_enc_det.cc \
    compact_enc_det/compact_enc_det/compact_enc_det_hint_code.cc \
    compact_enc_det/util/encodings/encodings.cc \
    compact_enc_det/util/languages/languages.cc, $ext_shared, , "-Wno-narrowing", cxx)
fi