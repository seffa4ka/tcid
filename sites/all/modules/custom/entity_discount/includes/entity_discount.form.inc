<?php

/**
 * Form function.
 *
 * Field: label.
 *
 * @return array
 *   Returns entity_discount message.
 */
function entity_discount_form($form, &$form_state) {
  $form = array();

  $form['label'] = array(
    '#markup' => token_replace(variable_get('entity_discount_message', t('Hello, [current-user:name]! Your discount code is [entity_discount:code].'))),
  );

  return $form;
}
