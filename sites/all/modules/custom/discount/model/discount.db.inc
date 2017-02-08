<?php

/**
 * @file
 * Discount model file.
 */

/**
 * Function return discound code or NULL.
 *
 * @global type $user
 *
 * @return string
 *   Discound code or NULL.
 */
function discount_db_get_code() {

  global $user;

  $query = db_select('discount_discount', 'discount')
    ->fields('discount')
    ->condition('uid', $user->uid)
    ->execute()
    ->fetchField();

  return $query;
}
