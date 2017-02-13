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

/**
 * Function outputs the code of the database.
 *
 * @global type $user
 */
function entity_discount_get_code() {

  global $user;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'entity_discount_entity');
  $query->propertyCondition('uid', $user->uid);
  $entity = $query->execute();
  
  if (isset($entity['entity_discount_entity'])) {
    $code = array_keys($entity['entity_discount_entity']);
    return $code[0];
  }
  else {
    return NULL;
  }
}