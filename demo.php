<?php
/*funtion __autoload($class) {
    include 'Address.'.$class.'.inc';
}
*/
function my_autoloader($class) {
    include 'Class.' . $class . '.inc';
}

spl_autoload_register('my_autoloader');

// Or, using an anonymous function as of PHP 5.3.0
spl_autoload_register(function ($class) {
    include 'Class.' . $class . '.inc';
});
echo '<h2>Instantiating Address</h2>';
$address = new AddressResidence;


echo '<h2>Setting properties...</h2>';
$address->street_address_1 = '555 Fake Street';
$address->city_name = 'Townsville';
$address->subdivision_name = 'State';
$address->country_name = 'United States of America';
echo $address;
echo '<tt><pre>'.var_export($address, TRUE).'</pre></tt>';


echo '<h2>Testing Address __ construct with an array</h2>';
$address_2 = new AddressBusiness(array(
    'street_address_1' =>'123 Phony Ave',
    'city_name' => 'Villageland',
    'subdivision_name' => 'Region',
    'country_name' => 'Canada',
));
echo $address_2;
echo '<tt><pre>'.var_export($address_2, TRUE).'</pre></tt>';

echo '<h2>loading data from the databse</h2>';
try{
    $address_db = Address::load(0);
    echo '<tt><pre>'.var_export($address_db, TRUE).'</pre></tt>';
}
catch (ExceptionAddress $e) {
    echo $e; 
}

?>