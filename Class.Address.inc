<?php
/**
 * Physical address
 */
 abstract class Address implements Model {
     const ADDRESS_TYPE_RESIDENCE = 1;
     const ADDRESS_TYPE_BUSINESS = 2;
     const ADDRESS_TYPE_PARK = 3;
    //address types
    static public $valid_address_types = array(
        Address::ADDRESS_TYPE_RESIDENCE => 'Residence',
        Address::ADDRESS_TYPE_BUSINESS => 'Business',
        Address::ADDRESS_TYPE_PARK => 'Park',
    );
     public $streetName_1;
     public $streetName_2;
     public $subdivision_name = 'california';
     public $city_name;
     protected $_postal_code;
     public $country_name;

     // Primary key of an address
     protected $_address_id;
     //When the record was created and time it was updated
     protected $_address_type_id;
     protected $_time_created;
     protected $_time_updated;

    function __construct($data = array()) {
        $this->_init();
        $this->_time_created = time();
        //ensure that the adress can be populated
        if(!is_array($data)) {
            trigger_error('unable to construct address with a ' .get_class($name));
        }
        //if there is at least one data in the array, populate the address with it
        if (count($data > 0)) {
            foreach ($data as $name => $value){
                //special case for protected properties.
                if(in_array($name, array (
                    'time_created',
                    'time_updated',
                    'address_id',
                    'address_type_id',                    
                ))) {
                    $name = '_'.$name;
                }
                $this->$name = $value;
            }
        }
    }

     function __get($name) {
         if(!$this->_postal_code) {
             $this->_postal_code = $this->_postal_code_guess();
         }

         //attempt to return a protected property name
         $protected_name_property = '_'.$name;
         if(property_exists($this, $protected_name_property)) {
             return $this->$protected_name_property;
         }
         //unability to find the property should trigger an error
         trigger_error('Undefined property via __get: '.$name);
         return NULL;
     }
     /**
      * Magic set
      *@param string name
      *@ param mixed value
      */

        function __set($name, $value) {
            //set the value of postal code
            if($name == 'postal_code') {
                $this->$name = $value;
                return;
            }

            //unable to access property should trigger an error
            trigger_error('Unable to access property via __set: '.$name);
            return NULL;
        }
        /**
         * Magic toString
         * @return string 
         */

        function __toString() {
            return $this->display();
        }

        abstract protected function _init();
     protected function _postal_code_guess() {
         $db = Database::getInstance();
         $mysqli = $db->getConnection();

         $sql = 'SELECT postal_code ';
         $sql .= 'FROM location ';
         $city_name = $mysqli->real_escape_string($this->city_name);
         $sql .= 'WHERE city_name = "'.$city_name.'" ';

         $subdivision_name = $mysqli->real_escape_string($this->subdivision_name);
         $sql .= 'AND subdivision_name = "'.$subdivision_name. '" ;';

         $result = $mysqli->query($sql);

         if($row = $result->fetch_assoc()) {
             return $row['postal_code'];
         }
     }
     
     function display() {
         $output = '';
         $output .= $this->streetName_1;
         if($this->streetName_2){
             $output .= '<br/>' . $this->streetName_2;
         }

         $output .= '<br/>';
         $output .= $this->city_name . ', '. $this->subdivision_name;
         $output .= ' ' . $this->postal_code;

         $output .= '<br/>';
         $output .= $this->country_name;

         return $output;
     }

     static public function isValidAddressTypeId($address_type_id) {
        return array_key_exists($address_type_id, self::$valid_address_types);
     }

     protected function _setAddressTypeId($address_type_id) {
         if(self::isValidAddressTypeId($address_type_id)) {
             $this->_address_type_id = $address_type_id;
         }
     }

    

     final public static function getInstance($address_type_id, $data = array()) {
         $class_name = 'Address'.self::valid_address_types[$address_type_id];
         return new $class_name($data);
     }
     
     final public static function load($address_id){
         $db = Database::getInstance();
         $mysqli = $db->connection();

         $sql_query = 'SELECT * ';
         $sql_query .= 'FROM address WHERE address_type_id = "'.(int) $address_id.'" ';
         $result = $mysqli->query($sql_query);
         if ($row = $result->fetch_assoc()) {
            return self::getInstance($row['address_type_id'],$row);
         }
     }
     final public function save() {}
    }
    ?>