<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 *
 */
function node_state_config_form($form, &$form_state) {
  $form = array();
  
  $form['label'] = array(
    '#markup' => t('Hello!'),
  );

  return system_settings_form($form);
}
