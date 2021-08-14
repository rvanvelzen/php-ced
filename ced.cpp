#include "compact_enc_det/compact_enc_det.h"

extern "C" const char *ced_detect_encoding(const char *text, int text_length) {
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

extern "C" const char *ced_version() {
    return CompactEncDet::Version();
}
