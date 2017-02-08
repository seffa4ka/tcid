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
    '#markup' => token_replace(variable_get('discount_message', t('Hello!'))),
  );

  return $form;
}
