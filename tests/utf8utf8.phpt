--TEST--
Check if detectEncoding can detect doubly encoded UTF-8
--FILE--
<?php
use function CompactEncDet\detectEncoding;

function detect($input, $allowUtf8Utf8) {
  try {
    var_export(detectEncoding($input, $allowUtf8Utf8));
  } catch (Throwable $ex) {
    echo $ex;
  }
  echo "\n";
}

detect("Avenue des D\xc3\x83\xc2\xa9port\xc3\x83\xc2\xa9s  1", true);
detect("Avenue des D\xc3\x83\xc2\xa9port\xc3\x83\xc2\xa9s  1", false);
?>
--EXPECT--
'x-utf8utf8'
'UTF-8'
