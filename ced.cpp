#include "compact_enc_det/compact_enc_det.h"

extern bool FLAGS_ced_allow_utf8utf8;

extern "C" const char *ced_detect_encoding(const char *text, int text_length, bool allow_utf8utf8) {
    bool is_reliable;
    int bytes_consumed;

    FLAGS_ced_allow_utf8utf8 = allow_utf8utf8;

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

extern "C" const char *ced_version() {
    return CompactEncDet::Version();
}
