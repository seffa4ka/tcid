<?php

/**
 * Form function.
 *
 * Field: label.
 *
 * @return array
 *   Returns discount message.
 */
function discount_form($form, &$form_state) {
  $form = array();

  $form['label'] = array(
    '#markup' => variable_get('discount_message', t('First hello!')),
  );

  return $form;
}
