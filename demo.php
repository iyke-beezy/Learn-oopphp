<?php
require 'Class.Address.inc';

echo '<h2>Instantiating Address</h2>';
$address = new Address;

echo '<h2>Empty Address</h2>';
echo '<tt><pre>'.var_export($address,TRUE).'</pre></tt>';

echo '<h2>Stting properties...</h2>';
$address->streetName_1 = '555 Fake Street';
$address->city_name = 'Townsville';
$address->subdivision_name = 'State';
$address->postal_code = '12345';
$address->country_name = 'United States of America';
echo '<tt><pre>'.var_export($address, TRUE).'</pre></tt>';

echo '<h2>DIsplaying address...</h2>';
echo $address->display();

?>