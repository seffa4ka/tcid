<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 */
function exchange_rates_config_form($form, &$form_state) {
  $form = array();

  $form['code'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency code'),
    '#required' => TRUE,
  );

  $form['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Rate'),
    '#element_validate' => array('element_validate_number'),
    '#required' => TRUE,
  );

  $form['timestamp'] = array(
    '#type' => 'date',
    '#title' => t('Date'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('exchange_rates_form_rate_submit'),
  );

  return $form;
}
