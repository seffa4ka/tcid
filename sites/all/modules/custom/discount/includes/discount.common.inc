<?php

/**
 * @file
 * Discount common file.
 */

/**
 * Function generation of the random string and record in the database.
 *
 * @global type $user
 */
function discount_generate_code() {

  global $user;

  $discount_value = array(
    'uid' => $user->uid,
    'discount'  => substr(uniqid(), 3),
  );
  drupal_write_record('discount_discount', $discount_value);
}
