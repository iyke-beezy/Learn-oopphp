<?php
require 'Class.Address.inc';
require 'Class.Database.inc';
require 'Class.AddressResidence.inc';
require 'Class.AddressBusiness.inc';

echo '<h2>Instantiating Address</h2>';
$address = new AddressResidence;


echo '<h2>Setting properties...</h2>';
$address->streetName_1 = '555 Fake Street';
$address->city_name = 'Townsville';
$address->subdivision_name = 'State';
$address->country_name = 'United States of America';
echo $address;
echo '<tt><pre>'.var_export($address, TRUE).'</pre></tt>';


echo '<h2>Testing Address __ construct with an array</h2>';
$address_2 = new AddressBusiness(array(
    'streetName_1' =>'123 Phony Ave',
    'city_name' => 'Villageland',
    'subdivision_name' => 'Region',
    'country_name' => 'Canada',
));
echo $address_2;
echo '<tt><pre>'.var_export($address_2, TRUE).'</pre></tt>';

echo '<h2>loading data from the databse</h2>';
$address_db = Address::load(1);
echo '<tt><pre>'.var_export($address_db, TRUE).'</pre></tt>';

?>