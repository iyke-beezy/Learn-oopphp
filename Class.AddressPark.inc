<?php
/**
 * park residence
 */
class AddressPark extends Address {
    protected function _init() {
        $this->_setAddressTypeId(Address::ADDRESS_TYPE_PARK);
    }
}