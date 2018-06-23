<?php
/**
 * Physical address
 */
 class Address{
     public $streetName_1;
     public $streetName_2;
     public $subdivision_name = 'california';
     public $city_name;
     protected $_postal_code;
     public $country_name;


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
            //set the value of posyal code
            if($name == 'postal_code') {
                $this->$name = $value;
                return;
            }

            //unable to access property should trigger an error
            trigger_error('Unable to access property via __set: '.$name);
            return NULL;
        }

     protected function _postal_code_guess() {
         return 'Lookup';
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
    }
    ?>

