<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 *
 * Filds: entity_discount_message.
 *
 * @return array
 *   System settings form.
 */
function entity_discount_config_form($form, &$form_state) {
  $form = array();

  $form['entity_discount_message'] = array(
    '#title' => t('Entity discount message'),
    '#description' => t('Input discount message. Usage [current-user:name] for display user name and [entity_discount:code] for display discount code.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('entity_discount_message', 'Hello, [current-user:name]! Your discount code is [entity_discount:code].'),
  );

  return system_settings_form($form);
}
