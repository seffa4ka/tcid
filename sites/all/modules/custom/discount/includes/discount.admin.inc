<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 *
 * Filds: discount_message.
 *
 * @return array
 *   System settings form.
 */
function discount_config_form($form, &$form_state) {
  $form = array();

  $form['discount_message'] = array(
    '#title' => t('Discount message'),
    '#description' => t('Input discount message.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('discount_message', 'Hello!'),
  );

  return system_settings_form($form);
}
