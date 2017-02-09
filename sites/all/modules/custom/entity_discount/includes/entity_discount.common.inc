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
function entity_discount_generate_code() {

  global $user;

  $discount_values = array(
    'uid' => $user->uid,
    'discount'  => substr(uniqid(), 3),
  );
  $entity = entity_create('entity_discount_entity', $discount_values);
  return entity_save('entity_discount_entity', $entity);
}

function entity_discount_get_code() {

  global $user;

  //$entity = entity_load('entity_discount_entity', array(), array('uid' => 'bf2df05732'));
  $entity = new EntityFieldQuery();
  $entity->entityCondition('entity_discount_entity', 'uid');
  if (isset($entity)) {
    dsm($entity);
    //return $entity;
  }
  else {
    return NULL;
  }
}