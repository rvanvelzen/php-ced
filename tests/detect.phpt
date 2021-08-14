--TEST--
Check if compact_enc_det returns expected values
--FILE--
<?php
use CompactEncDet\CompactEncDet;

function detect($input) {
  try {
    var_export(CompactEncDet::detectEncoding($input));
  } catch (Throwable $ex) {
    echo $ex;
  }
  echo "\n";
}

detect('');
detect('simple string');
detect('aloha… my friend‽');
detect("\xff\xfe<\x00?\x00x\x00m\x00l\x00 \x00v\x00");
?>
--EXPECT--
'ISO-8859-1'
'US-ASCII'
'UTF-8'
'UTF-16LE'
