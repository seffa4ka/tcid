<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 */
function node_log_config_form($form, &$form_state) {
  $form = array();

  $form['log_latency'] = array(
    '#title' => t('Latency'),
    '#type' => 'radios',
    '#options' => array(60 => '1 min', 120 => '2 min', 300 => '5 min'),
    '#default_value' => variable_get('log_latency', 60),
  );

  return system_settings_form($form);
}
