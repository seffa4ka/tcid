<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 *
 * Filds: form_height, form_width, form_bg.
 *
 * @return array
 *   System settings form.
 */
function new_status_form_config_form($form, &$form_state) {
  $form = array();

  $form['form_height'] = array(
    '#title' => t('Height window'),
    '#type' => 'radios',
    '#options' => array(160 => '160px', 200 => '200px', 400 => '400px'),
    '#default_value' => variable_get('form_height', 200),
  );

  $form['form_width'] = array(
    '#title' => t('Width window'),
    '#type' => 'radios',
    '#options' => array(200 => '200px', 500 => '500px', 800 => '800px'),
    '#default_value' => variable_get('form_width', 500),
  );

  $form['form_bg'] = array(
    '#title' => t('Color window'),
    '#type' => 'radios',
    '#options' => array(
      'darkgoldenrod' => 'darkgoldenrod',
      'burlywood' => 'burlywood',
      'coral' => 'coral',
    ),
    '#default_value' => variable_get('form_bg', 'burlywood'),
  );

  return system_settings_form($form);
}
