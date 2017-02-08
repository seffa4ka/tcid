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
    '#description' => t('Input discount message. Usage [current-user:name] for display user name and [discount:code] for display discount code.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('discount_message', 'Hello, [current-user:name]! Your discount code is [discount:code].'),
  );

  return system_settings_form($form);
}
