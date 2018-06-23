<?php
/**
 * Physical address
 */
 class Address{
     public $streetName_1;
     public $streetName_2;
     public $subdivision_name = 'california';
     public $city_name;
     public $postal_code;
     public $country_name;

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

