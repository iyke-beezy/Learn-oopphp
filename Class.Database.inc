<?php
/**
 * MYSQli database connection; only one connection is allowed
 */
class Database{
    private $_connection;
    //store single instance.
    private static $_instance;

    /**
     * Get an instance of the Database.
     * @return Database
     */

     public static function getInstance() {
         if(!self::$_instance) {
             self::$_instance = new self();
         }
         return self::$_instance;
     }

     public function __construct() {
         $this->_connection = new mysqli('localhost','root','','oopphp');
         //error handling
         if(mysqli_connect_error()) {
             trigger_error('Failed to connecct to MySQl: '.mysqli_connect_error(), E_USER_ERROR);
         }
     }

     private function __clone() {}

     public function getConnection() {
         return $this->_connection;
     }
}
